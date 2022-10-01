#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

#include "Engine/Math/VectorF.h"

namespace Engine::Graphics
{
	struct DLL_CLASS Vertex
	{
		ALIGN(4) struct
		{
			VectorF Position;
			VectorF Normal;

			struct
			{
				float X;
				float Y;
			} TexCoords0;
		};

		Vertex() noexcept;
		Vertex(float F0, float F1, float F2, float F3, float F4, float F5 = 0.0f, float F6 = 0.0f, float F7 = 0.0f) noexcept;
	};

	struct DLL_CLASS VertexPosition
	{
		float X;
		float Y;
		float Z;
	};
	
	struct DLL_CLASS VertexPositionColor
		: public VertexPosition
	{
	};

	struct DLL_CLASS VertexPositionColorTexture
		: public VertexPosition
	{
	};

	struct DLL_CLASS VertexPositionNormalTexture
		: public VertexPosition
	{
	};

	struct DLL_CLASS VertexPositionTexture
		: public VertexPosition
	{
	};
}
