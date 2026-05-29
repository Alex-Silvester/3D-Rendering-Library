#pragma once

#include "../../../Dependencies.h"

struct LightSource
{
	std::shared_ptr<glm::vec3> position;
	float intensity = 1.0f;
};