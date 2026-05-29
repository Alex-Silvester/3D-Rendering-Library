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

void Object::move(const glm::vec3 &dir)
{
  transform.position += dir;
}

void Object::draw(VAO vao, VBO vbo, const glm::mat4 &view, const Camera *camera, const Window *window)
{
  mesh.bindVBO(vbo);

  material.use(transform);

  if(light != nullptr)
  {
    material.shader->setVec3("light_pos", *light->position);
    material.shader->setFloat("light_intensity", light->intensity);
    material.shader->setVec3("obj_position", transform.position);
    material.shader->setVec3("camera_pos", camera->Position);
  }

  material.shader->setFloat("ambient_light", light == nullptr ? 1.0f : ambient_light_intensity);

  passToShader();
  material.setViewMatrix(view);

  glBindVertexArray(vao);

  glm::mat4 model = glm::mat4(1.0f);
  transform.transformModel(model);
  material.setModelTransform(model);

  mesh.renderMesh();
}

void Object::passToShader()
{}
