#pragma once

#include "Shader.h"
#include "Texture.h"
#include "../Transform/Transform.h"

class Material
{
public:

	Material();
	Material(std::shared_ptr<Shader> &shader);

	Material& operator=(const Material &mat);

	bool use(const Transform &transform);
	void setModelTransform(const glm::mat4 &transform);
	void setViewMatrix(const glm::mat4 &view);
	void setProjection(const glm::mat4 &projection);
	void setTexture(const std::string &path);

private:

public:

	Colour colour = Colour(1.f, 1.f, 1.f);
	std::shared_ptr<Shader> shader = nullptr;

private:

	std::shared_ptr<Texture> texture = nullptr;

};