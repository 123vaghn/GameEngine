#pragma once

#include "Engine/Engine/EngineCoreDefs.h"
#include "Engine/Engine/Timestep.h"

namespace Engine
{
	class DLL_CLASS Scene
	{
	public:
		Scene();
		Scene(const Scene &) = delete;

		virtual ~Scene();

		virtual void OnScenePlay();
		virtual void OnSceneStop();

		virtual void OnSceneActorUpdate(Timestep DeltaTime);
		virtual void OnSceneActorPhysicsUpdate(PhysicsTimestep DeltaTime);

		Scene &operator=(const Scene &) = delete;;

	private:
	};
}

