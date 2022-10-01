
#include "pch.h"
#include "Engine/Core/DataTypes/UInt32.h"

using namespace Engine;


/**
 * implementation
 */
UInt32::UInt32() noexcept
{
}


/**
 * implementation
 */
UInt32::UInt32(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
UInt32::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt32::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt32::operator T &&() noexcept
{
	return std::move(m_Tv);
}

