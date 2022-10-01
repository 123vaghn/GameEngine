
#include "pch.h"
#include "Engine/Math/AngleF.h"

using namespace Engine;


/**
 * implementation
 */
AngleF::AngleF() noexcept
{
}


/**
 * implementation
 */
AngleF::AngleF(float Direction) noexcept
	: Direction(Direction)
{
}


/**
 * implementation
 */
void AngleF::Set(float Direction)
{
	this->Direction = Direction;
}

namespace Engine
{
	/**
	 * implementation
	 */
	bool operator==(const AngleF &Lhs, const AngleF &Rhs)
	{
		return Lhs.Direction == Rhs.Direction;
	}


	/**
	 * implementation
	 */
	bool operator==(float Lhs, const AngleF &Rhs)
	{
		return Lhs == Rhs.Direction;
	}


	/**
	 * implementation
	 */
	bool operator==(const AngleF &Lhs, float Rhs)
	{
		return Lhs.Direction == Rhs;
	}


	/**
	 * implementation
	 */
	bool operator!=(const AngleF &Lhs, const AngleF &Rhs)
	{
		return !(Lhs == Rhs);
	}


	/**
 * implementation
 */
	bool operator!=(float Lhs, const AngleF &Rhs)
	{
		return !(Lhs == Rhs.Direction);
	}


	/**
	 * implementation
	 */
	bool operator!=(const AngleF &Lhs, float Rhs)
	{
		return !(Lhs.Direction == Rhs);
	}
}

