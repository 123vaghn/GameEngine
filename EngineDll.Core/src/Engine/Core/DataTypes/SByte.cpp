
#include "pch.h"
#include "Engine/Core/DataTypes/SByte.h"

using namespace Engine;


/**
 * implementation
 */
SByte::SByte() noexcept
{
}


/**
 * implementation
 */
SByte::SByte(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
SByte::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
SByte::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
SByte::operator T &&() noexcept
{
	return std::move(m_Tv);
}
