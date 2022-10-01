#include "pch.h"
#include "Engine/Engine/Graphics/Mesh.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Mesh::Mesh()
{
	glGenVertexArrays(1, &m_VAO);
}


/**
 * implementation
 */
void Mesh::AddVertices(const std::vector<Vertex> &VertexData)
{
	glBindVertexArray(m_VAO);

	m_VBO = std::unique_ptr<DynamicVertexBuffer>(DynamicVertexBuffer::Create(VertexData));
	m_IBO = std::unique_ptr<DynamicIndexBuffer>(DynamicIndexBuffer::Create(
			{
				0, 1, 3,
				1, 2, 3,
			}));
	glBindVertexArray(0);
}


/**
 * implementation
 */
void Mesh::Render(Shader *pShader)
{

}

