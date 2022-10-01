
#include "pch.h"
#include "Engine/Math/AngleF.h"
#include "Engine/Math/EulerAngleF.h"
#include "Engine/Math/Matrix4Fx4F.h"
#include "Engine/Math/PlaneF.h"
#include "Engine/Math/QuaternionF.h"
#include "Engine/Math/TransformF.h"
#include "Engine/Math/VectorF.h"
#include "Engine/Math/MathF.h"
#include "Engine/Exception.h"

using namespace Engine;

const float MathF::s_Epsilon = std::numeric_limits<float>::epsilon();
const float MathF::s_PI = 3.14159265358979;


/**
 * implementation
 */
float MathF::Abs(float x)
{
	return std::abs(x);
}


/**
 * implementation
 */
float MathF::Min(float x, float y)
{
	return std::fmin(x, y);
}


/**
 * implementation
 */
float MathF::Max(float x, float y)
{
	return std::fmax(x, y);
}


/**
 * implementation
 */
float MathF::PositiveDifference(float x, float y)
{
	return std::fdim(x, y);
}


/**
 * implementation
 */
float MathF::Nan(const char *&x)
{
	return std::nanf(x);
}


/**
 * implementation
 */
float MathF::Pow(float Base, std::int32_t Exponent)
{
	return std::pow(Base, Exponent);
}


/**
 * implementation
 */
float MathF::Pow(float Base, float Exponent)
{
	return std::pow(Base, Exponent);
}


/**
 * implementation
 */
float MathF::Exponent(float x)
{
	return std::exp(x);
}


/**
 * implementation
 */
float MathF::Exp2(float x)
{
	return std::exp(x);
}


/**
 * implementation
 */
float MathF::ExpM1(float x)
{
	return std::expm1(x);
}


/**
 * implementation
 */
float MathF::Log(float x)
{
	return std::log(x);
}


/**
 * implementation
 */
float MathF::Log10(float x)
{
	return std::log10(x);
}


/**
 * implementation
 */
float MathF::Log2(float x)
{
	return std::log2(x);
}


/**
 * implementation
 */
float MathF::Log1Plus(float x)
{
	return std::log1p(x);
}


/**
 * implementation
 */
float MathF::Sqrt(float x)
{
	return std::sqrt(x);
}


/**
 * implementation
 */
float MathF::Cbrt(float x)
{
	return std::cbrt(x);
}


/**
 * implementation
 */
float MathF::Hypotenuse(float x, float y)
{
	return std::hypot(x, y);
}


/**
 * implementation
 */
float MathF::Hypotenuse(float x, float y, float z)
{
	return std::hypot(x, y, z);
}


/**
 * implementation
 */
float MathF::Sin(float x)
{
	return std::sin(x);
}


/**
 * implementation
 */
float MathF::Cos(float x)
{
	return std::cos(x);
}


/**
 * implementation
 */
float MathF::Tan(float x)
{
	return std::tan(x);
}


/**
 * implementation
 */
float MathF::ASin(float x)
{
	return std::asin(x);
}


/**
 * implementation
 */
float MathF::ACos(float x)
{
	return std::acos(x);
}


/**
 * implementation
 */
float MathF::ATan(float x)
{
	return std::atan(x);
}


/**
 * implementation
 */
float MathF::ATan2(float x, float y)
{
	return std::atan2(x, y);
}


/**
 * implementation
 */
float MathF::Sinh(float x)
{
	return std::sinh(x);
}


/**
 * implementation
 */
float MathF::Cosh(float x)
{
	return std::cosh(x);
}


/**
 * implementation
 */
float MathF::Tanh(float x)
{
	return std::tanh(x);
}


/**
 * implementation
 */
float MathF::ASinh(float x)
{
	return std::asinh(x);
}


/**
 * implementation
 */
float MathF::ACosh(float x)
{
	return std::acosh(x);
}


/**
 * implementation
 */
float MathF::ATanh(float x)
{
	return std::atanh(x);
}


/**
 * implementation
 */
float MathF::Ceil(float x)
{
	return std::ceil(x);
}


/**
 * implementation
 */
