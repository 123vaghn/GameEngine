
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
#include "Engine/Math/QuaternionF.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Exception.h"

using namespace Engine;


/**
 * implementation
 */
QuaternionF QuaternionF::CreateFromAxisAngle(const VectorF &Axis, AngleF Angle)
{
	Angle = MathF::DegreesToRadians(Angle);
	Angle *= 0.5F;

	float Sin = MathF::Sin(Angle);
	float Cos = MathF::Cos(Angle);
		
	return 
	{
		Cos,
		Axis.X * Sin,
		Axis.Y * Sin,
		Axis.Z * Sin
	};
}


/**
 * implementation
 */
QuaternionF QuaternionF::CreateFromRotationMatrix(const Matrix4Fx4F &RotationMatrix)
{
	return
	{
	};
}

/**
 * implementation
 */
QuaternionF QuaternionF::CreateFromEulerAngles(float X, float Y, float Z)
{
	return CreateFromEulerAngles({ X, Y, Z });
}


/**
 * implementation
 */
QuaternionF QuaternionF::CreateFromEulerAngles(const VectorF &EulerAngles)
{
	return
	{
	};
}


/**
 * implementation
 */
float QuaternionF::GetDotProduct(const QuaternionF &Lhs, const QuaternionF &Rhs)
{
	return (Lhs.W * Rhs.W) + (Lhs.X * Rhs.X) + (Lhs.Y * Rhs.Y) + (Lhs.Z * Rhs.Z);
}


/**
 * implementation
 */
const QuaternionF &QuaternionF::GetIdentityRotation()
{
	static QuaternionF rotation =
	{
		1.0,
		0.0,
		0.0,
		0.0
	};

	return rotation;
}


/**
 * implementation
 */
QuaternionF::QuaternionF() noexcept 
{
}


/**
 * implementation
 */
QuaternionF::QuaternionF(float W, float X, float Y, float Z) noexcept
	: W(W), X(X), Y(Y), Z(Z)
{
}


/**
 * implementation
 */
QuaternionF::QuaternionF(float W, const VectorF &XYZ)
	: W(W), X(XYZ.X), Y(XYZ.Y), Z(XYZ.Z)
{
	
}


/**
 * implementation
 */
float QuaternionF::GetMagnitude() const
{
	return MathF::Sqrt(GetMagnitudeSquared());
}


/**
 * implementation
 */
float QuaternionF::GetMagnitudeSquared() const
{
	return (W * W) + (X * X) + (Y * Y) + (Z * Z);
}


/**
 * implementation
 */
void QuaternionF::Set(float W, float X, float Y, float Z) noexcept
{
	this->W = W;
	this->X = X;
	this->Y = Y;
	this->Z = Z;
}


/**
 * implementation
 */
QuaternionF QuaternionF::GetConjugate() const
{
	return
	{
		 W,
		-X,
		-Y,
		-Z
	};;
}


/**
 * implementation
 */
QuaternionF QuaternionF::GetNormalizedRotation() const
{
	float magnitude = GetMagnitude();
	return
	{
		W / magnitude,
		X / magnitude,
		Y / magnitude,
		Z / magnitude
	};
}


/**
 * implementation
 */
void QuaternionF::Normalize()
{
	float magnitude = GetMagnitude();

	W /= magnitude;
	X /= magnitude;
	Y /= magnitude;
	Z /= magnitude;
}


/**
 * implementation
 */
Matrix4Fx4F QuaternionF::ToRotationMatrix() const
{
	float XX = X * X;
	float YY = Y * Y;
	float ZZ = Z * Z;
	float XY = X * Y;
	float XZ = X * Z;
	float YZ = Y * Z;
	float WX = W * X;
	float WY = W * Y;
	float WZ = W * Z;

	VectorF Right   = { 1.0F - 2.0F * (YY + ZZ),        2.0F * (XY - WZ),        2.0F * (XZ + WY) };
	VectorF Up      = {        2.0F * (XY + WZ), 1.0F - 2.0F * (XX + ZZ),        2.0F * (YZ - WX) };
	VectorF Forward = {        2.0F * (XZ - WY),        2.0F * (YZ + WX), 1.0F - 2.0F * (XX + YY) };

	return Matrix4Fx4F::CreateRotation(Right, Up, Forward);
}



/**
 * implementation
 */
VectorF QuaternionF::GetRight() const
{
	return VectorF(1.0F, 0.0F, 0.0F).Rotate(*this);
}


/**
 * implementation
 */
VectorF QuaternionF::GetUp() const
{
	return VectorF(0.0F, 1.0F, 0.0F).Rotate(*this);
}


/**
 * implementation
 */
VectorF QuaternionF::GetBack() const
{
	return VectorF(0.0F, 0.0F, 1.0F).Rotate(*this);
}


/**
 * implementation
 */
VectorF QuaternionF::GetLeft() const
{
	return VectorF(-1.0F, 0.0F, 0.0F).Rotate(*this);
}


/**
 * implementation
 */
VectorF QuaternionF::GetDown() const
{
	return VectorF(0.0F, -1.0F, 0.0F).Rotate(*this);
}


/**
 * implementation
 */
VectorF QuaternionF::GetForward() const
{
	return VectorF(0.0F, 0.0F, -1.0F).Rotate(*this);
}



