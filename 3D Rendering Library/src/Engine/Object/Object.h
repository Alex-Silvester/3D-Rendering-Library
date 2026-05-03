#pragma once

#include "../../Dependencies.h"

#include "../Transform/Transform.h"
#include "../Mesh/Mesh.h"
#include "../Material/Material.h"

class Object
{
public:

	Object() = default;
	Object(const Transform &transform, const Mesh &mesh, const Material &material);

	void useMaterial();

public:

	Transform m_transform = Transform();

	bool active = true;

private:

	Mesh m_mesh = Mesh();

	Material m_material = Material();

};