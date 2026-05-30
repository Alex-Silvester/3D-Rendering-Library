#pragma once

#include "../../Dependencies.h"

#include "../Transform/Transform.h"
#include "../Mesh/Mesh.h"
#include "../Material/Material.h"

class Window;

class Object
{
public:

	Object() = default;
	Object(const Transform &transform, const Mesh &mesh, const Material &material);

	void setProjection(const glm::mat4 &projection);

private:

	friend class Window;

	virtual void draw(VAO vao, VBO vbo, const glm::mat4 &view, const Window *window);

public:

	Transform transform = Transform();
	Mesh mesh = Mesh();
	Material material = Material();

	bool active = true;
};