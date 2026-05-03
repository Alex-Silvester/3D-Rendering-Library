#include "Object.h"

Object::Object(const Transform &transform, const Mesh &mesh, const Material &material)
{
	m_transform = transform;
	m_mesh = mesh;
	m_material = material;
}

void Object::useMaterial()
{
	m_material.use(m_transform);
}
