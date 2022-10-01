#pragma once

#include "Engine/Engine/Graphics/Light.h"
#include "Engine/Math/VectorF.h"

namespace Engine::Graphics
{
	class DLL_CLASS DirectionalLight : public Light
	{
	public:
		DirectionalLight();

		const VectorF &GetDirection() const;

		void SetDirection(const VectorF &Direction);

	private:
		VectorF m_Direction;
	};
}

