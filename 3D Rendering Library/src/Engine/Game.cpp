#include "Game.h"
#include "Mesh/Mesh.h"

void Game::run()
{
  windowInit();
  gameInit();

  while (m_window->isOpen())
  {
    m_window->pollEvents();
    m_window->processInputs();

    debug_window.startFrame();

    update(m_window->getDeltaTime());

    m_window->clear();

    preRender();
    defaultRender();
    postRender();

    debug_window.renderFrame();

    m_window->display();
  }

  glDeleteVertexArrays(1, &m_window->m_vao);
  glDeleteBuffers(1, &m_window->m_vbo);

  glfwTerminate();
}

void Game::windowInit()
{
	m_window->initialise();
  m_window->changeCamera(m_camera);
	
	debug_window.init(*m_window);
  
  object_factory.addCopyObject(Object(Transform(), default_square, Material(default_shader)));
  object_factory.addObjectList(m_object_list);
	
  skybox.initialiseFaces("Data/images/skybox");

	addKeys();
}

void Game::gameInit()
{
  default_shader->init("Data/shaders/vertex/default.vert", "Data/shaders/fragment/default.frag");
  default_shader->setProjection(m_window->getProjection());

  test_object = &object_factory.create();
  test_object->material.colour.r = 0.f;

  transparent_object = &object_factory.create();
  transparent_object->material.colour = Colour(1.f, 0.f, 0.f, 0.3f);
  transparent_object->transform.position = test_object->transform.position + glm::vec3(0, 0, 1);

  textured_object = &object_factory.create();
  textured_object->material.setTexture("Data/images/Croose.jpg");
  textured_object->transform.position += glm::vec3(-2.0f, 0, 0 );

  test_model.create("Data/Models/FBX/Forklift.fbx");
}

void Game::update(float dt)
{
  debug_window.addText("FPS: %.f", 1.f / dt);
	debug_window.addText("Camera Pos: [%.4f, %.4f, %.4f]", m_camera.Position.x, m_camera.Position.y, m_camera.Position.z);

  test_object->transform.rotation += dt;
}

void Game::preRender()
{

}

void Game::defaultRender()
{
  m_window->draw(skybox);

  
  std::sort(m_object_list.begin(), m_object_list.end(),
            [this](std::unique_ptr<Object> &a, std::unique_ptr<Object> &b)
  {
    Camera &cam = m_window->getCurrentCamera();
    glm::vec3 &pos_a = a->transform.position;
    glm::vec3 &pos_b = b->transform.position;
  
    return glm::distance(cam.Position, pos_a) > glm::distance(cam.Position, pos_b);
  });

  for (std::unique_ptr<Object> &obj : m_object_list)
  {
    m_window->draw(*obj);
  }
}

void Game::postRender()
{

}

//This could be made more efficient with, maybe, preprocessor stuff
void Game::addKeys()
{
		Key<GLFW_KEY_ESCAPE      >::addWindow(m_window);
		Key<GLFW_KEY_W					 >::addWindow(m_window);
		Key<GLFW_KEY_S					 >::addWindow(m_window);
		Key<GLFW_KEY_A					 >::addWindow(m_window);
		Key<GLFW_KEY_D					 >::addWindow(m_window);
		Key<GLFW_KEY_SPACE			 >::addWindow(m_window);
		Key<GLFW_KEY_LEFT_SHIFT	 >::addWindow(m_window);
		Key<GLFW_KEY_LEFT_CONTROL>::addWindow(m_window);
    Key<GLFW_KEY_TAB         >::addWindow(m_window);
}
