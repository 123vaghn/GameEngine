
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/VertexBuffer.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.VertexBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
VertexBuffer *VertexBuffer::Create(const std::vector<Vertex> &VertexData)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::VertexBuffer(VertexData);
	default:
		return nullptr;
	}
}
 
 
/**
 * implementation
 */
VertexBuffer::VertexBuffer()
{
}


/**
 * implementation
 */
VertexBuffer::~VertexBuffer()
{
}
