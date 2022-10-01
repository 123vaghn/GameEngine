#pragma once

#include "Engine/Engine/Transform.h"
#include "Engine/Exception.h"

#include <memory>
#include <vector>

namespace Engine
{
	class Component;
	
	class DLL_CLASS Actor : public Object
	{
		friend class Component;

	public:
		Actor(const char *Name = "");

		void AddChild(Actor &Child);
		
		template<typename T>
		void AddComponent()
		{
			std::shared_ptr<T> ComponentRef;

			if ((ComponentRef = std::dynamic_pointer_cast<T>(std::shared_ptr<Component>(new T()))) == nullptr)
			{
			}

			/**
			 * This attachment is required in order for the component to understand which object it should begin 
			 * operating over.
			 */
			ComponentRef->m_Owner = this;

			m_Components.push_back(ComponentRef);
		}
		
		template<typename T>
		T &GetComponent() const
		{
			for (auto component : m_Components)
			{
				if (component->IsClassType(T::ClassType))
				{
					return *((T *)component.get());
				}
			}

			throw Exception();
		}

		bool Tick();
		
		Transform &GetTransform() const;
		
		size_t GetID() const;

	private:
		std::vector<Actor> m_Children;
		std::vector<std::shared_ptr<Component>> m_Components;
		std::shared_ptr<Transform> m_Transform;
		size_t m_ID;
	};
}


