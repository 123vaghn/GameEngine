
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
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Exception.h"
#include "Engine/Rectangle.h"

using namespace Engine;


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateTranslation(const VectorF &Translation)
{
	return
	{
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		Translation.X,
		Translation.Y,
		Translation.Z,
		1
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateRotation(const QuaternionF &Rotation)
{
	float W = Rotation.W;
	float X = Rotation.X;
	float Y = Rotation.Y;
	float Z = Rotation.Z;

	float XX = X * (2.0f * X);
	float YY = Y * (2.0f * Y);
	float ZZ = Z * (2.0f * Z);
	float XY = X * (2.0f * Y);
	float XZ = X * (2.0f * Z);
	float YZ = Y * (2.0f * Z);
	float WX = W * (2.0f * X);
	float WY = W * (2.0f * Y);
	float WZ = W * (2.0f * Z);

	return
	{
		1.0f - (YY + ZZ), 
		XY + WZ,	
		XZ - WY,	
		0,
		XY - WZ,	
		1.0f - (XX + ZZ), 
		YZ + WX,	
		0,
		XZ + WY,
		YZ - WX,
		1.0f - (XX + YY),
		0,
		0,
		0,
		0,
		1.0f
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateRotation(const VectorF &Right, const VectorF &Up, const VectorF &Forward)
{
	return
	{
		Right.X,
		Up.X,
		Forward.X,
		0,
		Right.Y,
		Up.Y,
		Forward.Y,
		0,
		Right.Z,
		Up.Z,
		Forward.Z,
		0,
		0,
		0,
		0,
		1,
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateScale(const VectorF &Scale)
{
	return
	{
		Scale.X,
		0,
		0,
		0,
		0,
		Scale.Y,
		0,
		0,
		0,
		0,
		Scale.Z,
		0,
		0,
		0,
		0,
		1
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateTRS(const VectorF &Translation, const QuaternionF &Rotation, const VectorF &Scale)
{
	return CreateTranslation(Translation) * Rotation.ToRotationMatrix() * CreateScale(Scale);
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreatePerspectiveProjection(float FOV, float AspectRatio, float zNear, float zFar)
{
	float radians = (float)(MathF::Tan((float)MathF::DegreesToRadians(FOV) / 2.0f));
	float h = (float)MathF::Cos(radians) / (float)MathF::Sin(radians);
	float w = h * AspectRatio;

	return
	{
		w,
		0,
		0,
		0,
		0,
		h,
		0,
		0,
		0,
		0,
		-(zFar + zNear) / (zFar - zNear),
		-1.0f,
		0,
		0,
		-(2.0f * zFar * zNear) / (zFar - zNear),
		0
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreatePerspectiveProjection(float FOV, float Width, float Height, float zNear, float zFar)
{
	float radians = (float)(MathF::Tan((float)MathF::DegreesToRadians(FOV) / 2.0f));
	float h = (float)MathF::Cos(radians) / (float)MathF::Sin(radians);
	float w = h * Height / Width;

	return
	{
		w,
		0,
		0,
		0,
		0,
		h,
		0,
		0,
		0,
		0,
		-(zFar + zNear) / (zFar - zNear),
		-1.0f,
		0,
		0,
		-(2.0f * zFar * zNear) / (zFar - zNear),
		0
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreatePerspectiveProjection(float FOV, const Rectangle &Area, float zNear, float zFar)
{
	float Width = Area.Right - Area.Left;
	float Height = Area.Bottom - Area.Top;

	float radians = (float)(MathF::Tan((float)MathF::DegreesToRadians(FOV) / 2.0f));
	float h = (float)MathF::Cos(radians) / (float)MathF::Sin(radians);
	float w = h * Height / Width;

	return
	{
		w,
		0,
		0,
		0,
		0,
		h,
		0,
		0,
		0,
		0,
		-(zFar + zNear) / (zFar - zNear),
		-1.0f,
		0,
		0,
		-(2.0f * zFar * zNear) / (zFar - zNear),
		0
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateOrthographicProjection(float Width, float Height, float zNear, float zFar)
{
	return
	{
		2.0f / Width,
		0,
		0,
		0,
		0,
		2.0f / Height,
		0, 
		0,
		0,
		0,
		1.0f / (zNear - zFar),
		0,
		0,
		0,
		zNear / (zNear - zFar),
		1.0
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateOrthographicProjection(const Rectangle &Area, float zNear, float zFar)
{
	float Width = Area.Right - Area.Left;
	float Height = Area.Bottom - Area.Top;

	return
	{
		2.0f / Width,
		0,
		0,
		0,
		0,
		2.0f / Height,
		0,
		0,
		0,
		0,
		1.0f / (zNear - zFar),
		0,
		(Area.Right + Area.Left) / Width,
		(Area.Top + Area.Bottom) / Height,
		zNear / (zNear - zFar),
		1.0
	};
}


/**
 *implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateLookAt(const VectorF &Eye, const VectorF &Center, const VectorF &Up)
{
	return
	{
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1
	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::CreateFrustum(const Rectangle &Area, float zNear, float zFar)
{
	return
	{
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1
	};
}


/**
 * implementation
 */
const Matrix4Fx4F &Matrix4Fx4F::GetIdentityMatrix4Fx4F()
{
	static Matrix4Fx4F matrix =
	{
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1,
		0,
		0,
		0,
		0,
		1
	};

	return matrix;
}


/**
 * implementation
 */
const Matrix4Fx4F &Matrix4Fx4F::GetZeroMatrix4Fx4F()
{
	static Matrix4Fx4F matrix =
	{
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};

	return matrix;
}


/**
 * implementation
 */
Matrix4Fx4F::Matrix4Fx4F() noexcept
{
}


/**
 * implementation
 */
Matrix4Fx4F::Matrix4Fx4F(const PlaneF &C0, const PlaneF &C1, const PlaneF &C2, const PlaneF &C3) noexcept
	: C0R0{ C0.X },
	  C0R1{ C0.Y },
	  C0R2{ C0.Z },
	  C0R3{ C0.W },
	  C1R0{ C1.X },
	  C1R1{ C1.Y },
	  C1R2{ C1.Z },
	  C1R3{ C1.W },
	  C2R0{ C2.X },
	  C2R1{ C2.Y },
	  C2R2{ C2.Z },
	  C2R3{ C2.W },
	  C3R0{ C3.X },
	  C3R1{ C3.Y },
	  C3R2{ C3.Z },
	  C3R3{ C3.W }
{
}


/**
 * implementation
 */
Matrix4Fx4F::Matrix4Fx4F(float C0R0, float C0R1, float C0R2, float C0R3, float C1R0, float C1R1, float C1R2, float C1R3, float C2R0, float C2R1, float C2R2, float C2R3, float C3R0, float C3R1, float C3R2, float C3R3) noexcept
	: C0R0{ C0R0 },
	  C0R1{ C0R1 },
	  C0R2{ C0R2 },
	  C0R3{ C0R3 },
	  C1R0{ C1R0 },
	  C1R1{ C1R1 },
	  C1R2{ C1R2 },
	  C1R3{ C1R3 },
	  C2R0{ C2R0 },
	  C2R1{ C2R1 },
	  C2R2{ C2R2 },
	  C2R3{ C2R3 },
	  C3R0{ C3R0 },
	  C3R1{ C3R1 },
	  C3R2{ C3R2 },
	  C3R3{ C3R3 }
{
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::Determinant() const
{
	float SF00 = C2R2 * C3R3 - C3R2 * C2R3;
	float SF01 = C2R1 * C3R3 - C3R1 * C2R3;
	float SF02 = C2R1 * C3R2 - C3R1 * C2R2;
	float SF03 = C2R0 * C3R3 - C3R0 * C2R3;
	float SF04 = C2R0 * C3R2 - C3R0 * C2R2;
	float SF05 = C2R0 * C3R1 - C3R0 * C2R1;

	return
	{

	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::Inverse() const
{
	return
	{

	};
}


/**
 * implementation
 */
Matrix4Fx4F Matrix4Fx4F::Transpose() const
{
	return
	{
		C0R0,
		C1R0,
		C2R0,
		C3R0,
		C0R1,
		C1R1,
		C2R1,
		C3R1,
		C0R2,
		C1R2,
		C2R2,
		C3R2,
		C0R3,
		C1R3,
		C2R3,
		C3R3
	};
}


/**
 * implementation
 */
PlaneF Matrix4Fx4F::GetColumn(uint32_t i) const
{
	switch (i)
	{
	case 0: return { C0R0, C0R1, C0R2, C3R3 };
	case 1: return { C1R0, C1R1, C1R2, C3R3 };
	case 2: return { C2R0, C2R1, C2R2, C3R3 };
	case 3: return { C3R0, C3R1, C3R2, C3R3 };
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
void Matrix4Fx4F::SetColumn(uint32_t i, const PlaneF &Column)
{
	switch (i)
	{
	case 0:
		C0R0 = Column.X;
		C0R1 = Column.Y;
		C0R2 = Column.Z;
		C0R3 = Column.W;
		break;
	case 1:
		C1R0 = Column.X;
		C1R1 = Column.Y;
		C1R2 = Column.Z;
		C1R3 = Column.W;
		break;
	case 2:
		C2R0 = Column.X;
		C2R1 = Column.Y;
		C2R2 = Column.Z;
		C2R3 = Column.W;
		break;
	case 3:
		C3R0 = Column.X;
		C3R1 = Column.Y;
		C3R2 = Column.Z;
		C3R3 = Column.W;
		break;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
PlaneF Matrix4Fx4F::GetRow(uint32_t i) const
{
	switch (i)
	{
	case 0: return { C0R0, C1R0, C2R0, C3R0 };
	case 1: return { C0R1, C1R1, C2R1, C3R1 };
	case 2: return { C0R2, C1R2, C2R2, C3R2 };
	case 3: return { C0R3, C1R3, C2R3, C3R3 };
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
void Matrix4Fx4F::SetRow(uint32_t i, const PlaneF &Row)
{
	switch (i)
	{
	case 0:
		C0R0 = Row.X;
		C1R0 = Row.Y;
		C2R0 = Row.Z;
		C3R0 = Row.W;
		break;
	case 1: 
		C0R1 = Row.X;
		C1R1 = Row.Y;
		C2R1 = Row.Z;
		C3R1 = Row.W;
		break;
	case 2: 
		C0R2 = Row.X;
		C1R2 = Row.Y;
		C2R2 = Row.Z;
		C3R2 = Row.W;
		break;
	case 3: 
		C0R3 = Row.X;
		C1R3 = Row.Y;
		C2R3 = Row.Z;
		C3R3 = Row.W;
		break;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
VectorF Matrix4Fx4F::MultiplyPoint(const VectorF &Vector)
{
	return
	{
		C0R0 * Vector.X + C0R1 * Vector.Y + C0R2 * Vector.Z + C0R3,
		C1R0 * Vector.X + C1R1 * Vector.Y + C1R2 * Vector.Z + C1R3,
		C2R0 * Vector.X + C2R1 * Vector.Y + C2R2 * Vector.Z + C2R3,
	};
}


/**
 * implementation
 */
VectorF Matrix4Fx4F::MultiplyPointPerspectiveDivide(const VectorF &Vector)
{
	VectorF Point = MultiplyPoint(Vector);
	
	float W = C3R0 * Vector.X + C3R1 * Vector.Y + C3R2 * Vector.Z + C3R3;

	if (W != 0.0F)
	{
		W = (float)(1.0F / W);

		Point.X *= W;
		Point.Y *= W;
		Point.Z *= W;
	}

	return Point;
}


/**
 * implementation
 */
VectorF Matrix4Fx4F::MultiplyVector(const VectorF &Vector)
{
	return
	{
		C0R0 * Vector.X + C0R1 * Vector.Y + C0R2 * Vector.Z,
		C1R0 * Vector.X + C1R1 * Vector.Y + C1R2 * Vector.Z,
		C2R0 * Vector.X + C2R1 * Vector.Y + C2R2 * Vector.Z
	};
}


/**
 * implementation
 */
PlaneF Matrix4Fx4F::TransformPlane(const PlaneF &Plane)
{
	return
	{
	};
}


/**
 * implementation
 */
bool Matrix4Fx4F::IsIdentityMatrix4Fx4F() const
{
	return
		C0R0 == 1 &&
		C0R1 == 0 &&
		C0R2 == 0 &&
		C0R3 == 0 &&
		C1R0 == 0 &&
		C1R1 == 1 &&
		C1R2 == 0 &&
		C1R3 == 0 &&
		C2R0 == 0 &&
		C2R1 == 0 &&
		C2R2 == 1 &&
		C2R3 == 0 &&
		C3R0 == 0 &&
		C3R1 == 0 &&
		C3R2 == 0 &&
		C3R3 == 1;
}


/**
 * implementation
 */
float &Matrix4Fx4F::operator[](uint32_t i)
{
	switch (i)
	{
	case I_C0R0: return C0R0;
	case I_C0R1: return C0R1;
	case I_C0R2: return C0R2;
	case I_C0R3: return C0R3;
	case I_C1R0: return C1R0;
	case I_C1R1: return C1R1;
	case I_C1R2: return C1R2;
	case I_C1R3: return C1R3;
	case I_C2R0: return C2R0;
	case I_C2R1: return C2R1;
	case I_C2R2: return C2R2;
	case I_C2R3: return C2R3;
	case I_C3R0: return C3R0;
	case I_C3R1: return C3R1;
	case I_C3R2: return C3R2;
	case I_C3R3: return C3R3;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
const float Matrix4Fx4F::operator[](uint32_t i) const
{
	switch (i)
	{
	case I_C0R0: return C0R0;
	case I_C0R1: return C0R1;
	case I_C0R2: return C0R2;
	case I_C0R3: return C0R3;
	case I_C1R0: return C1R0;
	case I_C1R1: return C1R1;
	case I_C1R2: return C1R2;
	case I_C1R3: return C1R3;
	case I_C2R0: return C2R0;
	case I_C2R1: return C2R1;
	case I_C2R2: return C2R2;
	case I_C2R3: return C2R3;
	case I_C3R0: return C3R0;
	case I_C3R1: return C3R1;
	case I_C3R2: return C3R2;
	case I_C3R3: return C3R3;
	default:
		throw Exception();
	}
}


/**
 * implementation
 */
bool Matrix4Fx4F::operator==(const Matrix4Fx4F &Rhs)
{
	return
		C0R0 == Rhs.C0R0 &&
		C0R1 == Rhs.C0R1 &&
		C0R2 == Rhs.C0R2 &&
		C0R3 == Rhs.C0R3 &&
		C1R0 == Rhs.C1R0 &&
		C1R1 == Rhs.C1R1 &&
		C1R2 == Rhs.C1R2 &&
		C1R3 == Rhs.C1R3 &&
		C2R0 == Rhs.C2R0 &&
		C2R1 == Rhs.C2R1 &&
		C2R2 == Rhs.C2R2 &&
		C2R3 == Rhs.C2R3 &&
		C3R0 == Rhs.C3R0 &&
		C3R1 == Rhs.C3R1 &&
		C3R2 == Rhs.C3R2 &&
		C3R3 == Rhs.C3R3;
}


/**
 * implementation
 */
bool Matrix4Fx4F::operator!=(const Matrix4Fx4F &Rhs)
{
	return !(*this == Rhs);
}


/**
 * implementation
 */
Matrix4Fx4F &Matrix4Fx4F::operator*=(const Matrix4Fx4F &Rhs)
{
	return *this =
	{
		C0R0 * Rhs.C0R0 + C1R0 * Rhs.C0R1 + C2R0 * Rhs.C0R2 + C3R0 * Rhs.C0R3,
		C0R1 * Rhs.C0R0 + C1R1 * Rhs.C0R1 + C2R1 * Rhs.C0R2 + C3R1 * Rhs.C0R3,
		C0R2 * Rhs.C0R0 + C1R2 * Rhs.C0R1 + C2R2 * Rhs.C0R2 + C3R2 * Rhs.C0R3,
		C0R3 * Rhs.C0R0 + C1R3 * Rhs.C0R1 + C2R3 * Rhs.C0R2 + C3R3 * Rhs.C0R3,
		C0R0 * Rhs.C1R0 + C1R0 * Rhs.C1R1 + C2R0 * Rhs.C1R2 + C3R0 * Rhs.C1R3,
		C0R1 * Rhs.C1R0 + C1R1 * Rhs.C1R1 + C2R1 * Rhs.C1R2 + C3R1 * Rhs.C1R3,
		C0R2 * Rhs.C1R0 + C1R2 * Rhs.C1R1 + C2R2 * Rhs.C1R2 + C3R2 * Rhs.C1R3,
		C0R3 * Rhs.C1R0 + C1R3 * Rhs.C1R1 + C2R3 * Rhs.C1R2 + C3R3 * Rhs.C1R3,
		C0R0 * Rhs.C2R0 + C1R0 * Rhs.C2R1 + C2R0 * Rhs.C2R2 + C3R0 * Rhs.C2R3,
		C0R1 * Rhs.C2R0 + C1R1 * Rhs.C2R1 + C2R1 * Rhs.C2R2 + C3R1 * Rhs.C2R3,
		C0R2 * Rhs.C2R0 + C1R2 * Rhs.C2R1 + C2R2 * Rhs.C2R2 + C3R2 * Rhs.C2R3,
		C0R3 * Rhs.C2R0 + C1R3 * Rhs.C2R1 + C2R3 * Rhs.C2R2 + C3R3 * Rhs.C2R3,
		C0R0 * Rhs.C3R0 + C1R0 * Rhs.C3R1 + C2R0 * Rhs.C3R2 + C3R0 * Rhs.C3R3,
		C0R1 * Rhs.C3R0 + C1R1 * Rhs.C3R1 + C2R1 * Rhs.C3R2 + C3R1 * Rhs.C3R3,
		C0R2 * Rhs.C3R0 + C1R2 * Rhs.C3R1 + C2R2 * Rhs.C3R2 + C3R2 * Rhs.C3R3,
		C0R3 * Rhs.C3R0 + C1R3 * Rhs.C3R1 + C2R3 * Rhs.C3R2 + C3R3 * Rhs.C3R3
	};
}


/**
 * implementation
 */
PlaneF Matrix4Fx4F::operator*(const PlaneF &Rhs)
{
	return
	{

	};
}


/**
 * implementation
 */
std::string Matrix4Fx4F::ToString() const
{
	return "";
}


namespace Engine
{
	/**
	 * implementation
	 */
	Matrix4Fx4F operator*(Matrix4Fx4F Lhs, const Matrix4Fx4F &Rhs)
	{
		return (Lhs) *= Rhs;
	}

	
	/**
	 * implementation
	 */
	bool operator==(const Matrix4Fx4F &Lhs, const Matrix4Fx4F &Rhs)
	{
		return Lhs == Rhs;
	}


	/**
	 * implementation
	 */
	bool operator!=(const Matrix4Fx4F &Lhs, const Matrix4Fx4F &Rhs)
	{
		return Lhs != Rhs;
	}
}


