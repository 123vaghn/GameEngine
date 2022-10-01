
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.Texture2D.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


/**
 * implementation
 */
API::GL::Texture2D::Texture2D() noexcept
{
}


/**
 * implementation
 */
API::GL::Texture2D::Texture2D(int32_t Width, int32_t Height, int32_t Channels, const char *const FilePath)
	: m_Width(Width), m_Height(Height), m_Channels(Channels)
{
	int32_t channels = 4;
	unsigned char *image = stbi_load(FilePath, &Width, &Height, &Channels, channels);
	
	glGenTextures(1, &m_ID);
	glBindTexture(GL_TEXTURE_2D, m_ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_Width, m_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)image);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glBindTexture(GL_TEXTURE_2D, 0);

	stbi_image_free(image);
}


/**
 * implementation
 */
API::GL::Texture2D::Texture2D(const API::GL::Texture2D &Other)
{
}


/**
 * implementation
 */
API::GL::Texture2D::Texture2D(API::GL::Texture2D &&Other) noexcept
	: m_ID(0), m_Width(0), m_Height(0)
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_Width, m_Width);
	std::swap(Other.m_Height, m_Height);
	std::swap(Other.m_Channels, m_Channels);
}


/**
 * implementation
 */
API::GL::Texture2D::~Texture2D()
{
}


/**
 * implementation
 */
void API::GL::Texture2D::Bind() const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_ID);
}


/**
 * implementation
 */
uint32_t API::GL::Texture2D::GetWidth() const
{
	return m_Width;
}


/**
 * implementation
 */
uint32_t API::GL::Texture2D::GetHeight() const
{
	return m_Height;
}


/**
 * implementation
 */
uint32_t API::GL::Texture2D::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::Texture2D &API::GL::Texture2D::operator=(const API::GL::Texture2D &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::Texture2D &API::GL::Texture2D::operator=(API::GL::Texture2D &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_Width, m_Width);
	std::swap(Other.m_Height, m_Height);
	std::swap(Other.m_Channels, m_Channels);

	return *this;
}
