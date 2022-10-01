
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/IndexBuffer.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.IndexBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
IndexBuffer *IndexBuffer::Create(const std::vector<uint32_t> &IndexData)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::IndexBuffer(IndexData);
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
IndexBuffer::IndexBuffer()
{
}


/**
 * implementation
 */
IndexBuffer::~IndexBuffer()
{
}