float MathF::Floor(float x)
{
	return std::floor(x);
}


/**
 * implementation
 */
float MathF::Truncate(float x)
{
	return std::trunc(x);
}


/**
 * implementation
 */
float MathF::Round(float x, MathF::RoundingMode RoundingMode)
{
	int32_t std_round_mode;

	switch (RoundingMode)
	{
	case RoundingMode::Down:	std_round_mode = FE_DOWNWARD;	break;
	case RoundingMode::Nearest:	std_round_mode = FE_TONEAREST;	break;
	case RoundingMode::Zero:	std_round_mode = FE_TOWARDZERO;	break;
	case RoundingMode::Up:		std_round_mode = FE_UPWARD;		break;
	default:
		throw Exception();
	}

	std::fesetround(std_round_mode);

	return std::round(x);
}


/**
 * implementation
 */
float MathF::NearbyInt(float x, MathF::RoundingMode RoundingMode)
{
	int32_t std_round_mode;

	switch (RoundingMode)
	{
	case RoundingMode::Down:	std_round_mode = FE_DOWNWARD;	break;
	case RoundingMode::Nearest:	std_round_mode = FE_TONEAREST;	break;
	case RoundingMode::Zero:	std_round_mode = FE_TOWARDZERO;	break;
	case RoundingMode::Up:		std_round_mode = FE_UPWARD;		break;
	default:
		throw Exception();
	}

	std::fesetround(std_round_mode);

	return std::nearbyint(x);
}


/**
 * implementation
 */
float MathF::DecomposeExponentP2(float x, std::int32_t *result)
{
	return std::frexp(x, result);
}


/**
 * implementation
 */
float MathF::DecomposeFraction(float x, float *result)
{
	return std::modf(x, result);
}


 /**
 * implementation
 */
float MathF::Scale(float x, std::int32_t Exponent)
{
	return std::scalbln(x, Exponent);
}


/**
 * implementation
 */
float MathF::Scale(float x, int64_t Exponent)
{
	return std::scalbln(x, Exponent);
}


/**
 * implementation
 */
int32_t MathF::iLogb(float x)
{
	return std::ilogb(x);
}

/**
 * implementation
 */
float MathF::Logb(float x)
{
	return std::logb(x);
}


/**
 * implementation
 */
float MathF::CopySign(float Magnitude, float Sign)
{
	return std::copysign(Magnitude, Sign);
}


/**
 * implementation
 */
bool MathF::FloatType(float x)
{
	return std::fpclassify(x);
}


/**
 * implementation
 */
bool MathF::IsFinite(float x)
{
	return std::isinf(x);
}


/**
 * implementation
 */
bool MathF::IsInfinite(float x)
{
	return std::isinf(x);
}



/**
 * implementation
 */
bool MathF::IsNan(float x)
{
	return std::isnan(x);
}


/**
 * implementation
 */
bool MathF::IsNormal(float x)
{
	return std::isnormal(x);
}


/**
 * implementation
 */
bool MathF::Sign(float x)
{
	return std::signbit(x);
}


/**
 * implementation
 */
bool MathF::IsGreater(float x, float y)
{
	return std::isgreater(x, y);
}


/**
 * implementation
 */
bool MathF::IsGreaterEqual(float x, float y)
{
	return std::isgreaterequal(x, y);
}


/**
 * implementation
 */
bool MathF::IsLess(float x, float y)
{
	return std::isless(x, y);
}


/**
 * implementation
 */
bool MathF::IsLessEqual(float x, float y)
{
	return std::islessequal(x, y);
}


/**
 * implementation
 */
bool MathF::IsLessGreater(float x, float y)
{
	return std::islessgreater(x, y);
}


/**
 * implementation
 */
bool MathF::IsUnordered(float x, float y)
{
	return std::isunordered(x, y);
}


/**
 * implementation
 */
float MathF::DegreesToRadians(float Degrees)
{
	auto x = (float)(s_PI / 180.0);

	return Degrees * x;
}


/**
 * implementation
 */
float MathF::RadiansToDegrees(float Radians)
{
	auto x = (float)(s_PI * 180.0);
	
	return Radians / x;
}
