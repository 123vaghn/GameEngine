#pragma once

#include "Engine/Engine/Component.h"

namespace Engine
{
}

namespace Engine::Components
{
	class DLL_CLASS Input : public Component
	{
	public:
		Input();

		virtual ~Input() override;

		bool IsKeyDown(int KeyCode) const;
		bool IsMouseButtonDown(int KeyCode) const;

	private:
	};
}

