
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/DynamicIndexBuffer.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.DynamicIndexBuffer.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
DynamicIndexBuffer *DynamicIndexBuffer::Create(const std::vector<uint32_t> &IndexData)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::DynamicIndexBuffer(IndexData);
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
DynamicIndexBuffer::DynamicIndexBuffer()
{
}


/**
 * implementation
 */
DynamicIndexBuffer::~DynamicIndexBuffer()
{
}
