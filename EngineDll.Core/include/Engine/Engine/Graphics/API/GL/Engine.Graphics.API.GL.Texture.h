
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/Texture.h"

namespace Engine::Graphics::API::GL
{
	class DLL_CLASS Texture : public Engine::Graphics::Texture
	{
	public:
		/// <summary>
		/// 
		/// </summary>
		Texture();

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		Texture(const Texture &Other);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Texture(Texture &&Other) noexcept;

		~Texture() override;

		/// <summary>
		/// 
		/// </summary>
		void Bind() const override;
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
		Texture &operator=(const Texture &Other);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Other"></param>
		/// <returns></returns>
		Texture &operator=(Texture &&Other) noexcept;

	private:
		uint32_t m_ID;
	};
}
