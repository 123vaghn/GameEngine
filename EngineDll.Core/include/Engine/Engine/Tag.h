#pragma once

#include "Engine/Core/DataTypes/String.h"

namespace Engine
{
	class DLL_CLASS Tag
	{
	public:
		Tag();
		Tag(const String &Name);

	private:
		String m_Name;
	};
}
