
#include "pch.h"
#include "Engine/Application/Application.h"
#include "Engine/GL/GL3.h"

using namespace Engine;
using namespace Engine::Platform;

#include "SDL.h"


/**
 * implementation
 */
GraphicsDevice::GraphicsDevice(const void *const pHWNDHandle)
try : m_pNativeHWNDHandle(pHWNDHandle)
{
}
catch (...)
{
}


/**
 * implementation
 */
GraphicsDevice::~GraphicsDevice()
{
}


/**
 * implementation
 */
void GraphicsDevice::TryCreateContext()
{
#if defined(_DEBUG)
	SDL_assert(m_pNativeHWNDHandle != nullptr);
#endif

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

	SDL_GL_SetAttribute(SDL_GL_ACCUM_RED_SIZE,		4);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE,			4);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_GREEN_SIZE,	4);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,			4);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_BLUE_SIZE,		4);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,			4);
	SDL_GL_SetAttribute(SDL_GL_ACCUM_ALPHA_SIZE,	4);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,			4);

	int32_t Flags = SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, Flags);

	Flags = SDL_GL_CONTEXT_PROFILE_CORE;
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, Flags);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, SDL_TRUE);

	if ((m_GraphicsHandle = SDL_GL_CreateContext(static_cast<SDL_Window *>(const_cast<void *>(m_pNativeHWNDHandle)))) == nullptr)
	{
		std::terminate();
	}

#if defined(_DEBUG)
	SDL_assert(m_GraphicsHandle != nullptr);
	SDL_assert(SDL_GL_GetCurrentWindow() == m_pNativeHWNDHandle);
	SDL_assert(SDL_GL_GetCurrentContext() == m_GraphicsHandle);
#endif

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::terminate();
	}
}


/**
 * implementation
 */
void GraphicsDevice::Display()
{
#if defined(_DEBUG)
	SDL_assert(m_GraphicsHandle != nullptr);
#endif

	SDL_GL_SwapWindow(static_cast<SDL_Window *>(const_cast<void *>(m_pNativeHWNDHandle)));
}


/**
 * implementation
 */
void GraphicsDevice::SetVSyncEnabled(VSyncMode Mode)
{
#if defined(_DEBUG)
	SDL_assert(m_GraphicsHandle != nullptr);
#endif

	SDL_GL_SetSwapInterval((int)Mode);
}
