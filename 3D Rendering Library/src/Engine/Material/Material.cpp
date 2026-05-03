#include "Material.h"

bool Material::use(const Transform &transform)
{
	if (!m_shader_ptr)
	{
		std::cerr << "Material requires shader to use\n";
		return false;
	}

	m_shader_ptr->use();

	//TODO: Set position and scale here when shaders made

	//if the material has a texture, then use it
	if(m_texture_ptr)
		m_texture_ptr->bindTexture();
}
