
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/Texture2D.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Texture2D.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Texture2D *Texture2D::Create(int32_t Width, int32_t Height, int32_t Channels, const char *const FilePath)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::Texture2D(Width, Height, Channels, FilePath);
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
Texture2D::Texture2D()
{
}


/**
 * implementation
 */
Texture2D::~Texture2D()
{
}
