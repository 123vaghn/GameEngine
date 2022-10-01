
#include "pch.h"
#include "Engine/Core/DataTypes/Int16.h"

using namespace Engine;


/**
 * implementation
 */
Int16::Int16() noexcept
{
}


/**
 * implementation
 */
Int16::Int16(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Int16::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int16::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int16::operator T &&() noexcept
{
	return std::move(m_Tv);
}

