#pragma once

#include "Engine/Engine/EngineCoreDefs.h"

#include "Engine/Math/VectorF.h"

namespace Engine::Graphics
{
	class DLL_CLASS Light
	{
	public:
		Light();

		virtual ~Light();

		const VectorF &GetColor() const;
		void SetColor(const VectorF &Color);

		float GetIntensity() const;
		void SetIntensity(float Intensity);

	private:
		VectorF m_Color;
		float m_Intensity;
	};
}
