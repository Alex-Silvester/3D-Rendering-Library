#pragma once

#include "../../Dependencies.h"

#include <stb_image.h>

using TextureID = unsigned int;

class Texture
{
public:

	Texture() = default;

	bool setTexture(const std::string &path);
	void bindTexture();

	int ID();

private:

	TextureID m_texture_ID;

};