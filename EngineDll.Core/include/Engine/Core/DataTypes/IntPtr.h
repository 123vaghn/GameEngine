#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS IntPtr
	{
	public:
		using T = signed long long int;

	public:
		IntPtr() noexcept;
		IntPtr(T *Address) noexcept;
		IntPtr(const IntPtr &Other);
		IntPtr(IntPtr &&Other) noexcept;
		
		~IntPtr();

		IntPtr &operator=(const IntPtr &Other);
		IntPtr &operator=(IntPtr &&Other) noexcept;

	private:
		T *m_Tp;
	};
}
