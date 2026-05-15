#include "Material.h"

Material::Material(std::shared_ptr<Shader> &_shader)
{
	shader = _shader;
}

bool Material::use(const Transform &transform)
{
	if (shader.get() == nullptr)
	{
		std::cerr << "Material requires shader to use\n";
		return false;
	}

	shader->use();

	shader->setVec4("colour", colour.toVec4());

	//if the material has a texture, then use it
	if(texture.get() != nullptr)
		texture->bindTexture();

	return true;
}

void Material::setModelTransform(const glm::mat4 &model)
{
	shader->setMat4("model", model);
}

void Material::setViewMatrix(const glm::mat4 &view)
{
	shader->setMat4("view", view);
}

void Material::setProjection(const glm::mat4 &projection)
{
	shader->setMat4("projection", projection);
}