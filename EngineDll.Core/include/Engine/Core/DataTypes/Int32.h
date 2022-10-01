#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS Int32
	{
	public:
		using T = signed int;

	public:
		Int32() noexcept;
		Int32(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T &&() noexcept;

	private:
		T m_Tv;
	};


	/**
	 *
	 * UNUSED 
	 * 
	 * 
	class DLL_CLASS Int32
	{
	public:
		Int32() noexcept;
		Int32(std::int32_t Value) noexcept;

		operator std::int32_t();
		operator const std::int32_t() const;

		Int32 &operator+=(const Int32 &Rhs);
		Int32 &operator-=(const Int32 &Rhs);
		Int32 &operator*=(const Int32 &Rhs);
		Int32 &operator/=(const Int32 &Rhs);
		Int32 &operator&=(const Int32 &Rhs);
		Int32 &operator|=(const Int32 &Rhs);
		Int32 &operator%=(const Int32 &Rhs);
		Int32 &operator^=(const Int32 &Rhs);

		friend Int32 operator+(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator-(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator*(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator/(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator&(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator|(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator%(Int32 Lhs, const Int32 &Rhs);
		friend Int32 operator^(Int32 Lhs, const Int32 &Rhs);

		Int32 &operator++();
		Int32 operator++(int);

		Int32 &operator--();
		Int32 operator--(int);

		Int32 &operator=(std::int32_t Rhs);
		Int32 &operator=(const std::int32_t &Rhs);
		Int32 &operator=(std::int32_t &&Rhs) noexcept;

		friend Int32 operator!(const Int32 &Lhs);

		bool operator==(const Int32 &Rhs);
		bool operator!=(const Int32 &Rhs);

		friend bool operator<(const Int32 &Lhs, const Int32 &Rhs);
		friend bool operator>(const Int32 &Lhs, const Int32 &Rhs);
		friend bool operator<=(const Int32 &Lhs, const Int32 &Rhs);
		friend bool operator>=(const Int32 &Lhs, const Int32 &Rhs);

		std::string ToString() const;

	private:
		std::int32_t m_Data;
	};

	DLL_CLASS Int32 operator+(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator-(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator*(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator/(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator&(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator|(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator%(Int32 Lhs, const Int32 &Rhs);
	DLL_CLASS Int32 operator^(Int32 Lhs, const Int32 &Rhs);
	 */
}
