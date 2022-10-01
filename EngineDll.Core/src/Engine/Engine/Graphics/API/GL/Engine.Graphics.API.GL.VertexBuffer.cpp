
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.VertexBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::VertexBuffer::VertexBuffer() noexcept
{
}


/**
 * implementation
 */
API::GL::VertexBuffer::VertexBuffer(const std::vector<Vertex> &VertexData)
	: m_VertexCount(VertexData.size())
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_VertexCount, (const void *)&VertexData[0], GL_STATIC_DRAW);

	int offset = 0;
	int components = 3;

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, components, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offset * sizeof(float)));

	offset += components;
	components = 3;

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, components, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offset * sizeof(float)));

	offset += components;
	components = 2;

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, components, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *)(offset * sizeof(float)));
}


/**
 * implementation
 */
API::GL::VertexBuffer::VertexBuffer(const API::GL::VertexBuffer &Other)
{
}


/**
 * implementation
 */
API::GL::VertexBuffer::VertexBuffer(API::GL::VertexBuffer &&Other) noexcept
	: m_ID(0), m_VertexCount(0)
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_VertexCount, m_VertexCount);
}


/**
 * implementation
 */
API::GL::VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


/**
 * implementation
 */
void API::GL::VertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}


/**
 * implementation
 */
uint32_t API::GL::VertexBuffer::GetBufferElementCount() const
{
	return m_VertexCount;
}


/**
 * implementation
 */
uint32_t API::GL::VertexBuffer::GetBufferSize() const
{
	return sizeof(Vertex) * m_VertexCount;
}


/**
 * implementation
 */
uint32_t API::GL::VertexBuffer::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::VertexBuffer &API::GL::VertexBuffer::operator=(const API::GL::VertexBuffer &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::VertexBuffer &API::GL::VertexBuffer::operator=(API::GL::VertexBuffer &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_VertexCount, m_VertexCount);

	return *this;
}
