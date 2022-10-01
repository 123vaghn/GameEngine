
#include "pch.h"
#include "Engine/Core/DataTypes/Int64.h"

using namespace Engine;


/**
 * implementation
 */
Int64::Int64() noexcept
{
}


/**
 * implementation
 */
Int64::Int64(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Int64::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int64::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int64::operator T &&() noexcept
{
	return std::move(m_Tv);
}
