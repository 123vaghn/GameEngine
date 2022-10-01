
#include "pch.h"
#include "Engine/Engine/Component.h"
#include "Engine/Engine/Actor.h"


using namespace Engine;

const size_t Component::ClassType = std::hash<std::string>()(TO_STRING(Component));


/**
 * implementation
 */
Component::Component()
{
}


/**
 * implementation
 */
Component::Component(const Component &Other)
	: m_Owner(Other.m_Owner)
{
}


/**
 * implementation
 */
Component::Component(Component &&Other) noexcept 
	: m_Owner(std::move(Other.m_Owner))
{
	Other.m_Owner = nullptr;
}


/**
 * implementation
 */
Component::~Component()
{
}


/**
 * implementation
 */
bool Component::IsClassType(const size_t ClassType) const
{
	return ClassType == Component::ClassType;
}


/**
 * implementation
 */
void Component::Tick()
{
}


/**
 * implementation
 */
void Component::Render()
{
}


/**
 * implementation
 */
Transform &Component::GetTransform() const
{
	return GetGameObject()->GetTransform();
}


/**
 * implementation
 */
Component &Component::operator=(const Component &Other)
{
	if (this != &Other)
	{
		m_Owner = Other.m_Owner;
	}

	return *this;
}


/**
 * implementation
 */
Component &Component::operator=(Component &&Other) noexcept
{
	if (this != &Other)
	{
		std::swap(Other.m_Owner, m_Owner);
	}

	return *this;
}


/**
 * implementation
 */
Actor *Component::GetGameObject() const
{
	return m_Owner;
}



