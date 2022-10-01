
#include "pch.h"
#include "Engine/Core/DataTypes/IntPtr.h"

using namespace Engine;


/**
 * implementation
 */
IntPtr::IntPtr() noexcept
{
}


/**
 * implementation
 */
IntPtr::IntPtr(T *Address) noexcept
	: m_Tp(Address)
{
}


/**
 * implementation
 */
IntPtr::IntPtr(const IntPtr &Other)
{
}


/**
 * implementation
 */
IntPtr::IntPtr(IntPtr &&Other) noexcept
{
	std::swap(Other.m_Tp, m_Tp);
}


/**
 * implementation
 */
IntPtr::~IntPtr()
{
}


/**
 * implementation
 */
IntPtr &IntPtr::operator=(const IntPtr &Other)
{
	return *this;
}


/**
 * implementation
 */
IntPtr &IntPtr::operator=(IntPtr &&Other) noexcept
{
	std::swap(Other.m_Tp, m_Tp);

	return *this;
}
