
#include "pch.h"
#include "Engine/Math/EulerAngleF.h"

using namespace Engine;


/**
 * implementation
 */
EulerAngleF::EulerAngleF() noexcept
{
}


/**
 * implementation
 */
EulerAngleF::EulerAngleF(float Direction) noexcept
	: Direction(Direction)
{
}


/**
 * implementation
 */
void EulerAngleF::Set(float Direction)
{
	this->Direction = Direction;
}

namespace Engine
{
	/**
	 * implementation
	 */
	bool operator==(const EulerAngleF &Lhs, const EulerAngleF &Rhs)
	{
		return Lhs.Direction == Rhs.Direction;
	}


	/**
	 * implementation
	 */
	bool operator==(float Lhs, const EulerAngleF &Rhs)
	{
		return Lhs == Rhs.Direction;
	}


	/**
	 * implementation
	 */
	bool operator==(const EulerAngleF &Lhs, float Rhs)
	{
		return Lhs.Direction == Rhs;
	}


	/**
	 * implementation
	 */
	bool operator!=(const EulerAngleF &Lhs, const EulerAngleF &Rhs)
	{
		return !(Lhs == Rhs);
	}


	/**
 * implementation
 */
	bool operator!=(float Lhs, const EulerAngleF &Rhs)
	{
		return !(Lhs == Rhs.Direction);
	}


	/**
	 * implementation
	 */
	bool operator!=(const EulerAngleF &Lhs, float Rhs)
	{
		return !(Lhs.Direction == Rhs);
	}
}

