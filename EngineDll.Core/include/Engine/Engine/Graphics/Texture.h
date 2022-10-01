
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	class DLL_CLASS Texture
	{
	public:
		static Texture *Create();

	public:
		Texture();

		virtual ~Texture();

		virtual void Bind() const = 0;

		virtual uint32_t GetID() const = 0;
	};
}
