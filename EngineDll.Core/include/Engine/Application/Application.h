
// 
// Copyright (C) 2022, 2022 Joseph Combs.
//
//  
// This software is licensed under the BSD 3-Clause License. You may use this software 
// under the terms of the BSD 3-Clause License.
// 
// 
// See LICENSE for details.
// 


#pragma once

#include "Engine/Application/PlatformGraphics.h"
#include "Engine/Engine/Timestep.h"

namespace Engine
{
	class DLL_CLASS Application
	{
	public:
		Application();
		Application(const Application &) = delete;
		Application(Application &&) noexcept = delete;

		virtual ~Application();

		void Run();

		Application &operator=(const Application &) = delete;
		Application &operator=(Application &&) noexcept = delete;

	protected:
		void CreateHWND();
		void CreateGraphicsDevice();

		virtual void GameUpdate(Timestep DeltaTime);
		virtual void GamePhysicsUpdate(PhysicsTimestep DeltaTime);

	private:
		bool m_Run;
		std::unique_ptr<Platform::GraphicsDevice> m_GraphicsDevice;

		void *m_pHWNDHandle;

		bool HandlePlatformEvents();
		void Shutdown();
	};
}

namespace Engine::Platform
{
	DLL_CLASS uint64_t GetPerformanceCounter();
	DLL_CLASS uint64_t GetPerformanceFrequency();
}

