#include "Game3D.h"

void Game3D::gameInit()
{
  skybox.initialiseFaces("Data/images/skybox");

  default_shader->init("Data/shaders/vertex/default.vert", "Data/shaders/fragment/default.frag");
  default_shader->setProjection(m_window->getProjection());

  test_object = &object_factory.create();
  test_object->material.colour.r = 0.f;
  //test_object->transform.Scale(0.05f,0.05f,0.05f);

  transparent_object = &object_factory.create();
  transparent_object->material.colour = Colour(1.f, 0.f, 0.f, 0.3f);
  transparent_object->transform.position = test_object->transform.position + glm::vec3(0, 0, 1);

  textured_object = &object_factory.create();
  textured_object->material.setTexture("Data/images/Croose.jpg");
  textured_object->transform.position += glm::vec3(-2.0f, 0, 0);

  model_mesh_test = &object_factory.create();
  const std::vector<float> mesh = test_model.create("Data/Models/FBX/Forklift.fbx").getVertices();
  model_mesh_test->mesh.setMesh(mesh);
  model_mesh_test->transform.Move(-5.f, -5.f, 0.f).Scale(0.01f, 0.01f, 0.01f);
}

void Game3D::update(float dt)
{
  debug_window.addText("FPS: %.f", 1.f / dt);
  debug_window.addText("Camera Pos: [%.4f, %.4f, %.4f]", m_camera.Position);

  test_object->transform.rotation += dt;

  light->position = m_window->getCurrentCamera().Position;

  default_shader->setVec3("lightPos", light->position);
  default_shader->setFloat("lightIntensity", light->intensity);
}

void Game3D::preRender()
{
  m_window->draw(skybox);
}

void Game3D::postRender()
{

}