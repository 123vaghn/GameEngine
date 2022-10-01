
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Engine/Graphics/API/GL/Engine.Graphics.API.GL.DynamicVertexBuffer.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
API::GL::DynamicVertexBuffer::DynamicVertexBuffer() noexcept
{
}


/**
 * implementation
 */
API::GL::DynamicVertexBuffer::DynamicVertexBuffer(const std::vector<Vertex> &VertexData)
	: m_VertexCount(VertexData.size())
{
	glGenBuffers(1, &m_ID);
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * m_VertexCount, &VertexData[0], GL_DYNAMIC_DRAW);

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
API::GL::DynamicVertexBuffer::DynamicVertexBuffer(const API::GL::DynamicVertexBuffer &Other)
{
}


/**
 * implementation
 */
API::GL::DynamicVertexBuffer &API::GL::DynamicVertexBuffer::operator=(const API::GL::DynamicVertexBuffer &Other)
{
	return *this;
}


/**
 * implementation
 */
API::GL::DynamicVertexBuffer::~DynamicVertexBuffer()
{
	glDeleteBuffers(1, &m_ID);
}


/**
 * implementation
 */
void API::GL::DynamicVertexBuffer::Bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}


/**
 * implementation
 */
uint32_t API::GL::DynamicVertexBuffer::GetBufferElementCount() const
{
	return m_VertexCount;
}


/**
 * implementation
 */
uint32_t API::GL::DynamicVertexBuffer::GetBufferSize() const
{
	return sizeof(Vertex) * m_VertexCount;
}


/**
 * implementation
 */
uint32_t API::GL::DynamicVertexBuffer::GetID() const
{
	return m_ID;
}


/**
 * implementation
 */
API::GL::DynamicVertexBuffer::DynamicVertexBuffer(API::GL::DynamicVertexBuffer &&Other) noexcept
	: m_ID(0), m_VertexCount(0)
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_VertexCount, m_VertexCount);
}


/**
 * implementation
 */
API::GL::DynamicVertexBuffer &API::GL::DynamicVertexBuffer::operator=(API::GL::DynamicVertexBuffer &&Other) noexcept
{
	std::swap(Other.m_ID, m_ID);
	std::swap(Other.m_VertexCount, m_VertexCount);

	return *this;
}
