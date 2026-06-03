#pragma once

#include "../../Dependencies.h"

#include "../Transform/Transform.h"
#include "../Mesh/Mesh.h"
#include "../Material/Material.h"
#include "../Light/Light.h"

class Window;

class Object
{
public:

	Object() = default;
	Object(const Transform &transform, const Mesh &mesh, const Material &material);

	void setProjection(const glm::mat4 &projection);

private:

	friend class Window;

	virtual void draw(const glm::mat4 &view, const Window *window);

public:

	Transform transform = Transform();
	Mesh mesh = Mesh();
	Material material = Material();

	//std::shared_ptr<Light> light_ptr = std::make_shared<Light>();

	bool active = true;
};