
#include "pch.h"
#include "Engine/Core/DataTypes/Int32.h"

using namespace Engine;


/**
 * implementation
 */
Int32::Int32() noexcept
{
}


/**
 * implementation
 */
Int32::Int32(T Value) noexcept
	: m_Tv(Value)
{
}


/**
 * implementation
 */
Int32::operator const T &() const noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int32::operator T &() noexcept
{
	return m_Tv;
}


/**
 * implementation
 */
Int32::operator T &&() noexcept
{
	return std::move(m_Tv);
}


//
///**
// * implementation
// */
//Int32::Int32() noexcept
//{
//}
//
//
///**
// * implementation
// */
//Int32::operator std::int32_t()
//{
//	return m_Data;
//}
//
//
///**
// * implementation
// */
//Int32::operator const std::int32_t() const
//{
//	return m_Data;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator+=(const Int32 &Rhs)
//{
//	m_Data += Rhs;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator-=(const Int32 &Rhs)
//{
//	m_Data -= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator*=(const Int32 &Rhs)
//{
//	m_Data *= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator/=(const Int32 &Rhs)
//{
//	m_Data /= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator&=(const Int32 &Rhs)
//{
//	m_Data &= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator|=(const Int32 &Rhs)
//{
//	m_Data |= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator%=(const Int32 &Rhs)
//{
//	m_Data %= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator^=(const Int32 &Rhs)
//{
//	m_Data ^= Rhs.m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32::Int32(std::int32_t Value) noexcept
//	: m_Data(Value)
//{
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator++()
//{
//	++m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 Int32::operator++(int)
//{
//	Int32 i = *this;
//	Int32::operator++();
//	
//	return i;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator--()
//{
//	--m_Data;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 Int32::operator--(int)
//{
//	Int32 i = *this;
//	Int32::operator--();
//
//	return i;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator=(std::int32_t Rhs)
//{
//	m_Data = Rhs;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator=(const std::int32_t &Rhs)
//{
//	m_Data = Rhs;
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//Int32 &Int32::operator=(std::int32_t &&Rhs) noexcept
//{
//	m_Data = std::move(Rhs);
//
//	return *this;
//}
//
//
///**
// * implementation
// */
//bool Int32::operator==(const Int32 &Rhs)
//{
//	return m_Data == Rhs.m_Data;
//}
//
//
///**
// * implementation
// */
//bool Int32::operator!=(const Int32 &Rhs)
//{
//	return !(*this == Rhs);
//}
//
//
///**
// * implementation
// */
//std::string Int32::ToString() const
//{
//	return "";
//}
//
//
//namespace Engine
//{
//	/**
//	 * implementation
//	 */
//	Int32 operator+(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs += Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator-(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs -= Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator*(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs *= Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator/(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs /= Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator&(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs &= Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator|(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs |= Rhs;
//		return Lhs;
//	}
//	
//	
//	/**
//	 * implementation
//	 */
//	Int32 operator%(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs %= Rhs;
//		return Lhs;
//	}
//
//
//	/**
//	 * implementation
//	 */
//	Int32 operator^(Int32 Lhs, const Int32 &Rhs)
//	{
//		Lhs ^= Rhs;
//		return Lhs;
//	}
//}