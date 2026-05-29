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
  test_sphere.init();
  test_sphere.move({ 0,0,-5 });

  test_light.init();
  test_light.move({ 0.f,3.f, 3.f });
  test_light.transform.scale = { 0.2f,0.2f,0.2f };
  test_light.source.intensity = 1.f;
  

  default_shader->init("Data/shaders/vertex/default.vert", "Data/shaders/fragment/default.frag");
  default_shader->setProjection(m_window->getProjection());

  test_object.mesh = default_square;
  test_object.material.shader = default_shader;

  test_object.material.colour.r = 0.f;

  test_object.move({ 4,0,-5 });

  test_light.source.intensity = 0.1f;
  test_object.light = &test_light.source;
  test_light.light = &test_light.source;
}

void Game::update(float dt)
{
  debug_window.addText("FPS: %.f", 1.f / dt);
	debug_window.addText("Camera Pos: [%.4f, %.4f, %.4f]", m_camera.Position.x, m_camera.Position.y, m_camera.Position.z);

  test_object.transform.rotation += dt;
}

void Game::render()
{
  m_window->draw(test_object);
  m_window->draw(test_sphere);
  m_window->draw(test_light);
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
