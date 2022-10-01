
#include "pch.h"
#include "Engine/Engine/Graphics/DirectionalLight.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
DirectionalLight::DirectionalLight()
{
}

const VectorF &DirectionalLight::GetDirection() const
{
	return m_Direction;
}

void DirectionalLight::SetDirection(const VectorF &Direction)
{
	m_Direction = Direction;
	m_Direction.Normalize();
}
