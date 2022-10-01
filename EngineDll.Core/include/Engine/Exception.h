#pragma once

#include "Engine/Core/DataTypes/String.h"

namespace Engine
{
	class DLL_CLASS Exception
	{
	public:
		Exception();
		Exception(const String &Message);

		virtual ~Exception()
		{
		}

		const String &GetMessage() const;

	private:
		String m_Message;
	};
}

