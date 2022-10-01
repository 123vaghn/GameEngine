
// 
// Copyright (C) 2022, 2022 Joseph Combs.
//
//  
// This software is licensed under the BSD 3-Clause License. You may use this software 
// under the terms of the BSD 3-Clause License.
// 
// 
// See LICENSE for details.
// 


#pragma once

#include "Engine/CoreDefs.h"
#include "Engine/Application/Types.h"

#include <mutex>
#include <memory>

namespace Engine::Platform
{
	enum class VSyncMode : int32_t
	{
		VSYNC_ADAPTIVE = -1,
		VSYNC_IMMEDIATE,
		VSYNC_DISABLED
	};
	
	class DLL_CLASS GraphicsDevice
	{
	public:
		GraphicsDevice(const void *const pHWNDHandle);
		GraphicsDevice(const GraphicsDevice &) = delete;
		GraphicsDevice(GraphicsDevice &&) noexcept = delete;

		~GraphicsDevice();

		void TryCreateContext();
		void Display();
		void SetVSyncEnabled(VSyncMode Mode);

		GraphicsDevice &operator=(const void *const pHWNDHandle);
		GraphicsDevice &operator=(GraphicsDevice &&) noexcept = delete;

	private:
		const void *const m_pNativeHWNDHandle;
		void *m_GraphicsHandle;
	};
}
