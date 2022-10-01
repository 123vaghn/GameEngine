
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/DynamicVertexBuffer.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.DynamicVertexBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
DynamicVertexBuffer *DynamicVertexBuffer::Create(const std::vector<Vertex> &VertexData)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::DynamicVertexBuffer(VertexData);
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
DynamicVertexBuffer::DynamicVertexBuffer()
{
}


/**
 * implementation
 */
DynamicVertexBuffer::~DynamicVertexBuffer()
{
}
