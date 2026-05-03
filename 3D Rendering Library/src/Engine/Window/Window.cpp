#include "Window.h"

Window::Window(float size_x, float size_y, const char *name)
{
	if (!initialise(size_x, size_y, name))
	{
		std::cerr << "Failed to initialise Window";
	}
}

void Window::clear(glm::vec4 colour)
{
	glClearColor(colour.x, colour.y, colour.z, colour.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::draw()
{
}

void Window::display()
{
	glfwSwapBuffers(m_window);

	float currentFrame = static_cast<float>(glfwGetTime());
	m_delta_time = currentFrame - m_last_frame;
	m_last_frame = currentFrame;
}

void Window::pollEvents()
{
	glfwPollEvents();
}

void Window::processInputs()
{
	processInput();
}

float Window::getDeltaTime()
{
	return m_delta_time;
}

bool Window::isOpen()
{
	return !glfwWindowShouldClose(m_window);
}

GLFWwindow *Window::glfwWindow()
{
  return m_window;
}

bool Window::initialise(float size_x, float size_y, const char *name)
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	m_window = createWindow(size_x, size_y, name);
	glfwSetWindowUserPointer(m_window, reinterpret_cast<void *>(this));


	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return false;
	}

	return true;
}

GLFWwindow *Window::createWindow(float size_x, float size_y, const char *name)
{
	GLFWwindow *window = makeWindow(size_x, size_y, name);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	return window;
}

GLFWwindow *Window::makeWindow(float size_x, float size_y, const char *name)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_DECORATED, DECORATE_WINDOW);
	// glfw window creation
	// --------------------
	GLFWwindow *window = glfwCreateWindow((int)size_x, (int)size_y, name, NULL, NULL);
	if (window == NULL)
	{
		std::cout << ("Failed to create GLFW window") << std::endl;
		glfwTerminate();
		return nullptr;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	return window;
}

void Window::mouse_callback(GLFWwindow *window, double xposIn, double yposIn)
{
	Window *user_window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));

	if (user_window)
	{
		user_window->mouseEvent(xposIn, yposIn);
	}
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void Window::processInput()
{
  GLint polygonMode;
  glGetIntegerv(GL_POLYGON_MODE, &polygonMode);

  //close window
  if (Key<GLFW_KEY_ESCAPE>::pressed())
  {
    glfwSetWindowShouldClose(m_window, true);
  }

  //forward/backward movement
  if (Key<GLFW_KEY_W>::held())
  {
    m_camera->ProcessKeyboard(FORWARD, m_delta_time);
  }
  if (Key<GLFW_KEY_S>::held())
  {
    m_camera->ProcessKeyboard(BACKWARD, m_delta_time);
  }

  //left/right movement
  if (Key<GLFW_KEY_A>::held())
  {
    m_camera->ProcessKeyboard(LEFT, m_delta_time);
  }
  if (Key<GLFW_KEY_D>::held())
  {
    m_camera->ProcessKeyboard(RIGHT, m_delta_time);
  }

  //up/down movement
  if (Key<GLFW_KEY_SPACE>::held())
  {
    m_camera->ProcessKeyboard(UP, m_delta_time);
  }
  if (Key<GLFW_KEY_LEFT_SHIFT>::held())
  {
    m_camera->ProcessKeyboard(DOWN, m_delta_time);
  }

  //sprint
  if (Key<GLFW_KEY_LEFT_CONTROL>::held())
  {
    m_camera->sprint_active = true;
  }
  if (Key<GLFW_KEY_LEFT_CONTROL>::released())
  {
    m_camera->sprint_active = false;
  }

}

