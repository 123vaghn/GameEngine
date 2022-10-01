#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS Int64
	{
	public:
		using T = signed long long int;

	public:
		Int64() noexcept;
		Int64(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T &&() noexcept;

	private:
		T m_Tv;
	};
}

