
#include "pch.h"
#include "Engine/Core/DataTypes/Boolean.h"

using namespace Engine;


/**
 * implementation
 */
Boolean::Boolean() noexcept
{
}


/**
 * implementation
 */
Boolean::Boolean(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Boolean::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Boolean::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Boolean::operator T && () noexcept
{
	return std::move(m_Tv);
}
