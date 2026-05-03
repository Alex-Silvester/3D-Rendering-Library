#include "Mesh.h"

void Mesh::setMesh(const std::vector<float> &verts)
{
	std::move(verts.begin(), verts.end(), m_vertices);
}
