#pragma once

#include "../../Dependencies.h"

#include "../Camera/Camera.h"
#include "../Key/Key.h"
#include "../Object/Object.h"

#define DECORATE_WINDOW true

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#define CURSOR_MODE GLFW_CURSOR_DISABLED

class Window
{
public:

	Window() = default;

	void clear(glm::vec4 colour = glm::vec4());

	void display();
	
	void pollEvents();
	void processInputs();

	float getDeltaTime();

	bool isOpen();

	[[nodiscard]] GLFWwindow* glfwWindow();

	void changeCamera(Camera &camera);

	Camera &getCurrentCamera();

	void draw(Object &object);

	bool initialise(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	const glm::mat4& getProjection();

	float &nearPlane() { return m_near; }

	float &farPlane() { return m_far; }

private:

	GLFWwindow *createWindow(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	GLFWwindow *makeWindow(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	static void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

	void mouseEvent(double xposIn, double yposIn);

	static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

	bool processInput();

public:

	VAO m_vao = 0;
	VBO m_vbo = 0;

private:

	GLFWwindow *m_window = nullptr;

	Camera* m_camera = nullptr;

	float m_last_frame = 0.f, m_delta_time = 0.f;
	
	glm::mat4 m_projection = glm::mat4(1.0f);  // Cache the projection matrix

	float m_near = 0.1f, m_far = 100.f;

	bool first_mouse = true;
	float last_x, last_y;
};