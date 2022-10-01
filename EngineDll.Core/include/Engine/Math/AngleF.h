
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

#include "Engine/Math/MathF.h"

namespace Engine
{
	struct DLL_CLASS AngleF
	{
		ALIGN(4) union
		{
			struct
			{
				float Direction;
			};
		};

		AngleF() noexcept;
		AngleF(float Direction) noexcept;

		void Set(float Direction);

		operator const float &() const { return Direction;}
		operator float &() { return Direction; }
	};
	
	DLL_CLASS bool operator==(const AngleF &Lhs, const AngleF &Rhs);
	DLL_CLASS bool operator==(float Lhs, const AngleF &Rhs);
	DLL_CLASS bool operator==(const AngleF &Lhs, float Rhs);
	DLL_CLASS bool operator!=(const AngleF &Lhs, const AngleF &Rhs);
	DLL_CLASS bool operator!=(float Lhs, const AngleF &Rhs);
	DLL_CLASS bool operator!=(const AngleF &Lhs, float Rhs);
}

