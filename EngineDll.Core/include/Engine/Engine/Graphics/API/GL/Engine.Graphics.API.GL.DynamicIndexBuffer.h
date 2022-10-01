
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/GL/KHRPlatform.h"
#include "Engine/Engine/Graphics/DynamicIndexBuffer.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS DynamicIndexBuffer : public Engine::Graphics::DynamicIndexBuffer
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL element array buffer.
		/// </summary>
		DynamicIndexBuffer() noexcept;

		/// <summary>
		/// Creates a new OpenGL element array buffer.
		/// </summary>
		/// <param name="pIndexData"></param>
		/// <param name="IndexCount"></param>
		DynamicIndexBuffer(const std::vector<uint32_t> &IndexData);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		DynamicIndexBuffer(const DynamicIndexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		DynamicIndexBuffer(DynamicIndexBuffer &&Other) noexcept;

		~DynamicIndexBuffer() override;

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
		DynamicIndexBuffer &operator=(const DynamicIndexBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		DynamicIndexBuffer &operator=(DynamicIndexBuffer &&Other) noexcept;

	private:
		uint32_t m_ID;
		uint32_t m_IndexCount;
	};
}
