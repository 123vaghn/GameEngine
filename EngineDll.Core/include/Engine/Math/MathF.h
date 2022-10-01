
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

#ifndef DLL_MATH_FUNC_API
#define DLL_MATH_FUNC_API DLL_FUNC
#endif

#include <xmmintrin.h>

namespace Engine
{
	class DLL_CLASS MathF
	{
	public:
		enum class DLL_CLASS RoundingMode
		{
			Down,
			Nearest,
			Zero,
			Up
		};

	public:
		static const float s_Epsilon;
		static const float s_PI;
		static RoundingMode s_CurrentRoundingMode;
	
	public:
		static float Abs(float x);
		static float Min(float x, float y);
		static float Max(float x, float y);
		static float PositiveDifference(float x, float y);
		static float Nan(const char *&x);
		static float Pow(float Base, float Exponent);
		static float Pow(float Base, int32_t Exponent);
		static float Exponent(float x);
		static float Exp2(float x);
		static float ExpM1(float x);
		static float Log(float x);
		static float Log10(float x);
		static float Log2(float x);
		static float Log1Plus(float x);
		static float Sqrt(float x);
		static float Cbrt(float x);
		static float Hypotenuse(float x, float y);
		static float Hypotenuse(float x, float y, float z);
		static float Sin(float x);
		static float Cos(float x);
		static float Tan(float x);
		static float ASin(float x);
		static float ACos(float x);
		static float ATan(float x);
		static float ATan2(float x, float y);
		static float Sinh(float x);
		static float Cosh(float x);
		static float Tanh(float x);
		static float ASinh(float x);
		static float ACosh(float x);
		static float ATanh(float x);
		static float Ceil(float x);
		static float Floor(float x);
		static float Truncate(float x);
		static float Round(float x, MathF::RoundingMode RoundingMode = MathF::RoundingMode::Nearest);
		static float NearbyInt(float x, MathF::RoundingMode RoundingMode = MathF::RoundingMode::Nearest);
		static float DecomposeExponentP2(float x, int32_t *result);
		static float DecomposeFraction(float x, float *result);
		static float Scale(float x, int32_t Exponent);
		static float Scale(float x, int64_t Exponent);
		static int32_t iLogb(float x);
		static float Logb(float x);
		static float CopySign(float Magnitude, float Sign);
		static bool FloatType(float x);
		static bool IsFinite(float x);
		static bool IsInfinite(float x);
		static bool IsNan(float x);
		static bool IsNormal(float x);
		static bool Sign(float x);
		static bool IsGreater(float x, float y);
		static bool IsGreaterEqual(float x, float y);
		static bool IsLess(float x, float y);
		static bool IsLessEqual(float x, float y);
		static bool IsLessGreater(float x, float y);
		static bool IsUnordered(float x, float y);
		static float DegreesToRadians(float Degrees);
		static float RadiansToDegrees(float Radians);
	};
}

