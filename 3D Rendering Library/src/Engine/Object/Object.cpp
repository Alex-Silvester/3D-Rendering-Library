#include "Object.h"

Object::Object(const Transform &transform, const Mesh &new_mesh, const Material &material)
{
  this->transform = transform;
  this->meshes.push_back(std::make_shared<Mesh>(new_mesh));
  this->material = material;
}

Object::Object(const Transform &transform, const std::vector<std::shared_ptr<Mesh>> &new_meshes, const Material &material)
{
	this->transform = transform;

  for(int i = 0; i < new_meshes.size(); i++)
  {
    this->meshes.push_back(new_meshes[i]);
  }

	this->material = material;
}

void Object::setProjection(const glm::mat4 &projection)
{
  material.setProjection(projection);
}

void Object::draw(const glm::mat4 &view, const Window *window)
{
  for(auto& mesh : meshes)
  {
    mesh->bindVBO();

    material.use(transform);
    material.setViewMatrix(view);

    mesh->bindVAO();

    glm::mat4 model = glm::mat4(1.0f);
    transform.transformModel(model);
    material.setModelTransform(model);

    mesh->renderMesh();
  }

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}
