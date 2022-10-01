
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
	struct VectorF;
	struct QuaternionF;
	struct AngleF;

	struct DLL_CLASS VectorF
	{
	public:
		static VectorF s_Zero;
		static VectorF s_One;
		static VectorF s_Back;
		static VectorF s_Forward;
		static VectorF s_Left;
		static VectorF s_Right;
		static VectorF s_Down;
		static VectorF s_Up;

	public:
		static float GetDotProduct(const VectorF &Lhs, const VectorF &Rhs);
		static VectorF GetCrossProduct(const VectorF &Lhs, const VectorF &Rhs);
		static VectorF GetNormalizedVector(const VectorF &Lhs);
		static void Normalize(VectorF &Other);
		static float GetDistanceBetweenPoints(const VectorF &Lhs, const VectorF &Rhs);
		static VectorF Lerp(const VectorF &Lhs, const VectorF &Rhs, float Time);
		static VectorF Slerp(const VectorF &Lhs, const VectorF &Rhs, float Time);
		static float GetAngle(const VectorF &Lhs, const VectorF &Rhs);
		static VectorF GetMin(const VectorF &Lhs);
		static VectorF GetMax(const VectorF &Lhs);
		static VectorF GetAbs(const VectorF &Lhs);

	public:
		ALIGN(4) union
		{
			struct
			{
				float X;
				float Y;
				float Z;
			};
		};

		VectorF() noexcept;
		VectorF(float X, float Y, float Z) noexcept;

	public:
		float GetMagnitude() const;
		float GetMagnitudeSquared() const;

		void Set(float X, float Y, float Z) noexcept;

		VectorF Rotate(AngleF Angle, const VectorF &Axis);
		VectorF Rotate(const QuaternionF &Rotation);

	public:
		float GetDotProduct(const VectorF &Other) const;
		VectorF GetCrossProduct(const VectorF &Other) const;
		VectorF GetNormalizedVector() const;
		void Normalize();
		VectorF Lerp(const VectorF &Other, float Time) const;
		VectorF Slerp(const VectorF &Other, float Time) const;

	public:
		float &operator[](std::int32_t i);
		const float operator[](std::int32_t i) const;

		VectorF &operator!();

		bool operator==(const VectorF &Rhs);
		bool operator!=(const VectorF &Rhs);

		VectorF &operator+=(const VectorF &Rhs);
		VectorF &operator+=(float Rhs);
		VectorF &operator-=(const VectorF &Rhs);
		VectorF &operator-=(float Rhs);
		VectorF &operator*=(const VectorF &Rhs);
		VectorF &operator*=(float Rhs);
		VectorF &operator/=(const VectorF &Rhs);
		VectorF &operator/=(float Rhs);

	public:
		const char *ToString() const;
	};

	DLL_CLASS VectorF operator+(VectorF Lhs, const VectorF &Rhs);
	DLL_CLASS VectorF operator+(VectorF Lhs, float Rhs);
	DLL_CLASS VectorF operator-(VectorF Lhs, const VectorF &Rhs);
	DLL_CLASS VectorF operator-(VectorF Lhs, float Rhs);
	DLL_CLASS VectorF operator*(VectorF Lhs, const VectorF &Rhs);
	DLL_CLASS VectorF operator*(VectorF Lhs, float Rhs);
	DLL_CLASS VectorF operator/(VectorF Lhs, const VectorF &Rhs);
	DLL_CLASS VectorF operator/(VectorF Lhs, float Rhs);

	DLL_CLASS bool operator==(const VectorF &Lhs, const VectorF &Rhs);
	DLL_CLASS bool operator!=(const VectorF &Lhs, const VectorF &Rhs);
}
