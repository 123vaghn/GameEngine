
#include "pch.h"
#include "Engine/Engine/Event.h"

using namespace Engine;

Event::Event()
	: m_Handled(false)
{
}

bool Event::WasHandledByLayer() const
{
	return m_Handled;
}
