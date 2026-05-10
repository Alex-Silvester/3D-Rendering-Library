#pragma once

#include "../../Dependencies.h"

#include "../Key/Key.h"

using VAO = unsigned int;
using VBO = unsigned int;

class Mesh
{
public:

	Mesh() = default;

	void setMesh(const std::vector<float> &verts);

	void bindVBO(VBO vbo);

private:

	std::vector<float> m_vertices = std::vector<float>();

};