/**
 * implementation
 */
float &QuaternionF::operator[](int32_t i)
{
	switch (i)
	{
	case 0: return W;
	case 1: return X;
	case 2: return Y;
	case 3: return Z;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
const float QuaternionF::operator[](int32_t i) const
{
	switch (i)
	{
	case 0: return W;
	case 1: return X;
	case 2: return Y;
	case 3: return Z;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
bool QuaternionF::operator==(const QuaternionF &Rhs)
{
	return
		W == Rhs.W &&
		X == Rhs.X &&
		Y == Rhs.Y &&
		Z == Rhs.Z;
}


/**
 * implementation
 */
bool QuaternionF::operator!=(const QuaternionF &Rhs)
{
	return !(*this == Rhs);
}


/**
 * implementation
 */
QuaternionF &QuaternionF::operator*=(const QuaternionF &Rhs)
{
	//return *this =
	//{
	//	W * Rhs.W - X * Rhs.X - Y * Rhs.Y - Z * Rhs.Z,
	//	X * Rhs.W + W * Rhs.X + Y * Rhs.Z - Z * Rhs.Y,
	//	Y * Rhs.W + W * Rhs.Y + Z * Rhs.X - X * Rhs.Z,
	//	Z * Rhs.W + W * Rhs.Z + X * Rhs.Y - Y * Rhs.X
	//};

	return *this =
	{
		W * Rhs.W - X * Rhs.X - Y * Rhs.Y - Z * Rhs.Z,
		W * Rhs.X + X * Rhs.W + Y * Rhs.Z - Z * Rhs.Y,
		W * Rhs.Y + Y * Rhs.W + Z * Rhs.X - X * Rhs.Z,
		W * Rhs.Z + Z * Rhs.W + X * Rhs.Y - Y * Rhs.X
	};
}


/**
 * implementation
 */
QuaternionF &QuaternionF::operator*=(const VectorF &Rhs) 
{
	/**
	 * Credits for the general algorithm: 
	 * https://github.com/BennyQBD/3DGameEngine/blob/225fa8baf6637756ba03ccbc0444bf7751d87dbb/src/com/base/engine/core/Quaternion.java#L77
	 * 
	 * Turns out, I ended up needing a way to do this kind of multiplication, and I couldn't even read many sources 
	 * online, *especially* even GLM of all things.
	 * 
	 * 
	 * README
	 * 
	 * In various places, I've used the above person's code as an example of how to do various things. I'll place 
	 * credit markers where credit is due. If I forget, then my apologies. Just alert me if it's something I should 
	 * truly fix, because I primarily want to get something working before I place *any* comments all over the 
	 * code-base, but I'd also prefer that those who have written code that I've observed should get the credit and
	 * recognition they actually deserve.
	 * 
	 * The same goes for any other sources I've used as examples.
	 */
	return *this =
	{
		-X * Rhs.X - Y * Rhs.Y - Z * Rhs.Z,
		 W * Rhs.X + Y * Rhs.Z - Z * Rhs.Y,
		 W * Rhs.Y + Z * Rhs.X - X * Rhs.Z,
		 W * Rhs.Z + X * Rhs.Y - Y * Rhs.X
	};
}



/**
 * implementation
 */
const char *QuaternionF::ToString() const
{
	return "";
}


namespace Engine
{
	/**
	 * implementation
	 */
	QuaternionF operator*(QuaternionF Lhs, const QuaternionF &Rhs)
	{
		Lhs *= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	QuaternionF operator*(QuaternionF Lhs, const VectorF &Rhs)
	{
		Lhs *= Rhs;
		return Lhs;
	}


	/**
	 * implementation
	 */
	VectorF operator*(const QuaternionF &Lhs, const VectorF &Rhs)
	{
		float XX = Lhs.X * Lhs.X;
		float YY = Lhs.Y * Lhs.Y;
		float ZZ = Lhs.Z * Lhs.Z;
		float XY = Lhs.X * Lhs.Y;
		float XZ = Lhs.X * Lhs.Z;
		float YZ = Lhs.Y * Lhs.Z;
		float WY = Lhs.W * Lhs.Y;
		float WX = Lhs.W * Lhs.X;
		float WZ = Lhs.W * Lhs.Z;
	
		return
		{
			1.0F - 2.0F * (YY + ZZ) * Rhs.X +        2.0F * (XY - WZ) * Rhs.Y +        2.0F * (XZ + WY) * Rhs.Z,
				   2.0F * (XY + WZ) * Rhs.X + 1.0F - 2.0F * (XX + ZZ) * Rhs.Y +        2.0F * (YZ - WX) * Rhs.Z,
				   2.0F * (XZ - WY) * Rhs.X +        2.0F * (YZ + WX) * Rhs.Y + 1.0F - 2.0F * (XX + YY) * Rhs.Z
		};
	}


	/**
	 * implementation
	 */
	bool operator==(const QuaternionF &Lhs, const QuaternionF &Rhs)
	{
		return Lhs == Rhs;
	}


	/**
	 * implementation
	 */
	bool operator!=(const QuaternionF &Lhs, const QuaternionF &Rhs)
	{
		return Lhs != Rhs;
	}
}

