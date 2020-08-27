#include "pch.h"
#include "InputSystem.h"

namespace nc
{
    bool InputSystem::Startup()
    {
        const Uint8* keystate = SDL_GetKeyboardState(&m_numKeys);

        m_keystate = new Uint8[m_numKeys];
        m_prevKeystate = new Uint8[m_numKeys];
        memcpy(m_keystate, keystate, m_numKeys);
        memcpy(m_prevKeystate, keystate, m_numKeys);

        return true;
    }

    void InputSystem::Shutdown()
    {
        delete[] m_keystate;
        delete[] m_prevKeystate;
    }

    void InputSystem::Update()
    {
        memcpy(m_prevKeystate, m_keystate, m_numKeys);

        const Uint8* keystate = SDL_GetKeyboardState(nullptr);

        memcpy(m_keystate, keystate, m_numKeys);
    }

    InputSystem::eButtonState InputSystem::GetButtonState(int id)
    {
        InputSystem::eButtonState state = eButtonState::IDLE;

        bool buttonDown = GetButtonDown(id);
        bool prevButtonDown = GetPreviousButtonDown(id);

        if (buttonDown)
        {
            state = (prevButtonDown) ? eButtonState::HELD : eButtonState::PRESSED;
        }
        else
        {
            state = (prevButtonDown) ? eButtonState::RELEASED : eButtonState::IDLE;
        }

        return state;
    }

    bool InputSystem::GetButtonDown(int id)
    {
        return m_keystate[id];
    }

    bool InputSystem::GetPreviousButtonDown(int id)
    {
        return m_prevKeystate[id];
    }
}
