
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.DynamicIndexBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::DynamicIndexBuffer::DynamicIndexBuffer() noexcept
{
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer::DynamicIndexBuffer(const std::vector<uint32_t> &IndexData)
	: m_IndexCount(IndexData.size())
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * m_IndexCount, &IndexData[0], GL_DYNAMIC_DRAW);
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer::DynamicIndexBuffer(const API::GL::DynamicIndexBuffer &Other)
{
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer &API::GL::DynamicIndexBuffer::operator=(const API::GL::DynamicIndexBuffer &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer::~DynamicIndexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


/**
 * implementation
 */
void API::GL::DynamicIndexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}


/**
 * implementation
 */
uint32_t API::GL::DynamicIndexBuffer::GetBufferElementCount() const
{
	return m_IndexCount;
}


/**
 * implementation
 */
uint32_t API::GL::DynamicIndexBuffer::GetBufferSize() const
{
	return sizeof(GLuint) * m_IndexCount;
}


/**
 * implementation
 */
uint32_t API::GL::DynamicIndexBuffer::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer::DynamicIndexBuffer(API::GL::DynamicIndexBuffer &&Other) noexcept
	: m_ID(0), m_IndexCount(0)
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_IndexCount, m_IndexCount);
}


/**
 * implementation
 */
API::GL::DynamicIndexBuffer &API::GL::DynamicIndexBuffer::operator=(API::GL::DynamicIndexBuffer &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_IndexCount, m_IndexCount);

	return *this;
}
