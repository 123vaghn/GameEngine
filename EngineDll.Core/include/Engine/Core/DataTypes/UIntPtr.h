#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	class DLL_CLASS UIntPtr
	{
	public:
		using T = unsigned long long int;
		
	public:
		UIntPtr() noexcept;
		UIntPtr(T *Address) noexcept;
		UIntPtr(const UIntPtr &Other);
		UIntPtr(UIntPtr &&Other) noexcept;

		~UIntPtr();

		UIntPtr &operator=(const UIntPtr &Other);
		UIntPtr &operator=(UIntPtr &&Other) noexcept;



	private:
		T *m_Tp;
	};
}
