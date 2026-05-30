#include "Mesh.h"

Mesh::Mesh(const std::vector<float> &verts)
{
	setMesh(verts);
}

void Mesh::setMesh(const std::vector<float> &verts)
{
	m_vertices = verts;
}

void Mesh::setMesh_move(const std::vector<float> &verts)
{
	std::move(verts.begin(), verts.end(), m_vertices.data());
}

void Mesh::bindVBO(VBO vbo)
{
	//explicitly bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices[0], GL_STATIC_DRAW);
}

void Mesh::renderMesh(int data_points)
{
	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size() / data_points);
}
