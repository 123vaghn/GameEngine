
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


#include "pch.h"
#include "Engine/Math/PlaneF.h"
#include "Engine/Exception.h"

using namespace Engine;


/**
 * implementation
 */
PlaneF::PlaneF() noexcept
{
}


/**
 * implementation
 */
PlaneF::PlaneF(float X, float Y, float Z, float W) noexcept
	: X(X), Y(Y), Z(Z), W(W)
{
}
