#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine
{
	struct DLL_CLASS Timestep
	{
		double Delta;

		Timestep(double Delta = 0.0f) noexcept
			: Delta(Delta)
		{
		}

		operator double() const
		{
			return Delta;
		}
	};

	struct DLL_CLASS PhysicsTimestep
	{
		double Delta;

		PhysicsTimestep(double Delta = 0.0f) noexcept
			: Delta(Delta)
		{
		}

		operator double() const
		{
			return Delta;
		}
	};
}
