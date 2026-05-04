#pragma once

#include "../../Dependencies.h"

#include <stb_image.h>

using TextureID = unsigned int;

class Texture
{
public:

	Texture() = default;

	bool setTexture(std::string path);
	void bindTexture();

private:

	TextureID m_texture_ID = 0;

};