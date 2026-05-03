#pragma once

#include "../../Dependencies.h"

using TextureID = unsigned int;

class Texture
{
public:

	bool setTexture(std::string path);
	void bindTexture();

private:

	TextureID m_texture_ID = 0;

};