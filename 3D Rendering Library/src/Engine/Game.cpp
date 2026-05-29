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

    render();

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
	
	addKeys();
}

void Game::gameInit()
{
  default_shader->init("Data/shaders/vertex/default.vert", "Data/shaders/fragment/default.frag");
  default_shader->setProjection(m_window->getProjection());

  test_object.mesh = default_square;
  test_object.material.shader = default_shader;

  test_object.material.colour.r = 0.f;

  transparent_object.mesh = default_square;
  transparent_object.material.shader = default_shader;

  transparent_object.material.colour = Colour(1.f, 0.f, 0.f, 0.3f);
  transparent_object.transform.position = test_object.transform.position + glm::vec3(0, 0, 1);
}

void Game::update(float dt)
{
  debug_window.addText("FPS: %.f", 1.f / dt);
	debug_window.addText("Camera Pos: [%.4f, %.4f, %.4f]", m_camera.Position.x, m_camera.Position.y, m_camera.Position.z);

  test_object.transform.rotation += dt;
}

//Note: when rendering transparent objects, render them last from back to front to get the transparency to work properly
void Game::render()
{
  m_window->draw(test_object);
  m_window->draw(transparent_object);
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
