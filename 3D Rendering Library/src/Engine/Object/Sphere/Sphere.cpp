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

	mesh = default_square;
}

void Sphere::passToShader()
{
	m_sphere_shader->setFloat("radius", radius);

	ImGui::SliderFloat(" ", &aa_flag, 0.f, 1.f, "%.3f", ImGuiSliderFlags_Logarithmic);

	m_sphere_shader->setFloat("aa_dist", aa_flag);
}
