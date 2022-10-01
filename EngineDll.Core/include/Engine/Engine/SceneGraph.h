#pragma once

#include "Engine/Engine/Actor.h"

namespace Engine
{
	class DLL_CLASS SceneGraph
	{
	public:
		SceneGraph();
		SceneGraph(const SceneGraph &) = delete;
		SceneGraph(SceneGraph &&) noexcept = delete;

		~SceneGraph();

		SceneGraph &operator=(const SceneGraph &) = delete;
		SceneGraph &operator=(SceneGraph &&) noexcept = delete;

	private:
	};
}

