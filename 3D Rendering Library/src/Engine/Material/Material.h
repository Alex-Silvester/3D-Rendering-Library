#pragma once

#include "Shader.h"
#include "Texture.h"

class Material
{
public:

	void use(/* Transform transform */ );

private:

public:

	Colour m_colour = Colour(1.f, 1.f, 1.f);

private:

	std::shared_ptr<Shader> m_shader_ptr = std::make_shared<Shader>(nullptr);
	std::shared_ptr<Texture> m_texture_ptr = std::make_shared<Texture>(nullptr);

};