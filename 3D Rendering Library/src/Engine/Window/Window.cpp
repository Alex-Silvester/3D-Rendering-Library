#include "Window.h"

void Window::clear(glm::vec4 colour)
{
	glClearColor(colour.x, colour.y, colour.z, colour.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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

void Window::changeCamera(Camera &camera)
{
	m_camera = &camera;
}

Camera &Window::getCurrentCamera()
{
	return *m_camera;
}

void Window::draw(Object &object)
{
	object.setProjection(getProjection());
	object.draw(m_vao, m_vbo, m_camera->GetViewMatrix(), this);
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

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	// Set initial viewport
	glViewport(0, 0, (int)size_x, (int)size_y);

	glGenVertexArrays(1, &m_vao);
	glGenBuffers(1, &m_vbo);
	
	glBindVertexArray(m_vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	
	//position(3 floats), colour(4 floats), normal(3 floats), texture coordinate(2 floats)
	
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	// colour attribute
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	// normal attribute
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(7 * sizeof(float)));
	glEnableVertexAttribArray(2);
	// texture attribute
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(10 * sizeof(float)));
	glEnableVertexAttribArray(3);

	glEnable(GL_BLEND);
	glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

	return true;
}

GLFWwindow *Window::createWindow(float size_x, float size_y, const char *name)
{
	GLFWwindow *window = makeWindow(size_x, size_y, name);
	glfwSetInputMode(window, GLFW_CURSOR, CURSOR_MODE);
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

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		//return false;
	}

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

void Window::mouseEvent(double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (glfwGetInputMode(m_window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL)
	{
		last_x = xpos;
		last_y = ypos;
		return;
	}

	if (first_mouse)
	{
		last_x = xpos;
		last_y = ypos;
		first_mouse = false;
	}

	float xoffset = xpos - last_x;
	float yoffset = last_y - ypos; // reversed since y-coordinates go from bottom to top

	last_x = xpos;
	last_y = ypos;

	m_camera->ProcessMouseMovement(xoffset, yoffset);
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

bool Window::processInput()
{
  GLint polygonMode;
  glGetIntegerv(GL_POLYGON_MODE, &polygonMode);

  //close window
  if (Key<GLFW_KEY_ESCAPE>::pressed())
  {
    glfwSetWindowShouldClose(m_window, true);
  }

	if (Key<GLFW_KEY_TAB>::pressed())
	{
		if (glfwGetInputMode(m_window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL)
		{
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
		else
		{
			glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}
	}

	if (glfwGetInputMode(m_window, GLFW_CURSOR) == GLFW_CURSOR_NORMAL) return true;

	if (m_camera == nullptr)
	{
		std::cerr << "Camera not set\n";
		return false;
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
  else if (Key<GLFW_KEY_LEFT_CONTROL>::released())
  {
    m_camera->sprint_active = false;
  }

	return true;
}

const glm::mat4& Window::getProjection()
{
	if (m_camera == nullptr)
	{
		std::cerr << "Window Requires camera to get projection\n";
		return glm::mat4();
	}

	int size_x;
	int size_y;

	glfwGetWindowSize(m_window, &size_x, &size_y);

	m_projection = glm::perspective(
		glm::radians(m_camera->Zoom),
		(float)size_x / (float)size_y,
		0.1f,
		100.0f);
	
	return m_projection;
}

