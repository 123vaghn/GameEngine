
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/GL/KHRPlatform.h"
#include "Engine/Engine/Graphics/DynamicVertexBuffer.h"
#include "Engine/Engine/Graphics/Vertex.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS DynamicVertexBuffer : public Engine::Graphics::DynamicVertexBuffer
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL array buffer.
		/// </summary>
		DynamicVertexBuffer() noexcept;

		/// <summary>
		/// Creates a new OpenGL array buffer.
		/// </summary>
		/// <param name="pVertexData"></param>
		/// <param name="VertexCount"></param>
		DynamicVertexBuffer(const std::vector<Vertex> &VertexData);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		DynamicVertexBuffer(const DynamicVertexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		DynamicVertexBuffer(DynamicVertexBuffer &&Other) noexcept;

		~DynamicVertexBuffer() override;

		/// <summary>
		/// Binds this array (vertex) buffer as the current array buffer.
		/// </summary>
		void Bind() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetBufferElementCount() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetBufferSize() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetID() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		DynamicVertexBuffer &operator=(const DynamicVertexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		DynamicVertexBuffer &operator=(DynamicVertexBuffer &&Other) noexcept;

	private:
		uint32_t m_ID;
		uint32_t m_VertexCount;
	};
}
