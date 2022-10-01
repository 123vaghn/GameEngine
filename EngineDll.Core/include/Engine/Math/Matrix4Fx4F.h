
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

// standard library headers.
#include <array>
#include <string>

#include "Engine/Math/VectorF.h"
#include "Engine/Math/PlaneF.h"
#include "Engine/Math/QuaternionF.h"

#define I_C0R0 0
#define I_C0R1 (I_C0R0 + 1)
#define I_C0R2 (I_C0R1 + 1)
#define I_C0R3 (I_C0R2 + 1)
#define I_C1R0 (I_C0R3 + 1)
#define I_C1R1 (I_C1R0 + 1)
#define I_C1R2 (I_C1R1 + 1)
#define I_C1R3 (I_C1R2 + 1)
#define I_C2R0 (I_C1R3 + 1)
#define I_C2R1 (I_C2R0 + 1)
#define I_C2R2 (I_C2R1 + 1)
#define I_C2R3 (I_C2R2 + 1)
#define I_C3R0 (I_C2R3 + 1)
#define I_C3R1 (I_C3R0 + 1)
#define I_C3R2 (I_C3R1 + 1)
#define I_C3R3 (I_C3R2 + 1)


namespace Engine
{
	struct Matrix4Fx4F;
	struct Point;
	struct Rectangle;

	struct DLL_CLASS Matrix4Fx4F
	{
		static Matrix4Fx4F CreateTranslation(const VectorF &Translation);
		static Matrix4Fx4F CreateRotation(const QuaternionF &Rotation);		
		static Matrix4Fx4F CreateRotation(const VectorF &Right, const VectorF &Up, const VectorF &Forward);
		static Matrix4Fx4F CreateScale(const VectorF &Scale);
		static Matrix4Fx4F CreateTRS(const VectorF &Translation, const QuaternionF &Rotation, const VectorF &Scale);
		static Matrix4Fx4F CreatePerspectiveProjection(float FOV, float AspectRatio, float zNear, float zFar);
		static Matrix4Fx4F CreatePerspectiveProjection(float FOV, float Width, float Height, float zNear, float zFar);
		static Matrix4Fx4F CreatePerspectiveProjection(float FOV, const Rectangle &Area, float zNear, float zFar);
		static Matrix4Fx4F CreateOrthographicProjection(float Width, float Height, float zNear, float zFar);
		static Matrix4Fx4F CreateOrthographicProjection(const Rectangle &Area, float zNear, float zFar);
		static Matrix4Fx4F CreateLookAt(const VectorF &Eye, const VectorF &Center, const VectorF &Up);
		static Matrix4Fx4F CreateFrustum(const Rectangle &Area, float zNear, float zFar);

		static const Matrix4Fx4F &GetIdentityMatrix4Fx4F();
		static const Matrix4Fx4F &GetZeroMatrix4Fx4F();

		ALIGN(4) union
		{
			/**
			 * The matrix is a column-major matrix.
			 * 
			 *
			 */
			struct
			{
				// column: 1 -> index: 1
				float C0R0;	

				// column: 1 -> index: 2
				float C0R1;

				// column: 1 -> index: 3
				float C0R2;	

				// column: 1 -> index: 4
				float C0R3;

				// column: 2 -> index: 1
				float C1R0;

				// column: 2 -> index: 2
				float C1R1;

				// column: 2 -> index: 3
				float C1R2;

				// column: 2 -> index: 4
				float C1R3;

				// column: 3 -> index: 1
				float C2R0;

				// column: 3 -> index: 2
				float C2R1;

				// column: 3 -> index: 3
				float C2R2;	

				// column: 3 -> index: 4
				float C2R3;	

				// column: 4 -> index: 1
				float C3R0;

				// column: 4 -> index: 2
				float C3R1;

				// column: 4 -> index: 3
				float C3R2;

				// column: 4 -> index: 4
				float C3R3;
			};

			/**
			 * Helper member.
			 * 
			 * This exists as a way to quickly look-up a value in the matrix.
			 * Be mindful, y' hear?
			 * 
			 */
			float M[4][4] =
			{
				0
			};
		};

		/// <summary>
		/// Creates a new 4x4 floating-point matrix without initialization.
		/// </summary>
		/// <returns></returns>
		Matrix4Fx4F() noexcept;

