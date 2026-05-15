#pragma once

#include "../../Dependencies.h"

class Transform
{
public:

	Transform(glm::vec3 pos = glm::vec3{ 0.f,0.f,0.f }, glm::vec3 scale = glm::vec3{1.f,1.f,1.f}, glm::vec3 rot = glm::vec3()) : position(pos), scale(scale), rotation(rot) {};

	void transformModel(glm::mat4 &model);

public:

	glm::vec3 position = glm::vec3();
	glm::vec3 scale = glm::vec3(1.f, 1.f, 1.f);
	glm::vec3 rotation = glm::vec3();

private:

};
