
#include "pch.h"
#include "Engine/Engine/Components/Behavior.h"

using namespace Engine;
using namespace Engine::Components;

const size_t Behavior::ClassType = std::hash<std::string>()(TO_STRING(Behavior));


/**
 * implementation
 */
Behavior::Behavior()
{
}


/**
 * implementation
 */
Behavior::~Behavior()
{
}


/**
 * implementation
 */
bool Behavior::IsClassType(const size_t ClassType) const
{
    return ClassType == Behavior::ClassType ? true : Component::IsClassType(ClassType);
}


/**
 * implementation
 */
void Behavior::Tick()
{
}


/**
 * implementation
 */
void Behavior::Render()
{
}

