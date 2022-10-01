
#include "pch.h"
#include "Engine/Core/DataTypes/Byte.h"

using namespace Engine;


/**
 * implementation
 */
Byte::Byte() noexcept
{
}


/**
 * implementation
 */
Byte::Byte(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Byte::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Byte::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Byte::operator T &&() noexcept
{
	return std::move(m_Tv);
}
