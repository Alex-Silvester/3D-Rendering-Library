#pragma once

#include "../../Dependencies.h"

//TODO: add rotations, potentially with quaternions

class Transform
{
public:

	Transform() = default;
	Transform(glm::vec3 pos, glm::vec3 scale) : m_position(pos), m_scale(scale) {};

	glm::vec3 m_position = glm::vec3();

	glm::vec3 m_scale = glm::vec3(1.f, 1.f, 1.f);

private:

};
