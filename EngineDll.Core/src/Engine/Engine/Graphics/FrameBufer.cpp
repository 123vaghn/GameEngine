
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/FrameBuffer.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.FrameBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
FrameBuffer *FrameBuffer::Create()
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::FrameBuffer();
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
FrameBuffer::FrameBuffer()
{
}


/**
 * implementation
 */
FrameBuffer::~FrameBuffer()
{
}
