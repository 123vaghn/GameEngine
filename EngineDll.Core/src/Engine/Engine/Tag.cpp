
#include "pch.h"
#include "Engine/Engine/Tag.h"

using namespace Engine;

Tag::Tag()
	: m_Name(L"")
{
}

Tag::Tag(const String &Name)
	: m_Name(Name)
{
}
