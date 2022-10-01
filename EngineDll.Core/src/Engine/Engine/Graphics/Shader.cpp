
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/Shader.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Shader.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Shader *Shader::Create(const char *const VertexShader, const char *const FragmentShader)
{
	switch (Graphics::GetAPI())
	{
	case GraphicsAPI::None:
		break;
	case GraphicsAPI::OpenGLCoreProfile: return new Graphics::API::GL::Shader(VertexShader, FragmentShader);
	default:
		return nullptr;
	}
}


/**
 * implementation
 */
Shader::Shader()
{
}


/**
 * implementation
 */
Shader::~Shader()
{
}
