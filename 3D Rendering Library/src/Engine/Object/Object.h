#pragma once

#include "../../Dependencies.h"

#include "../Transform/Transform.h"
#include "../Mesh/Mesh.h"
#include "../Material/Material.h"
#include "../Light/Light.h"

#include "../Model/Model.h"

class Window;

enum DrawMode
{
	VERTEX = 0,
	EDGE
};

class Object
{
public:

	Object() = default;
	Object(const Transform &transform, const Mesh &new_mesh, const Material &material);
	Object(const Transform &transform, const std::vector<std::shared_ptr<Mesh>> &new_meshes, const Material &material);

	DrawMode m_draw_mode = DrawMode::VERTEX;

	void setProjection(const glm::mat4 &projection);

private:

	friend class Window;

	virtual void draw(const glm::mat4 &view, const Window *window);

public:

	Transform transform = Transform();
	std::vector<std::shared_ptr<Mesh>> meshes = std::vector<std::shared_ptr<Mesh>>();
	Material material = Material();

	//std::shared_ptr<Light> light_ptr = std::make_shared<Light>();

	bool active = true;
};