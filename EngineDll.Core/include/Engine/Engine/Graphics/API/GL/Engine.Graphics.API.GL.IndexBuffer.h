
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/IndexBuffer.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS IndexBuffer : public Engine::Graphics::IndexBuffer
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL element array buffer.
		/// </summary>
		IndexBuffer() noexcept;

		/// <summary>
		/// Creates a new OpenGL element array buffer.
		/// </summary>
		/// <param name="pIndexData"></param>
		/// <param name="IndexCount"></param>
		IndexBuffer(const std::vector<uint32_t> &IndexData);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		IndexBuffer(const IndexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		IndexBuffer(IndexBuffer &&Other) noexcept;

		~IndexBuffer() override;

		/// <summary>
		/// Binds this element array <index> buffer as the current element array buffer.
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
		IndexBuffer &operator=(const IndexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		IndexBuffer &operator=(IndexBuffer &&Other) noexcept;

	private:
		uint32_t m_ID;
		uint32_t m_IndexCount;
	};
}
