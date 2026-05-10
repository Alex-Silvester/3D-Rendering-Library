#pragma once

#include "../../Dependencies.h"

#include "../Key/Key.h"

using VAO = unsigned int;
using VBO = unsigned int;

const std::vector<float> default_square =
{
	/* position ------- colour --------- normal --- texture coords */
	 1.f, 1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
	-1.f, 1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
	-1.f,-1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
																								   
	-1.f,-1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
	 1.f,-1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
	 1.f, 1.f,0.f,  1.f,1.f,1.f,1.f,  0.f,1.f,0.f,    0.f,0.f,
};

class Mesh
{
public:

	Mesh() = default;
	Mesh(const std::vector<float> &verts);

	void setMesh(const std::vector<float> &verts);

	void setMesh_move(const std::vector<float> &verts);

	void bindVBO(VBO vbo);

private:

	std::vector<float> m_vertices = std::vector<float>();

};
