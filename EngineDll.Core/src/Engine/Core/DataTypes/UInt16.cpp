
#include "pch.h"
#include "Engine/Core/DataTypes/UInt16.h"

using namespace Engine;


/**
 * implementation
 */
UInt16::UInt16() noexcept
{
}


/**
 * implementation
 */
UInt16::UInt16(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
UInt16::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt16::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt16::operator T &&() noexcept
{
	return std::move(m_Tv);
}
