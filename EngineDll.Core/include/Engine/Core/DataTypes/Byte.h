#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS Byte
	{
	public:
		using T = unsigned char;

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		Byte() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Value"></param>
		/// <returns></returns>
		Byte(T Value) noexcept;

		int GetSize() const;

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
		operator T && () noexcept;

	private:
		T m_Tv;
	};
}

