#include "Mesh.h"

void Mesh::setMesh(const std::vector<float> &verts)
{
	//std::move(verts.begin(), verts.end(), m_vertices);
}

void Mesh::bindVBO(VBO vbo)
{
	//explicitly bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices[0], GL_STATIC_DRAW);
}