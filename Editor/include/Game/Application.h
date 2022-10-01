
#pragma once

#include "Engine/Application/Application.h"
#include "Engine/Engine/Timestep.h"

namespace MyApp
{
	class Game : public Engine::Application
	{
	public:
		Game();
		
		virtual ~Game() override;

	private:
		virtual void GameUpdate(Engine::Timestep DeltaTime) override;
		virtual void GamePhysicsUpdate(Engine::PhysicsTimestep DeltaTime) override;
	};
}
