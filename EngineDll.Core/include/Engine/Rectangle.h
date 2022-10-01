#pragma once

#include "Engine/CoreDefs.h"

namespace Engine
{
	struct DLL_CLASS Rectangle
	{
		float Left;
		float Top;
		float Right;
		float Bottom;

		Rectangle(float Left, float Top, float Right, float Bottom) noexcept;
	};
}
