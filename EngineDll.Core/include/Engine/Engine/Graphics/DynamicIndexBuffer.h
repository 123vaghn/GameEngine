
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	class DLL_CLASS DynamicIndexBuffer
	{
	public:
		static DynamicIndexBuffer *Create(const std::vector<uint32_t> &IndexData);

	public:
		DynamicIndexBuffer();

		virtual ~DynamicIndexBuffer();

		virtual void Bind() const = 0;

		virtual uint32_t GetBufferElementCount() const = 0;
		virtual uint32_t GetBufferSize() const = 0;
		virtual uint32_t GetID() const = 0;
	};
}
