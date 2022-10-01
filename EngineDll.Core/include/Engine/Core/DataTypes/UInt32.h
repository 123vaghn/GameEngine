#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS UInt32
	{
	public:
		using T = unsigned int;

	public:
		UInt32() noexcept;
		UInt32(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T && () noexcept;

	private:
		T m_Tv;
	};
}

