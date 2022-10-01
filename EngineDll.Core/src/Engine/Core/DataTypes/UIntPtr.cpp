
#include "pch.h"
#include "Engine/Core/DataTypes/UIntPtr.h"

using namespace Engine;


/**
 * implementation
 */
UIntPtr::UIntPtr() noexcept
{
}


/**
 * implementation
 */
UIntPtr::UIntPtr(T *Address) noexcept
	: m_Tp(Address)
{
}


/**
 * implementation
 */
UIntPtr::UIntPtr(const UIntPtr &Other)
{
}


/**
 * implementation
 */
UIntPtr::UIntPtr(UIntPtr &&Other) noexcept
{
	std::swap(Other.m_Tp, m_Tp);
}


/**
 * implementation
 */
UIntPtr::~UIntPtr()
{
}


/**
 * implementation
 */
UIntPtr &UIntPtr::operator=(const UIntPtr &Other)
{
	return *this;
}


/**
 * implementation
 */
UIntPtr &UIntPtr::operator=(UIntPtr &&Other) noexcept
{
	std::swap(Other.m_Tp, m_Tp);

	return *this;
}
