#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS UInt64
	{
	public:
		using T = unsigned long long int;

	public:
		UInt64() noexcept;
		UInt64(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T &&() noexcept;

	private:
		T m_Tv;
	};
}

