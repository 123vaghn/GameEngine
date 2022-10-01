#pragma once

#include "Engine/Engine/Component.h"
#include "Engine/Engine/Script.h"

namespace Engine::Components
{
	class DLL_CLASS Behavior : public Component
	{
	public:
		static const size_t ClassType;

	public:
		Behavior();
	
		virtual ~Behavior();

		virtual bool IsClassType(const size_t ClassType) const;

		virtual void Tick();
		virtual void Render();

	private:
	};
}


