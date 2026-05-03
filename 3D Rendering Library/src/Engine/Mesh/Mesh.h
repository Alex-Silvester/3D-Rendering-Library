#pragma once

#include "../../Dependencies.h"

class Mesh
{
public:

	Mesh() = default;

	void setMesh(const std::vector<float> &verts);

private:

	std::vector<float> m_vertices = std::vector<float>();

};
