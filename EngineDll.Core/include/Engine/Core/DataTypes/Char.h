#pragma once

#include "Engine/Core/DataTypes/SByte.h"

namespace Engine
{
	class DLL_CLASS Char
	{
	public:
		using T = wchar_t;

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Source"></param>
		/// <param name="Destination"></param>
		/// <returns></returns>
		static unsigned int ToAsciiString(const Char *const Source, SByte *Destination);

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		Char() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Value"></param>
		/// <returns></returns>
		Char(T Value) noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		operator const T &() const noexcept;
		
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		operator T &() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		operator T &&() noexcept;

	private:
		T m_Tv;
	};
}

