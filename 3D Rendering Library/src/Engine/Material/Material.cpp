#include "Material.h"

bool Material::use(const Transform &transform)
{
	if (m_shader_ptr.get() == nullptr)
	{
		std::cerr << "Material requires shader to use\n";
		return false;
	}

	m_shader_ptr->use();

	m_shader_ptr->setVec3("Position", transform.m_position);
	m_shader_ptr->setVec3("Scale", transform.m_scale);

	//if the material has a texture, then use it
	if(m_texture_ptr.get() != nullptr)
		m_texture_ptr->bindTexture();

	return true;
}

void Material::transformModel()
{
	// calculate the model matrix for each object and pass it to shader before drawing
	glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
	model = glm::translate(model, glm::vec3(0.f));
	m_shader_ptr->setMat4("model", model);
}
