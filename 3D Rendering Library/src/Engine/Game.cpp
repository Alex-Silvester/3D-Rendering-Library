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

  glfwTerminate();
}

void Game::windowInit()
{
	m_window->initialise();
  m_window->changeCamera(m_camera);
	
	debug_window.init(*m_window);
  
  object_factory.addCopyObject(Object(Transform(), default_square, Material(default_shader)));
  object_factory.addObjectList(m_object_list);

	addKeys();
}

void Game::defaultRender()
{
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
    Key<GLFW_KEY_F5          >::addWindow(m_window);
}
