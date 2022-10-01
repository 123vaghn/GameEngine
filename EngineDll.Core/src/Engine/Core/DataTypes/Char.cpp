
#include "pch.h"
#include "Engine/Core/DataTypes/Char.h"

using namespace Engine;


/**
 * implementation
 */
unsigned int Char::ToAsciiString(const Char *const Source, SByte *Destination)
{
	return 0;
}


/**
 * implementation
 */
Char::Char() noexcept
{
}


/**
 * implementation
 */
Char::Char(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Char::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Char::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Char::operator T &&() noexcept
{
	return std::move(m_Tv);
}
