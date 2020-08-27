#pragma once
#include "Core/System.h"

namespace nc
{
	class InputSystem : public System
	{
	public:
		// Inherited via System
		virtual bool Startup() override;
		virtual void Shutdown() override;
		virtual void Update() override;

		enum class eButtonState
		{
			IDLE,
			PRESSED,
			HELD,
			RELEASED
		};

		eButtonState GetButtonState(int id);
		bool GetButtonDown(int id);
		bool GetPreviousButtonDown(int id);

	protected:
		Uint8* m_keystate;
		Uint8* m_prevKeystate;
		int m_numKeys;
	};
}