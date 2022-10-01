
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

#if __cplusplus > 201701L
	#if __cplusplus == 201703L
	#endif
#endif

#ifndef NULL
	#if defined(__cplusplus)
		#define NULL 0
	#else
		#define NULL ((void*)0)
	#endif
#endif

#ifndef ENGINE_USING_FALLBACK_COMPILER
	#ifdef DLL_BUILD
		#define DLL_CLASS __declspec(dllexport)
	#else
		#define DLL_CLASS __declspec(dllimport)
	#endif
#endif

#define DLL_FUNC DLL_CLASS

#define ENGINEAPI __stdcall
#define CAPI __cdecl

#ifndef DEPRECATED
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define DEPRECATED __declspec(deprecated)
	#else
		#define DEPRECATED 
	#endif
#endif

#ifndef UNUSED
	#define UNSUED
#endif

#ifndef NORETURN
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define NORETURN __declspec(noreturn)
	#else
		#define NORETURN 
	#endif
#endif

#ifndef NOTHROW 
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define NOTHROW __declspec(nothrow)
	#else
		#define NOTHROW 
	#endif
#endif

#ifndef NOINLINE
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define NOINLINE __declspec(noinline)
	#else
		#define NORETURN
	#endif
#endif

#ifndef INLINE 
	#ifdef _MSC_VER
		#define INLINE __inline
	#else
		#define INLINE inline
	#endif
#endif

#ifndef FORCEINLINE 
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define FORCEINLINE __forceinline
	#else
		#define FORCEINLINE
	#endif
#endif

#ifndef ALIGN
	#ifndef ENGINE_USING_FALLBACK_COMPILER
		#define ALIGN(x) __declspec(align(x))
	#else
		#define ALIGN(x) 
	#endif
#endif

#ifndef RESTRICT
	#define RESTRICT __restrict
#endif

