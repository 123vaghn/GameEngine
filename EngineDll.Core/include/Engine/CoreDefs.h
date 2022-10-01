
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


#pragma once

#include "CompilerDefs.h"

#define BASE ____super
#define ENGINE_DEF_INHERITED_TYPE(x) typedef x BASE;

#ifdef UNICDOE
#endif

#define gCSTR(x) x.c_str()
#define gNT_(x) x L"\0"

#define ENGINE_UNSIGNED_INT8 unsigned ENGINE_INT8	
#define ENGINE_UNSIGNED_INT16 unsigned ENGINE_INT16
#define ENGINE_UNSIGNED_INT32 unsigned ENGINE_INT32
#define ENGINE_UNSIGNED_INT64 unsigned ENGINE_INT64

#ifndef E_LOBYTE
	#define E_LOBYTE(w) ((WORD)(WORD)(w))
	#define E_HIBYTE(w) ((WORD)(((WORD)(w) >> 8) & 0xFF))
#endif

#ifndef E_LOWORD
	#define E_LOWORD(l) ((WORD)(DWORD)(l))
	#define E_HIWORD(l) ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))
#endif

#define get_ptr(x) x.get()
#define get_ref(x)

namespace Engine
{
	typedef signed char int8;
	typedef unsigned char uint8;
	typedef signed short int16;
	typedef unsigned short uint16;
	typedef signed int int32;
	typedef unsigned int uint32;
	typedef signed long long int64;
	typedef unsigned long long uint64;
}
