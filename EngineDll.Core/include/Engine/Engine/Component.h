#pragma once

#include "Engine/Engine/Actor.h"

#ifndef TO_STRING
	#define TO_STRING(x) #x
#endif

namespace Engine
{
	class Actor;

	class DLL_CLASS Component : public Object
	{
		friend class Actor;
	
	public:
		static const size_t ClassType;
		
		Component();
		Component(const Component &Other);
		Component(Component &&Other) noexcept;

		virtual ~Component();
	
		virtual bool IsClassType(const size_t ClassType) const;

		virtual void Tick();
		virtual void Render();

		template<typename T>
		T &GetComponent() const
		{
			return GetGameObject()->GetComponent<T>();
		}

		Transform &GetTransform() const;

		Component &operator=(const Component &Other);
		Component &operator=(Component &&Other) noexcept;

	protected:
		Actor *GetGameObject() const;

	private:
		mutable Actor *m_Owner = nullptr;
	};
}


