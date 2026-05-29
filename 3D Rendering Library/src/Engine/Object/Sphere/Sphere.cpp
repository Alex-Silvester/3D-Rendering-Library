#include "Sphere.h"

Sphere::Sphere()
{

}

void Sphere::init()
{
	if (m_sphere_shader.get() == nullptr)
	{
		m_sphere_shader = std::make_shared<Shader>();
		m_sphere_shader->init("Data/shaders/vertex/billboard.vert", "Data/shaders/fragment/sphere.frag");
	}

	material.shader = m_sphere_shader;

	mesh = default_sphere;
}

void Sphere::passToShader()
{
	m_sphere_shader->setFloat("radius", radius);
	m_sphere_shader->setVec3("scale", transform.scale);
	m_sphere_shader->setFloat("aa_dist", aa_flag);
}
