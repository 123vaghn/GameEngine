#include "pch.h"
#include "Engine/Exception.h"

using namespace Engine;


/**
 * implementation
 */
Exception::Exception() : 
	Exception(gNT_(L""))
{
}


/**
 * implementation
 */
Exception::Exception(const String &Message) : 
	m_Message(Message)
{
}

/**
 * implementation
 */
const String &Exception::GetMessage() const
{
	return m_Message;
}
