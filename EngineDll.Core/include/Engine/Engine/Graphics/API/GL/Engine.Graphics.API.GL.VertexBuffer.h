
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/VertexBuffer.h"
#include "Engine/Engine/Graphics/Vertex.h"

#define ENGINE_VERTEX_POSITION_ATTRIBUTE 0
#define ENGINE_VERTEX_TEXCOORD0_ATTRIBUTE 1
#define ENGINE_VERTEX_NORMAL_ATTRIBUTE 2

#define ENGINE_VERTEX_2DVECTOR_ATTRIBUTE_ELEMENTS 2
#define ENGINE_VERTEX_3DVECTOR_ATTRIBUTE_ELEMENTS 3

#define ENGINE_VERTEX_POSITION_ATTRIBUTE 0
#define ENGINE_VERTEX_TEXCOORD0_ATTRIBUTE 1
#define ENGINE_VERTEX_NORMAL_ATTRIBUTE 2

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS VertexBuffer : public Engine::Graphics::VertexBuffer
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL array buffer.
		/// </summary>
		VertexBuffer() noexcept;
		
		/// <summary>
		/// Creates a new OpenGL array buffer.
		/// </summary>
		/// <param name="pVertexData"></param>
		/// <param name="VertexCount"></param>
		VertexBuffer(const std::vector<Vertex> &VertexData);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		VertexBuffer(const VertexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		VertexBuffer(VertexBuffer &&Other) noexcept;

		~VertexBuffer() override;

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
		VertexBuffer &operator=(const VertexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		VertexBuffer &operator=(VertexBuffer &&Other) noexcept;

	private:
		uint32_t m_ID;
		uint32_t m_VertexCount;
	};
}