		/// <summary>
		/// Creates a new 4x4 floating-point matrix.
		/// </summary>
		/// <param name="C0">C0 -> [C0R0, C0R1, C0R2, C0R3]</param>
		/// <param name="C1">C0 -> [C1R0, C1R1, C1R2, C1R3]</param>
		/// <param name="C2">C0 -> [C2R0, C2R1, C2R2, C2R3]</param>
		/// <param name="C3">C0 -> [C3R0, C3R1, C3R2, C3R3]</param>
		/// <returns></returns>
		Matrix4Fx4F(const PlaneF &C0, const PlaneF &C1, const PlaneF &C2, const PlaneF &C3) noexcept;

		/// <summary>
		/// Creates a new 4x4 floating-point matrix.
		/// </summary>
		/// <param name="C0R0">column: 1 -> index: 1</param>
		/// <param name="C0R1">column: 1 -> index: 2</param>
		/// <param name="C0R2">column: 1 -> index: 3</param>
		/// <param name="C0R3">column: 1 -> index: 4</param>
		/// <param name="C1R0">column: 2 -> index: 1</param>
		/// <param name="C1R1">column: 2 -> index: 2</param>
		/// <param name="C1R2">column: 2 -> index: 3</param>
		/// <param name="C1R3">column: 2 -> index: 4</param>
		/// <param name="C2R0">column: 3 -> index: 1</param>
		/// <param name="C2R1">column: 3 -> index: 2</param>
		/// <param name="C2R2">column: 3 -> index: 3</param>
		/// <param name="C2R3">column: 3 -> index: 4</param>
		/// <param name="C3R0">column: 4 -> index: 1</param>
		/// <param name="C3R1">column: 4 -> index: 2</param>
		/// <param name="C3R2">column: 4 -> index: 3</param>
		/// <param name="C3R3">column: 4 -> index: 4</param>
		/// <returns></returns>
		Matrix4Fx4F(float C0R0,float C0R1, float C0R2, float C0R3, float C1R0, float C1R1, float C1R2, float C1R3, float C2R0, float C2R1, float C2R2, float C2R3, float C3R0, float C3R1, float C3R2, float C3R3) noexcept;

		Matrix4Fx4F Determinant() const;
		Matrix4Fx4F Inverse() const;
		Matrix4Fx4F Transpose() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="i"></param>
		/// <returns></returns>
		PlaneF GetColumn(uint32_t i) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="i"></param>
		/// <param name="Column"></param>
		void SetColumn(uint32_t i, const PlaneF &Column);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="i"></param>
		/// <returns></returns>
		PlaneF GetRow(uint32_t i) const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="i"></param>
		/// <param name="Row"></param>
		void SetRow(uint32_t i, const PlaneF &Row);

		/**
		 * 
		 */
		VectorF MultiplyPoint(const VectorF &Vector);

		/**
		 *
		 */
		VectorF MultiplyPointPerspectiveDivide(const VectorF &Vector);

		/**
		 *
		 */
		VectorF MultiplyVector(const VectorF &Vector);

		/**
		 *
		 */
		PlaneF TransformPlane(const PlaneF &Vector);


		/// <summary>
		/// Checks if this matrix is an indentity matrix.
		/// </summary>
		/// <returns>False if this matrix is not an identity matrix.</returns>
		bool IsIdentityMatrix4Fx4F() const;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="i"></param>
		/// <returns></returns>
		float &operator[](uint32_t i);
		const float operator[](uint32_t i) const;

		/// <summary>
		/// 
		/// </summary>
		operator const float *() const
		{
			return &C0R0;
		}

		bool operator==(const Matrix4Fx4F &Rhs);
		bool operator!=(const Matrix4Fx4F &Rhs);

		Matrix4Fx4F &operator*=(const Matrix4Fx4F &Rhs);

		PlaneF operator*(const PlaneF &Rhs);

		std::string ToString() const;
	};

	DLL_FUNC Matrix4Fx4F operator*(Matrix4Fx4F Lhs, const Matrix4Fx4F &Rhs);

	DLL_FUNC bool operator==(const Matrix4Fx4F &Lhs, const Matrix4Fx4F &Rhs);
	DLL_FUNC bool operator!=(const Matrix4Fx4F &Lhs, const Matrix4Fx4F &Rhs);
}
