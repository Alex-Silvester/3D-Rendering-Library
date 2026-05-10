#include "Object.h"

Object::Object(const Transform &transform, const Mesh &mesh, const Material &material)
{
	m_transform = transform;
	m_mesh = mesh;
	m_material = material;
}

void Object::draw(VAO vao, VBO vbo, const glm::mat4 &view, const Window *window)
{
  m_material.use(m_transform);

  glBindVertexArray(vao);

  m_mesh.bindVBO(vbo);

  m_material.transformModel();

  m_mesh.renderMesh();
}
