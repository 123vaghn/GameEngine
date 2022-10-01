
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Texture.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::Texture::Texture()
{
}


/**
 * implementation
 */
API::GL::Texture::Texture(const API::GL::Texture &Other)
{
}


/**
 * implementation
 */
API::GL::Texture::Texture(API::GL::Texture &&Other) noexcept
	: m_ID{ 0 }
{
	std::swap(Other.m_ID, m_ID);
}


/**
 * implementation
 */
API::GL::Texture::~Texture()
{
}


/**
 * implementation
 */
void API::GL::Texture::Bind() const
{
}


/**
 * implementation
 */
uint32_t  API::GL::Texture::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::Texture &API::GL::Texture::operator=(const API::GL::Texture &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::Texture &API::GL::Texture::operator=(API::GL::Texture &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);

	return *this;
}
