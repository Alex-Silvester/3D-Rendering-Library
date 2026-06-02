#include "Skybox.h"

void Skybox::initialiseFaces(std::string path)
{
	std::vector<std::string> paths =
	{
		path + "/right.jpg",
		path + "/left.jpg",
		path + "/top.jpg",
		path + "/bottom.jpg",
		path + "/front.jpg",
		path + "/back.jpg"
	};

	m_textureID = Util::loadCubemap(paths);

	if (m_skybox_shader == nullptr)
	{
		m_skybox_shader = std::make_shared<Shader>();
		m_skybox_shader->init("Data/shaders/vertex/skybox.vert", "Data/shaders/fragment/skybox.frag");
	}

	transform = Transform();
	material = Material(m_skybox_shader);
	mesh = Mesh(skybox_vertices);
}

void Skybox::draw(VAO vao, VBO vbo, const glm::mat4 &view, const Window *window)
{
	GLint polygonMode;
	glGetIntegerv(GL_POLYGON_MODE, &polygonMode);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glDepthMask(GL_FALSE);

	mesh.bindVBO();

	material.use(transform);
	m_skybox_shader->setInt("skybox", 0);
	material.setViewMatrix(glm::mat4(glm::mat3(view)));

	mesh.bindVAO();

	glm::mat4 model = glm::mat4(1.0f);
	transform.transformModel(model);
	material.setModelTransform(model);

	mesh.renderMesh();

	glDepthMask(GL_TRUE);

	if (polygonMode == GL_FILL)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else if (polygonMode == GL_LINE)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}
