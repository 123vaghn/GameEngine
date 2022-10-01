
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	class DLL_CLASS FrameBuffer
	{
	public:
		static FrameBuffer *Create();

	public:
		FrameBuffer();

		virtual ~FrameBuffer();

		virtual void Bind() const = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual uint32_t GetID() const = 0;
	};
}
