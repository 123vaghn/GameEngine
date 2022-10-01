
#include "pch.h"
#include "Engine/Core/DataTypes/UInt64.h"

using namespace Engine;


/**
 * implementation
 */
UInt64::UInt64() noexcept
{
}


/**
 * implementation
 */
UInt64::UInt64(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
UInt64::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt64::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
UInt64::operator T && () noexcept
{
	return std::move(m_Tv);
}
