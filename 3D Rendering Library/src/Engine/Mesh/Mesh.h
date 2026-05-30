#pragma once

#include "../../Dependencies.h"

#include "../Key/Key.h"

using VAO = unsigned int;
using VBO = unsigned int; 

static const std::vector<float> default_square =
{
		1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
	 -1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
	 -1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
											 							   		  	
	 -1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
	  1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
	  1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 0.f, 0.f,   0.f, 0.f,
};

class Mesh
{
public:

	Mesh() = default;
	Mesh(const std::vector<float> &verts);

	void operator=(const std::vector<float> &verts)
	{
		setMesh(verts);
	}

	void setMesh(const std::vector<float> &verts);

	void setMesh_move(const std::vector<float> &verts);

	void bindVBO(VBO vbo);

	void renderMesh(int data_points = 12);

private:

	std::vector<float> m_vertices = std::vector<float>();

};
