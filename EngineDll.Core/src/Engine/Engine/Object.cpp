
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
#include "Engine/Engine/Object.h"

using namespace Engine;


/**
 * implementation
 */
Object::Object(const char *Name)
	: m_Name(Name)
{
}


/**
 * implementation
 */
Object::~Object()
{
}


/**
 * implementation
 */
const char *Object::ToString() const
{
	return "";
}
