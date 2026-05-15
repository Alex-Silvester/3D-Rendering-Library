#pragma once

#include "Shader.h"
#include "Texture.h"
#include "../Transform/Transform.h"

class Material
{
public:

	Material() = default;
	Material(std::shared_ptr<Shader> &shader);

	bool use(const Transform &transform);
	void transformModel(const Transform &transform);
	void setViewMatrix(const glm::mat4 &view);
	void setProjection(const glm::mat4 &projection);

private:

public:

	Colour colour = Colour(1.f, 1.f, 1.f);
	std::shared_ptr<Shader> shader;
	std::shared_ptr<Texture> texture;

private:


};