#pragma once

#include "../Object/Object.h"
#include "../Utils/Utils.h"
#include "../Camera/Camera.h"

static std::vector<float> skybox_vertices = {         
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  1.f, 0.f,
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  1.f, 1.f,
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  1.f, 1.f,
     1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 1.f,
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
                          
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
                          
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
                          
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
                          
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f,  1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
                          
    -1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f, -1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
    -1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
     1.0f, -1.0f,  1.0f,  1.f, 1.f, 1.f, 1.f,  1.f, 1.f, 1.f,  0.f, 0.f,
};

class Skybox : public Object
{
public:
   
	void initialiseFaces(std::string path);

private:

  void draw(VAO vao, VBO vbo, const glm::mat4 &view, const Window *window) override;

private:

	GLuint m_textureID = 0;

  inline static std::shared_ptr<Shader> m_skybox_shader = nullptr;
};