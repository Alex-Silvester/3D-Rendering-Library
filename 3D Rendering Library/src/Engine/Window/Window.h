#pragma once

#include "../../Dependencies.h"

#include "../Camera/Camera.h"
#include "../Key/Key.h"
#include "../Object/Object.h"

#define DECORATE_WINDOW true

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

class Window
{
public:

	Window() = default;
	//Window(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	void clear(glm::vec4 colour = glm::vec4());

	void display();
	
	void pollEvents();
	void processInputs();

	float getDeltaTime();

	bool isOpen();

	[[nodiscard]] GLFWwindow* glfwWindow();

	void changeCamera(const Camera &camera);

	void draw(Object &object);

	bool initialise(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

private:

	GLFWwindow *createWindow(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	GLFWwindow *makeWindow(float size_x = SCREEN_WIDTH, float size_y = SCREEN_HEIGHT, const char *name = "");

	static void mouse_callback(GLFWwindow *window, double xposIn, double yposIn);

	void mouseEvent(double xposIn, double yposIn) {}

	static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

	bool processInput();

	glm::mat4 getProjection(GLFWwindow *window, const Camera &camera);

private:

	GLFWwindow *m_window = nullptr;

	std::unique_ptr<Camera> m_camera;

	float m_last_frame = 0.f, m_delta_time = 0.f;

	VAO m_vao = 0;
	VBO m_vbo = 0;

};