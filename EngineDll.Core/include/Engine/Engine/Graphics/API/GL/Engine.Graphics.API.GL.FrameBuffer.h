
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/GL/KHRPlatform.h"
#include "Engine/Engine/Graphics/FrameBuffer.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS FrameBuffer : public Engine::Graphics::FrameBuffer
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL frame buffer.
		/// </summary>
		FrameBuffer() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		FrameBuffer(const FrameBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		FrameBuffer(FrameBuffer &&Other) noexcept;

		~FrameBuffer() override;

		/// <summary>
		/// 
		/// </summary>
		void Bind() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetWidth() const override;

		/// <summar
		/// <returns></rey>
		/// 
		/// </summary>turns>
		uint32_t GetHeight() const override;

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
		FrameBuffer &operator=(const FrameBuffer &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		FrameBuffer &operator=(FrameBuffer &&Other) noexcept;

	private:
		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_ID;
	};
}
