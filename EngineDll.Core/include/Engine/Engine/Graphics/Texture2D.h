
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	class DLL_CLASS Texture2D
	{
	public:
		static Texture2D *Create(int32_t Width, int32_t Height, int32_t Channels, const char *const FilePath);

	public:
		Texture2D();

		virtual ~Texture2D();

		virtual void Bind() const = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual uint32_t GetID() const = 0;
	};
}
