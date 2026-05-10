#pragma once

#include "../../Dependencies.h"

//TODO: add rotations, potentially with quaternions

class Transform
{
public:

	Transform(glm::vec3 pos = glm::vec3{ 0.f,0.f,0.f }, glm::vec3 scale = glm::vec3{1.f,1.f,1.f}) : m_position(pos), m_scale(scale) {};

	glm::vec3 m_position = glm::vec3();

	glm::vec3 m_scale = glm::vec3(1.f, 1.f, 1.f);

private:

};
