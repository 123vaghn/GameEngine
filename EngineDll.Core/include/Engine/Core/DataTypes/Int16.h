#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS Int16
	{
	public:
		using T = signed short;
		
	public:
		Int16() noexcept;
		Int16(T Value) noexcept;

		operator const T &() const noexcept;
		operator T &() noexcept;
		operator T &&() noexcept;

	private:
		T m_Tv;
	};
}
