
#include "pch.h"
#include "Engine/Engine/Actor.h"
#include "Engine/Engine/Transform.h"
#include "Engine/Engine/Component.h"

using namespace Engine;


/**
 * implementation
 */
Actor::Actor(const char *Name)
	: Object(Name), m_Transform(std::make_shared<Transform>())
{
}


/**
 * implementation
 */
void Actor::AddChild(Actor &Child)
{
	Child.m_Transform->m_Parent = &GetTransform();

	m_Children.push_back(Child);
}


/**
 * implementation
 */
bool Actor::Tick()
{
	for (const auto &value : m_Components)
	{
		value->Tick();
	}

	for (auto &object : m_Children)
	{
		bool bRet;
		
		if ((bRet = object.Tick()) == false)
		{
		}
	}

	return true;
}

 
/**
 * implementation
 */
Transform &Actor::GetTransform() const
{
	return *get_ptr(m_Transform);
}


/**
 * implementation
 */
size_t Actor::GetID() const
{
	return m_ID;
}

