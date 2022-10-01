
#pragma once

#include "Engine/Engine/Event.h"
#include "Engine/Engine/EventDispatcher.h"
#include "Engine/Engine/Scene.h"

namespace MyApp
{
	class TestScene : public Engine::Scene
	{
	public:
		TestScene();
		
		virtual ~TestScene() override;

		virtual void OnScenePlay() override;
		virtual void OnSceneStop() override;

		virtual void OnSceneActorUpdate(Engine::Timestep DeltaTime) override;
		virtual void OnSceneActorPhysicsUpdate(Engine::PhysicsTimestep DeltaTime) override;

	private:
	};
}
