#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS Boolean
	{
	public:
		using T = bool;

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		Boolean() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Value"></param>
		/// <returns></returns>
		Boolean(T Value) noexcept;

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

