#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	struct DLL_CLASS Point
	{
		float X;
		float Y;

		Point(float X, float Y) noexcept;
	};
}
