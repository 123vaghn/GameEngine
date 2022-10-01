
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

#include "Engine/Math/AngleF.h"
#include "Engine/Math/VectorF.h"

namespace Engine
{
	struct QuaternionF;
	struct VectorF;
	struct Matrix4Fx4F;


	struct DLL_CLASS QuaternionF
	{
	public:
		static QuaternionF CreateFromAxisAngle(const VectorF &Axis, AngleF Angle);
		static QuaternionF CreateFromRotationMatrix(const Matrix4Fx4F &RotationMatrix);
		static QuaternionF CreateFromEulerAngles(float X, float Y, float Z);
		static QuaternionF CreateFromEulerAngles(const VectorF &EulerAngles);
		static float GetDotProduct(const QuaternionF &Lhs, const QuaternionF &Rhs);
		static const QuaternionF &GetIdentityRotation();

	public:
		ALIGN(4) union
		{
			struct
			{
				float W;
				float X;
				float Y;
				float Z;
			};
		};

		QuaternionF() noexcept;
		QuaternionF(float W, float X, float Y, float z) noexcept;
		QuaternionF(float W, const VectorF &XYZ);

	public:
		float GetMagnitude() const;
		float GetMagnitudeSquared() const;
		
		void Set(float W, float X, float Y, float Z) noexcept;
		
	public:
		QuaternionF GetConjugate() const;
		QuaternionF GetNormalizedRotation() const;
		void Normalize();

		Matrix4Fx4F ToRotationMatrix() const;

		/**
		 * Calculates and returns the right (+X) direction relative to this rotation.
		 */
		VectorF GetRight() const;

		/**
		 * Calculates and returns the up (+Y) direction relative to this rotation.
		 */
		VectorF GetUp() const;

		/**
		 * Calculates and returns the back (+Z) direction relative to this rotation.
		 */
		VectorF GetBack() const;

		/**
		 * Calculates and returns the  direction opposite to the right direction (-X) relative to this rotation.
		 */
		VectorF GetLeft() const;

		/**
		 * Calculates and returns the direction opposite to the up direction (-Y) relative to this rotation.
		 */
		VectorF GetDown() const;

		/**
		 * Calculates and returns the direction opposite to the back direction (-Z) relative to this rotation.
		 */
		VectorF GetForward() const;

	public:
		float &operator[](int32_t i);
		const float operator[](int32_t i) const;

		bool operator==(const QuaternionF &Rhs);
		bool operator!=(const QuaternionF &Rhs);
	
		QuaternionF &operator*=(const QuaternionF &Rhs);
		QuaternionF &operator*=(const VectorF &Rhs);
		
		const char *ToString() const;
	};

	DLL_CLASS QuaternionF operator*(QuaternionF Lhs, const QuaternionF &Rhs);
	DLL_CLASS QuaternionF operator*(QuaternionF Lhs, const VectorF &Rhs);

	DLL_CLASS VectorF operator*(const QuaternionF &Lhs, const VectorF &Rhs);;
	
	DLL_CLASS bool operator==(const QuaternionF &Lhs, const QuaternionF &Rhs);
	DLL_CLASS bool operator!=(const QuaternionF &Lhs, const QuaternionF &Rhs);
}
