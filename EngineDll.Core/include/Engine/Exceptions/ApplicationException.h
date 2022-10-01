#pragma once

#include "Engine/Exception.h"

namespace Engine
{
	class DLL_CLASS ApplicationException : public Exception
	{
	public:
		ApplicationException();
	};
}
