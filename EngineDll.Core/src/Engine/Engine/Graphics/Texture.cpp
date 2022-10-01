
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/Texture.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Texture.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Texture *Texture::Create()
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Engine::Graphics::API::GL::Texture();
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
Texture::Texture()
{
}


/**
 * implementation
 */
Texture::~Texture()
{
}
