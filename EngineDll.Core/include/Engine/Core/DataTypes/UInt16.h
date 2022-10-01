#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS UInt16
	{
	public:
		using T = unsigned short int;

	public:
		UInt16() noexcept;
		UInt16(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T && () noexcept;

	private:
		T m_Tv;
	};
}

