#include "Light.h"

Light::Light()
{
	source.position = std::make_shared<glm::vec3>(transform.position);
}
