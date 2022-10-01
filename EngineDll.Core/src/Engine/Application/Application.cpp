
//
// Copyright (C) 2022, 2022 Joseph Combs.
// See LICENSE for details.
//


#include "pch.h"
#include "Engine/Application/Application.h"
#include "Engine/GL/GL3.h"

using namespace Engine;

#include "SDL.h"


/**
 * implementation
 */
Application::Application()
{
	Engine::Platform::Initialize();
}


/**
 * implementation
 */
Application::~Application()
{
}


/**
 * implementation
 */
void Application::Run()
{
	double time = (double)Engine::Platform::GetPerformanceCounter();
	double time_previous = time;
	double time_delta = 0;
	double time_delta_elapsed = 0;

	m_Run = true;
	
	while ((m_Run) != false)
	{
		bool bRet;

		if ((bRet = HandlePlatformEvents()) == false)
		{
			break;
		}

		time_previous = time;
		time = (double)Engine::Platform::GetPerformanceCounter();
		time_delta = (double)((time - time_previous) / (double)Engine::Platform::GetPerformanceFrequency());
		time_delta_elapsed += time_delta;
		
		constexpr double SECONDS_PER_PHYSICS_TICK = (double)(1 / 60.0);

		while (time_delta_elapsed >= SECONDS_PER_PHYSICS_TICK)
		{
			time_delta_elapsed -= SECONDS_PER_PHYSICS_TICK;

			GamePhysicsUpdate({ time_delta });
		}

		GameUpdate(time_delta);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0, 0, 0, 1);

		//
		// graphics
		//
	
		m_GraphicsDevice->Display();
	}

	Shutdown();
}


/**
 * implementation
 */
void Application::CreateHWND()
{
	m_pHWNDHandle = SDL_CreateWindow(
		"", 
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1600,
		900,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (!m_pHWNDHandle)
	{
		std::terminate();
	}
}


/**
 * implementation
 */
void Application::CreateGraphicsDevice()
{
	if ((m_GraphicsDevice = std::make_unique<Platform::GraphicsDevice>(m_pHWNDHandle)) == nullptr)
	{
		std::terminate();
	}

	m_GraphicsDevice->TryCreateContext();
}


/**
 * implementation
 */
void Application::GameUpdate(Timestep DeltaTime)
{
}


/**
 * implementation
 */
void Application::GamePhysicsUpdate(PhysicsTimestep DeltaTime)
{
}


/**
 * implementation
 */
bool Application::HandlePlatformEvents()
{
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0)
	{
		switch (e.type)
		{
		case SDL_WINDOWEVENT:
			switch (e.window.event)
			{
			case SDL_WINDOWEVENT_CLOSE:
				m_Run = false;
				break;
			case SDL_WINDOWEVENT_TAKE_FOCUS:
				if (!SDL_SetWindowInputFocus(static_cast<SDL_Window *>(m_pHWNDHandle)))
				{
				}

				break;
			case SDL_WINDOWEVENT_ENTER:
			case SDL_WINDOWEVENT_FOCUS_GAINED:
			case SDL_WINDOWEVENT_LEAVE:
			case SDL_WINDOWEVENT_FOCUS_LOST:
			case SDL_WINDOWEVENT_ICCPROF_CHANGED:
			case SDL_WINDOWEVENT_MAXIMIZED:
			case SDL_WINDOWEVENT_MINIMIZED:
			case SDL_WINDOWEVENT_DISPLAY_CHANGED:
			case SDL_WINDOWEVENT_MOVED:
			case SDL_WINDOWEVENT_RESIZED:
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			case SDL_WINDOWEVENT_SHOWN:
			case SDL_WINDOWEVENT_HIDDEN:
			default:
				break;
			}

			break;
		case SDL_DISPLAYEVENT:
			switch (e.display.event)
			{
			case SDL_DISPLAYEVENT_CONNECTED:
			case SDL_DISPLAYEVENT_DISCONNECTED:
			case SDL_DISPLAYEVENT_ORIENTATION:
			default:
				break;
			}

			break;
		case SDL_KEYDOWN:
		case SDL_KEYUP:
		case SDL_KEYMAPCHANGED:
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
		case SDL_CONTROLLERDEVICEADDED:
		case SDL_CONTROLLERDEVICEREMOVED:
		case SDL_TEXTINPUT:
		case SDL_TEXTEDITING_EXT:
		case SDL_TEXTEDITING:
		case SDL_AUDIODEVICEADDED:
		case SDL_AUDIODEVICEREMOVED:
			break;
		case SDL_USEREVENT:
			switch (e.user.type)
			{
			default:
				break;
			}

			break;
		case SDL_QUIT:
			if ((m_Run) == false)
			{
				return false;
			}

			break;
		case SDL_SYSWMEVENT:
			// Anything SDL doesn't handle can be manually handled here.
			return true;
		default:
			break;
		}
	}

	return true;
}


/**
 * implementation
 */
void Application::Shutdown()
{
}


/**
 *	void Application::EngineThreadFunction()
 *	{
 *		using namespace std::literals;
 *	
 *		auto dt = std::chrono::duration<std::uint64_t, std::ratio<1, 60>>{ 1 };
 *	
 *		typedef decltype(std::chrono::steady_clock::duration{} + dt) duration;
 *		typedef std::chrono::time_point<std::chrono::steady_clock, duration> time_point;
 *	
 *		time_point time = std::chrono::steady_clock::now();
 *		time_point time_previous;
 *	
 *		duration accumulator = 0s;
 *	
 *		while (!m_EngineThreadDone)
 *		{
 *			time_previous = time;
 *			time = std::chrono::steady_clock::now();
 *	
 *			auto delta = time - time_previous;
 *	
 *			if (delta > 250ms)
 *			{
 *				delta = 250ms;
 *			}
 *	
 *			accumulator += delta;
 *	
 *			while (accumulator >= dt)
 *			{
 *				PhysicsUpdate();
 *	
 *				accumulator -= dt;
 *			}
 *	
 *			Update();
 *			Render();
 *		}
 *	}
 */

