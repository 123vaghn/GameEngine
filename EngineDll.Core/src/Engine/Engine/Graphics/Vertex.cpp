
#include "pch.h"
#include "Engine/Engine/Graphics/Vertex.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Vertex::Vertex() noexcept
{
}


/**
 * implementation
 */
Vertex::Vertex(float F0, float F1, float F2, float F3, float F4, float F5, float F6, float F7) noexcept
	: Position(F0, F1, F2), Normal(F5, F6, F7), TexCoords0{ F3, F4 }
{
}

