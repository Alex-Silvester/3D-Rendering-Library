#include "../Object.h"

class Sphere : public Object
{
public:

	Sphere();

	void init();

private:

	void passToShader() override;

public:

	float radius = 1.f;
	float aa_flag = 0.f;

private:

	inline static std::shared_ptr<Shader> m_sphere_shader;

};