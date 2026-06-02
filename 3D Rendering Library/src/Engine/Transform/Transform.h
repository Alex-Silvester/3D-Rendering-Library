#pragma once

#include "../../Dependencies.h"

class Transform
{
public:

	Transform(glm::vec3 pos = glm::vec3{ 0.f,0.f,0.f }, glm::vec3 scale = glm::vec3{1.f,1.f,1.f}, glm::vec3 rot = glm::vec3()) : position(pos), scale(scale), rotation(rot) {};

	void transformModel(glm::mat4 &model);

	Transform &Move(const glm::vec3 &move);
	Transform &Move(float x, float y, float z) { return Move({ x, y, z }); }

	Transform &Scale(const glm::vec3 &size);
	Transform &Scale(float x, float y, float z) { return Scale({ x, y, z }); }

	Transform &Rotate(const glm::vec3 &angle);
	Transform &Rotate(float x, float y, float z) { return Rotate({ x, y, z }); }

public:

	glm::vec3 position = glm::vec3();
	glm::vec3 scale = glm::vec3(1.f, 1.f, 1.f);
	glm::vec3 rotation = glm::vec3();

private:

};
