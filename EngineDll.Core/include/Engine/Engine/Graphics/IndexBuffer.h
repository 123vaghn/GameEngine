
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	class DLL_CLASS IndexBuffer
	{
	public:
		static IndexBuffer *Create(const std::vector<uint32_t> &IndexData);

	public:
		IndexBuffer();

		virtual ~IndexBuffer();

		virtual void Bind() const = 0;
		
		virtual uint32_t GetBufferElementCount() const = 0;
		virtual uint32_t GetBufferSize() const = 0;
		virtual uint32_t GetID() const = 0;
	};
}
