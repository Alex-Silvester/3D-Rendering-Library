#pragma once

#include "../../Dependencies.h"

#include "../Key/Key.h"

using VAO = unsigned int;
using VBO = unsigned int; 

static const std::vector<float> default_square =
{
		1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   0.f, 0.f,
	 -1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   1.f, 0.f,
	 -1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   1.f, 1.f,
											 							   		  				 
	 -1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   1.f, 1.f,
	  1.f,-1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   0.f, 1.f,
	  1.f, 1.f, 0.f,   1.f, 1.f, 1.f, 1.f,   0.f, 1.f, 1.f,   0.f, 0.f,
};

class Mesh
{
public:

	Mesh();

	Mesh(const std::vector<float> &mesh);

	void operator=(const Mesh &mesh)
	{
		setMesh(mesh.m_vertices);
	}

	void operator=(const std::vector<float> &verts)
	{
		setMesh(verts);
	}

	void setMesh(const std::vector<float> &verts);

	void setMesh_move(const std::vector<float> &verts);

	void bindVBO();
	void bindVAO();

	void renderMesh(size_t data_points = 12);

private:

	std::vector<float> m_vertices = std::vector<float>();


	unsigned int m_vbo = 0, m_vao = 0;;
};
