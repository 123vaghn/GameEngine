#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS SByte
	{
	public:
		using T = signed char;

	public:
		SByte() noexcept;
		SByte(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T && () noexcept;

	private:
		T m_Tv;
	};
}

