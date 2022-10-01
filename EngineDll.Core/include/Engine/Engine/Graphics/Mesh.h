#pragma once

#include "Engine/Engine/Graphics/DynamicIndexBuffer.h"
#include "Engine/Engine/Graphics/DynamicVertexBuffer.h"
#include "Engine/Engine/Graphics/Shader.h"

namespace Engine::Graphics
{
	class DLL_CLASS Mesh
	{
	public:
		Mesh();

		void AddVertices(const std::vector<Vertex> &VertexData);
		void Render(Shader *pShader);

	private:
		std::shared_ptr<DynamicIndexBuffer> m_IBO;
		std::shared_ptr<DynamicVertexBuffer> m_VBO;
		uint32_t m_VAO;
	};
}
