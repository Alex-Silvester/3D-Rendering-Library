#pragma once

#include "Shader.h"
#include "Texture.h"
#include "../Transform/Transform.h"

class Material
{
public:

	Material() = default;

	bool use(const Transform &transform);
	void transformModel();

private:

public:

	Colour m_colour = Colour(1.f, 1.f, 1.f);

private:

	std::shared_ptr<Shader> m_shader_ptr;
	std::shared_ptr<Texture> m_texture_ptr;

};