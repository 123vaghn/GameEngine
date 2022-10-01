#pragma once

#include "Engine/Engine/EngineCoreDefs.h"
#include "Engine/Core/DataTypes/String.h"

namespace Engine
{
	class DLL_CLASS Object
	{
	public:
		Object(const char *Name = "");

		virtual ~Object();

		virtual const char *ToString() const;

	private:
		std::string m_Name;
	};
}