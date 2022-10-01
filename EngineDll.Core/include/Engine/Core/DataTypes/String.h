
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

#include "Engine/CoreDefs.h"
#include "Engine/Core/DataTypes/Char.h"

namespace Engine
{
	class DLL_CLASS String
	{
	public:
		using T = Char; // Do not use. It is deprecated.

	public:
		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		String() noexcept;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Chars"></param>
		/// <param name="Capacity"></param>
		String(const wchar_t *const Chars, unsigned int Capacity = 0);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="Capacity"></param>
		explicit String(unsigned int Capacity);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Rhs"></param>
		String(const String &Rhs);
		
		/// <summary>
		/// 
		/// </summary>
		/// <param name="Rhs"></param>
		/// <returns></returns>
		String(String &&Rhs) noexcept;

		~String();

		void Resize(unsigned int Size);

		unsigned int GetSize() const;
		unsigned int GetCharacterCount() const;
	
		void Swap(String &Other);

		Char &operator[](int i);
		const Char operator[](int i) const;

		String &operator=(const String &Rhs);
		String &operator=(String &&Rhs) noexcept;
		
		bool operator==(const String &Rhs);
		bool operator!=(const String &Rhs);

		operator Char *();
		operator const Char *() const;

	private:
		unsigned int m_Size;
		unsigned int m_Capacity;
		unsigned int m_Pos;

		Char *m_Tp;
	};
}
