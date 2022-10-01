
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
#include "Engine/Math/VectorF.h"
#include "Engine/Math/QuaternionF.h"
#include "Engine/Math/AngleF.h"
#include "Engine/Exception.h"

using namespace Engine;

VectorF VectorF::s_Zero(0.0F, 0.0F, 0.0F);
VectorF VectorF::s_One(1.0F, 1.0F, 1.0F);

VectorF VectorF::s_Back(0.0F, 0.0F, 1.0F);
//VectorF VectorF::s_Back(0.0f, 1.0f, 0.0f);
VectorF VectorF::s_Forward(0.0F, 0.0F, -1.0F);
//VectorF VectorF::s_Forward(0.0f, 1.0f, 0.0f);
VectorF VectorF::s_Left(-1.0F, 0.0F, 0.0F);
VectorF VectorF::s_Right(1.0F, 0.0F, 0.0F);

VectorF VectorF::s_Down(0.0F, -1.0F, 0.0F);
//VectorF VectorF::s_Down(0.0f, 0.0f, -1.0f);
VectorF VectorF::s_Up(0.0F, 1.0F, 0.0F);
//VectorF VectorF::s_Up(0.0f, 0.0f, 1.0f);


/**
 * implementation
 */
float VectorF::GetDotProduct(const VectorF &Lhs, const VectorF &Rhs)
{
	return Lhs.GetDotProduct(Rhs);
}


/**
 * implementation
 */
VectorF VectorF::GetCrossProduct(const VectorF &Lhs, const VectorF &Rhs)
{
	return Lhs.GetCrossProduct(Rhs);
}


/**
 * implementation
 */
VectorF VectorF::GetNormalizedVector(const VectorF &Lhs)
{
	return Lhs.GetNormalizedVector();
}

/**
 * implementation
 */
float VectorF::GetDistanceBetweenPoints(const VectorF &Lhs, const VectorF &Rhs)
{
	return 0.0f;
}


/**
 * implementation
 */
VectorF VectorF::Lerp(const VectorF &Lhs, const VectorF &Rhs, float Time)
{
	Lhs.Lerp(Rhs, Time);
}


/**
 * implementation
 */
VectorF VectorF::Slerp(const VectorF &Lhs, const VectorF &Rhs, float Time)
{
	Lhs.Slerp(Rhs, Time);
}


/**
 * implementation
 */
VectorF VectorF::GetMin(const VectorF &Lhs)
{
	return
	{

	};
}


/**
 * implementation
 */
VectorF VectorF::GetMax(const VectorF &Lhs)
{
	return
	{

	};
}


/**
 * implementation
 */
VectorF VectorF::GetAbs(const VectorF &Lhs)
{
	return
	{

	};
}


/**
 * implementation
 */
VectorF::VectorF() noexcept 
{
}


/**
 * implementation
 */
VectorF::VectorF(float X, float Y, float Z) noexcept :
	X(X), Y(Y), Z(Z)
{
}


/**
 * implementation
 */
float VectorF::GetMagnitude() const
{
	return MathF::Sqrt(GetMagnitudeSquared());
}


/**
 * implementation
 */
float VectorF::GetMagnitudeSquared() const
{
	return (X * X) + (Y * Y) + (Z * Z);
}


/**
 * implementation
 */
void VectorF::Set(float X, float Y, float Z) noexcept
{
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}


/**
 * implementation
 */
VectorF VectorF::Rotate(AngleF Angle, const VectorF &Axis)
{
	auto Q = QuaternionF::CreateFromAxisAngle(Axis, Angle);
	auto Conjugate = Q.GetConjugate();

	Q *= *this;
	Q *= Conjugate;
	
	return
	{
		Q.X,
		Q.Y,
		Q.Z
	};
}


/**
 * implementation
 */
VectorF VectorF::Rotate(const QuaternionF &Rotation)
{
	auto Q = Rotation;
	auto Conjugate = Rotation.GetConjugate();
	
	Q *= *this;
	Q *= Conjugate;

	return
	{
		Q.X,
		Q.Y,
		Q.Z
	};
}


/**
 * implementation
 */
