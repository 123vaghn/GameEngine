
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.IndexBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::IndexBuffer::IndexBuffer() noexcept
{
}


/**
 * implementation
 */
API::GL::IndexBuffer::IndexBuffer(const std::vector<uint32_t> &IndexData)
	: m_IndexCount(IndexData.size())
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * m_IndexCount, (const void *)&IndexData[0], GL_STATIC_DRAW);
}


/**
 * implementation
 */
API::GL::IndexBuffer::IndexBuffer(const API::GL::IndexBuffer &Other)
{
}


/**
 * implementation
 */
API::GL::IndexBuffer::IndexBuffer(API::GL::IndexBuffer &&Other) noexcept
	: m_ID(0), m_IndexCount(0)
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_IndexCount, m_IndexCount);
}


/**
 * implementation
 */
API::GL::IndexBuffer::~IndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


/**
 * implementation
 */
void API::GL::IndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}


/**
 * implementation
 */
uint32_t API::GL::IndexBuffer::GetBufferElementCount() const
{
	return m_IndexCount;
}


/**
 * implementation
 */
uint32_t API::GL::IndexBuffer::GetBufferSize() const
{
	return sizeof(uint32_t) * m_IndexCount;
}


/**
 * implementation
 */
uint32_t API::GL::IndexBuffer::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::IndexBuffer &API::GL::IndexBuffer::operator=(const API::GL::IndexBuffer &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::IndexBuffer &API::GL::IndexBuffer::operator=(API::GL::IndexBuffer &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_IndexCount, m_IndexCount);

	return *this;
}
