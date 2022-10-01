
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


#include "pch.h"
#include "Engine/Application/Application.h"
#include "Engine/GL/GL3.h"

using namespace Engine;

#include "SDL.h"

namespace Engine
{
	static bool s_SDL_Init = false;
}


/**
 * implementation
 */
uint64_t Engine::Platform::GetPerformanceCounter()
{
	return SDL_GetPerformanceCounter();
}


/**
 * implementation
 */
uint64_t Engine::Platform::GetPerformanceFrequency()
{
	return SDL_GetPerformanceFrequency();
}


/**
 * implementation
 */
bool Engine::Platform::Initialize()
{
	if (!s_SDL_Init)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			return true;
		}

		unsigned int status = SDL_RegisterEvents(SDL_LASTEVENT - SDL_USEREVENT);
		if (status == (unsigned int)-1)
		{
			return true;
		}
	}
	else
	{
#if defined(_DEBUG)
#endif
	}

	return false;
}

