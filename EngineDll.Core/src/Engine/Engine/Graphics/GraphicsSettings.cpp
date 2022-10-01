
#include "pch.h"
#include "Engine/Engine/Graphics/Graphics.h"

using namespace Engine;
using namespace Engine::Graphics;

namespace Engine::Graphics
{
	static GraphicsAPI s_API = GraphicsAPI::None;
}



/**
 * implementation
 */
GraphicsAPI Engine::Graphics::GetAPI()
{
	return s_API;
}


/**
 * implementation
 */
void Engine::Graphics::SetAPI(GraphicsAPI API)
{
	s_API = API;
}
