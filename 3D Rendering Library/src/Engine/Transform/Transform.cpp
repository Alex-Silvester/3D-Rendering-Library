#include "Transform.h"

void Transform::transformModel(glm::mat4 &model)
{
	model = glm::translate(model, position);

	//left
	model = glm::rotate(model, rotation.x, { 1,0,0 });
	//up
	model = glm::rotate(model, rotation.y, { 0,1,0 });
	//forward
	model = glm::rotate(model, rotation.z, { 0,0,1 });

	model = glm::scale(model, scale);

}

Transform &Transform::Move(const glm::vec3 &move)
{
	position += move;
	return *this;
}

Transform &Transform::Scale(const glm::vec3 &size)
{
	scale *= size;
	return *this;
}

Transform &Transform::Rotate(const glm::vec3 &angle)
{
	rotation += angle;
	return *this;
}
