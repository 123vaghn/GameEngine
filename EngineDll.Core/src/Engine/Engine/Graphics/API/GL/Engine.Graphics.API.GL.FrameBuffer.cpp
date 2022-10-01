
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.FrameBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::FrameBuffer::FrameBuffer() noexcept
{
}


/**
 * implementation
 */
API::GL::FrameBuffer::FrameBuffer(const API::GL::FrameBuffer &Other)
{
}


/**
 * implementation
 */
API::GL::FrameBuffer::FrameBuffer(API::GL::FrameBuffer &&Other) noexcept
	: m_ID(0)
{
	std::swap(Other.m_ID, m_ID);
}


/**
 * implementation
 */
API::GL::FrameBuffer::~FrameBuffer()
{
	glDeleteProgram(m_ID);
}


/**
 * implementation
 */
void API::GL::FrameBuffer::Bind() const
{
}


/**
 * implementation
 */
uint32_t API::GL::FrameBuffer::GetWidth() const
{
	return m_Width;
}	


/**
 * implementation
 */
uint32_t API::GL::FrameBuffer::GetHeight() const
{
	return m_Height;
}


/**
 * implementation
 */
uint32_t API::GL::FrameBuffer::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::FrameBuffer &API::GL::FrameBuffer::operator=(const API::GL::FrameBuffer &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::FrameBuffer &API::GL::FrameBuffer::operator=(API::GL::FrameBuffer &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);

	return *this;
}
