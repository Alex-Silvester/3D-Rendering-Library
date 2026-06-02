#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::Mesh(const std::vector<float> &mesh)
{
	setMesh(mesh);
}

void Mesh::setMesh(const std::vector<float> &verts)
{
	m_vertices = verts;

	if (m_vbo == 0)
	{
		glGenVertexArrays(1, &m_vao);
		glGenBuffers(1, &m_vbo);

		glBindVertexArray(m_vao);

		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

		//position(3 floats), colour(4 floats), normal(3 floats), texture coordinate(2 floats)

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)0);
		glEnableVertexAttribArray(0);
		// colour attribute
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
		// normal attribute
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(7 * sizeof(float)));
		glEnableVertexAttribArray(2);
		// texture attribute
		glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, 12 * sizeof(float), (void *)(10 * sizeof(float)));
		glEnableVertexAttribArray(3);
	}
	else
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
	}

	glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), &m_vertices[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Mesh::setMesh_move(const std::vector<float> &verts)
{
	std::move(verts.begin(), verts.end(), m_vertices.data());
}

void Mesh::bindVBO()
{
	//explicitly bind the VBO
	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
}

void Mesh::bindVAO()
{
	glBindVertexArray(m_vao);
}

void Mesh::renderMesh(size_t data_points)
{
	glDrawArrays(GL_TRIANGLES, 0, m_vertices.size() / data_points);
}
