
#include "pch.h"
#include "Engine/Engine/Graphics/Light.h"

using namespace Engine;
using namespace Engine::Graphics;


/**
 * implementation
 */
Light::Light()
{
}


/**
 * implementation
 */
Light::~Light()
{
}


const VectorF &Light::GetColor() const
{
	return m_Color;
}

void Light::SetColor(const VectorF &Color)
{
	m_Color = Color;
}

float Light::GetIntensity() const
{
	return m_Intensity;
}

void Light::SetIntensity(float Intensity) 
{
	m_Intensity = Intensity;
}
