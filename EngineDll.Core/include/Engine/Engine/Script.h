#pragma once

#include "Engine/Engine/Object.h"

namespace Engine
{
	class DLL_CLASS Script : public Object
	{
	public:
		Script();

		virtual ~Script();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();
		virtual void OnStart();
		virtual void OnUpdate();

	private:
	};
}


