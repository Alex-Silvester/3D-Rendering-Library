#include "Material.h"

Material::Material()
{
}

Material::Material(std::shared_ptr<Shader> &_shader)
{
	shader = _shader;
}

Material &Material::operator=(const Material &mat)
{
	this->shader = mat.shader;
	this->texture = std::make_shared<Texture>();
	this->colour = mat.colour;

	return *this;
}

bool Material::use(const Transform &transform)
{
	if (shader.get() == nullptr)
	{
		std::cerr << "Material requires shader to use\n";
		return false;
	}

	shader->use();

	shader->setVec4("colour", colour.toVec4());

	shader->setInt("hasTexture", 0);
	//if the material has a texture, then use it
	if (texture->ID() != 0)
	{
		shader->setInt("hasTexture", 1);
		texture->bindTexture();
	}

	return true;
}

void Material::setModelTransform(const glm::mat4 &model)
{
	shader->setMat4("model", model);
}

void Material::setViewMatrix(const glm::mat4 &view)
{
	shader->setMat4("view", view);
}

void Material::setProjection(const glm::mat4 &projection)
{
	shader->setMat4("projection", projection);
}

void Material::setTexture(const std::string &path)
{
	texture.reset();
	texture = std::make_shared<Texture>();
	texture->setTexture(path);
}
