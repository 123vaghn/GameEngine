
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/Texture2D.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS Texture2D : public Engine::Graphics::Texture2D
	{
	public:
		/// <summary>
		/// Creates a new, uninitialized OpenGL 2D texture.
		/// </summary>
		Texture2D() noexcept;

		/// <summary>
		/// Creates a new OpenGL 2D texture.
		/// </summary>
		Texture2D(int32_t Width, int32_t Height, int32_t Channels, const char *const FilePath);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		Texture2D(const Texture2D &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Texture2D(Texture2D &&Other) noexcept;

		~Texture2D() override;

		/// <summary>
		/// 
		/// </summary>
		void Bind() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		uint32_t GetWidth() const override;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
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
		Texture2D &operator=(const Texture2D &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Texture2D &operator=(Texture2D &&Other) noexcept;

	private:
		uint32_t m_Width;
		uint32_t m_Height;
		uint32_t m_Channels;
		uint32_t m_ID;
	};
}
