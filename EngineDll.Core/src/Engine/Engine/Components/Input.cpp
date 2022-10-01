
#include "pch.h"
#include "Engine/Engine/Components/Input.h"

using namespace Engine;
using namespace Engine::Components;


#include <SDL/SDL.h>


/**
 * implementation
 */
Input::Input()
{
}


/**
 * implementation
 */
bool Input::IsKeyDown(int KeyCode) const
{
	const unsigned char *keys = SDL_GetKeyboardState(NULL);

	return keys[KeyCode];
}


/**
 * implementation
 */
bool Input::IsMouseButtonDown(int KeyCode) const
{
	int x;
	int y;
	return SDL_BUTTON(SDL_GetMouseState(&x, &y));
}


/**
 * implementation
 */
Input::~Input()
{
}

