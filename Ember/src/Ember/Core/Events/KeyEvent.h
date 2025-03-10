#pragma once

#include "Ember/Core/Events/Event.h"

namespace Ember {

    class EM_API KeyPressEvent : public Event{
    public:
        KeyPressedEvent(int key, int scancode,int mods, int repeatCount) : m_Key(key), m_Scancode(scancode), m_Mods(mods), m_RepeatCount(repeatCount){}

        EVENT_CLASS_TYPE(KeyPressed);
    private:
        int m_Key;
        int m_Scancode;
        int m_Mods;
        int m_RepeatCount;
    };

    class EM_API KeyReleaseEvent : public Event{
    public:
        KeyPressedEvent(int key, int scancode, int mods) : m_Key(key), m_Scancode(scancode), m_Mods(mods) {}

        EVENT_CLASS_TYPE(KeyReleased);
    private:
        int m_Key;
        int m_Scancode;
        int m_Mods;
    }
}