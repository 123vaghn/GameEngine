
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#pragma once

#include "Engine/Engine/Graphics/Vertex.h"
#include "Engine/Math/VectorF.h"

namespace Engine::Graphics
{
	class DLL_CLASS VertexBuffer
	{
	public:
		static VertexBuffer *Create(const std::vector<Vertex> &VertexData);

	public:
		VertexBuffer();

		virtual ~VertexBuffer();

		virtual void Bind() const = 0;

		virtual uint32_t GetBufferElementCount() const = 0;
		virtual uint32_t GetBufferSize() const = 0;
		virtual uint32_t GetID() const = 0;
	};
}
