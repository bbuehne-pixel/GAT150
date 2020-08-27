#pragma once
#include "Objects/GameObject.h"

namespace nc
{
	class GameObject;

	class Component : public Object
	{
	public:
		virtual void Create(void* data) = 0;
		virtual void Update() = 0;

		friend class GameObject;

	protected:
		GameObject* m_owner{ nullptr };
	};
}
