#pragma once

#include "Ember/Core/Events/Event.h"

namespace Ember {

    class EM_API KeyEvent : public Event {
    public:
        inline int GetKeyCode() const { return m_KeyCode; }

    protected:
		KeyEvent(int keycode, int scancode, int mods)
			: m_KeyCode(keycode), m_Scancode(scancode), m_Mods(mods) {}

		int m_KeyCode, m_Scancode, m_Mods;
    };

    class EM_API KeyPressEvent : public KeyEvent{
    public:
        KeyPressEvent(int keycode, int scancode,int mods, int repeatCount) : KeyEvent(keycode, scancode, mods), m_RepeatCount(repeatCount){}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

        EVENT_CLASS_TYPE(KeyPressed);
    private:
        int m_RepeatCount;
    };

    class EM_API KeyReleaseEvent : public KeyEvent{
    public:
        KeyReleaseEvent(int keycode, int scancode, int mods) : KeyEvent(keycode, scancode, mods) {}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleaseEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

        EVENT_CLASS_TYPE(KeyReleased);
    };
}