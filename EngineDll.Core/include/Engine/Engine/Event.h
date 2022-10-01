#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine
{
	class DLL_CLASS Event
	{
		friend class EventDispatcher;

	public:
		Event();

		bool WasHandledByLayer() const;

	private:
		bool m_Handled;
	};
}
