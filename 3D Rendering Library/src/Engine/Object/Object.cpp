#include "Object.h"

Object::Object(const Transform &transform, const Mesh &mesh, const Material &material)
{
	this->transform = transform;
	this->mesh = mesh;
	this->material = material;
}

void Object::setProjection(const glm::mat4 &projection)
{
  material.setProjection(projection);
}

void Object::draw(VAO vao, VBO vbo, const glm::mat4 &view, const Window *window)
{
  mesh.bindVBO(vbo);

  material.use(transform);
  material.setViewMatrix(view);

  glBindVertexArray(vao);

  glm::mat4 model = glm::mat4(1.0f);
  transform.transformModel(model);
  material.setModelTransform(model);

  mesh.renderMesh();
}
