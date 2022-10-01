
#include "pch.h"
#include "Engine/Core/DataTypes/String.h"

using namespace Engine;


/**
 * implementation
 */ 
String::String() noexcept 
{
}


/**
 * implementation
 */ 
String::String(const wchar_t *const Chars, unsigned int Capacity)
	: m_Size(std::wcslen((Char::T *)Chars)), m_Capacity(Capacity > 0 ? Capacity : m_Size + 1), m_Pos(m_Size), m_Tp(new Char[m_Capacity])
{
	std::copy_n(Chars, m_Capacity, m_Tp);
}


/**
 * implementation
 */ 
String::String(unsigned int Capacity)
{
}


/**
 * implementation
 */ 
String::String(const String &Other) 
	: m_Size(Other.m_Size), m_Capacity(Other.m_Capacity), m_Pos(Other.m_Pos), m_Tp(new Char[m_Capacity])
{
	std::copy(Other.m_Tp, Other.m_Tp + m_Size, m_Tp);
}


/**
 * implementation
 */ 
String::String(String &&Other) noexcept :
	m_Size(Other.m_Size), m_Capacity(Other.m_Capacity), m_Pos(Other.m_Pos), m_Tp(Other.m_Tp)
{
	Other.m_Size = 0;
	Other.m_Capacity = 0;
	Other.m_Pos = 0;
	Other.m_Tp = nullptr;
}


/**
 * implementation
 */ 
String::~String()
{
	delete[] m_Tp;
}


/**
 * implementation
 */ 
void String::Resize(unsigned int Capacity)
{
	m_Capacity = Capacity;

	Char *Tp = new Char[Capacity];

	std::copy_n(m_Tp, m_Capacity, Tp);
	std::swap(m_Tp, Tp);

	delete[] Tp;
}


/**
 * implementation
 */ 
unsigned int String::GetCharacterCount() const
{
	return m_Size;
}


/**
 * implementation
 */
void String::Swap(String &Other)
{

}


/**
 * implementation
 */ 
Char &String::operator[](int i)
{
	m_Pos = i;

	return m_Tp[m_Pos];
}


/**
 * implementation
 */ 
const Char String::operator[](int i) const
{
	return m_Tp[i];
}


/**
 * implementation
 */ 
String &String::operator=(const String &Rhs)
{
	if (this != &Rhs)
	{
		m_Size = Rhs.m_Size;
		m_Capacity = Rhs.m_Capacity;
		m_Pos = Rhs.m_Pos;

		Char *Tp = new Char[m_Capacity];

		std::copy(Rhs.m_Tp, Rhs.m_Tp + m_Size, Tp);
		std::swap(m_Tp, Tp);

		delete[] Tp;
	}

	return *this;
}


/**
 * implementation
 */ 
String &String::operator=(String &&Rhs) noexcept
{
	if (this != &Rhs)
	{
		std::swap(Rhs.m_Size, m_Size);
		std::swap(Rhs.m_Capacity, m_Capacity);
		std::swap(Rhs.m_Pos, m_Pos);
		std::swap(Rhs.m_Tp, m_Tp);
	}

	return *this;
}


/**
 * implementation
 */
bool String::operator==(const String &Rhs)
{
}


/**
 * implementation
 */
bool String::operator!=(const String &Rhs)
{
	return !(*this == Rhs);
}


/**
 * implementation
 */ 
String::operator Char *()
{
	return m_Tp;
}


/**
 * implementation
 */ 
String::operator const Char *() const
{
	return m_Tp;
}
