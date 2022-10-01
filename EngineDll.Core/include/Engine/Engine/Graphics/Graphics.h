#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

namespace Engine::Graphics
{
	enum class GraphicsAPI
	{
		None = -1,
		OpenGLCoreProfile
	};

	DLL_CLASS GraphicsAPI GetAPI();
	DLL_CLASS void SetAPI(GraphicsAPI API);
}
