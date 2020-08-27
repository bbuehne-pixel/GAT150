#pragma once
#include "Component.h"

namespace nc
{
	class RenderComponent : public Component
	{
	public:
		//void Read(const rapidjson::Value& value) override;

		virtual void Draw() = 0;

		static bool SortZ(const RenderComponent* lhs, const RenderComponent* rhs)
		{
			return (lhs->m_z < rhs->m_z);
		}

	protected:
		int m_z{ 0 };
	};
}