float VectorF::GetDotProduct(const VectorF &Other) const
{
	return (X * Other.X) + (Y * Other.Y) + (Z * Other.Z);
}


/**
 * implementation
 */
VectorF VectorF::GetCrossProduct(const VectorF &Other) const
{
	return
	{
		Y * Other.Z - Z * Other.Y,
		Z * Other.X - X * Other.Z,
		X * Other.Y - Y * Other.X
	};
}


/**
 * implementation
 */
VectorF VectorF::GetNormalizedVector() const
{
	float magnitude = GetMagnitude();
	return
	{
		X / magnitude,
		Y / magnitude,
		Z / magnitude
	};
}


/**
 * implementation
 */
void VectorF::Normalize()
{
	float magnitude = GetMagnitude();

	X /= magnitude;
	Y /= magnitude;
	Z /= magnitude;
}


/**
 * implementation
 */
VectorF VectorF::Lerp(const VectorF &Other, float Time) const
{
	return
	{

	};
}


/**
 * implementation
 */
VectorF VectorF::Slerp(const VectorF &Other, float Time) const
{
	return
	{

	};
}


/**
 * implementation
 */
float &VectorF::operator[](std::int32_t i)
{
	switch (i)
	{
	case 0: return X;
	case 1: return Y;
	case 2: return Z;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
const float VectorF::operator[](std::int32_t i) const
{
	switch (i)
	{
	case 0: return X;
	case 1: return Y;
	case 2: return Z;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
VectorF &VectorF::operator!()
{
	X = !X;
	Y = !Y;
	Z = !Z;

	return *this;
}


/**
 * implementation
 */
bool VectorF::operator==(const VectorF &Rhs)
{
	return
		X == Rhs.X &&
		Y == Rhs.Y &&
		Z == Rhs.Z;
}


/**
 * implementation
 */
bool VectorF::operator!=(const VectorF &Rhs)
{
	return !(*this == Rhs);
}


/**
 * implementation
 */
VectorF &VectorF::operator+=(const VectorF &Rhs)
{
	X += Rhs.X;
	Y += Rhs.Y;
	Z += Rhs.Z;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator+=(float Rhs)
{
	X += Rhs;
	Y += Rhs;
	Z += Rhs;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator-=(const VectorF &Rhs)
{
	X -= Rhs.X;
	Y -= Rhs.Y;
	Z -= Rhs.Z;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator-=(float Rhs)
{
	X -= Rhs;
	Y -= Rhs;
	Z -= Rhs;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator*=(const VectorF &Rhs)
{
	X *= Rhs.X;
	Y *= Rhs.Y;
	Z *= Rhs.Z;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator*=(float Rhs)
{
	X *= Rhs;
	Y *= Rhs;
	Z *= Rhs;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator/=(const VectorF &Rhs)
{
	X /= Rhs.X;
	Y /= Rhs.Y;
	Z /= Rhs.Z;

	return *this;
}


/**
 * implementation
 */
VectorF &VectorF::operator/=(float Rhs)
{
	X /= Rhs;
	Y /= Rhs;
	Z /= Rhs;
		
	return *this;
}


/**
 * implementation
 */
const char *VectorF::ToString() const
{
	return "";
}


namespace Engine
{
	/**
	 * implementation
	 */
	VectorF operator+(VectorF Lhs, const VectorF &Rhs)
	{
		Lhs += Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator+(VectorF Lhs, float Rhs)
	{
		Lhs += Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator-(VectorF Lhs, const VectorF &Rhs)
	{
		Lhs -= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator-(VectorF Lhs, float Rhs)
	{
		Lhs -= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator*(VectorF Lhs, const VectorF &Rhs)
	{
		Lhs *= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator*(VectorF Lhs, float Rhs)
	{
		Lhs *= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator/(VectorF Lhs, const VectorF &Rhs)
	{
		Lhs *= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator/(VectorF Lhs, float Rhs)
	{
		Lhs /= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	bool operator==(const VectorF &Lhs, const VectorF &Rhs)
	{
		return Lhs == Rhs;
	}


	/**
	 * implementation
	 */
	bool operator!=(const VectorF &Lhs, const VectorF &Rhs)
	{
		return Lhs != Rhs;
	}
}
