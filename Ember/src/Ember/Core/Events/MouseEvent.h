#pragma once

#include "Ember/Core/Events/Event.h"

namespace Ember {

    class EM_API MouseButtonEvent : public Event {
    public:
        inline int GetMouseButton() const { return m_Button; }

    protected:
        MouseButtonEvent(int button) : m_Button(button) {}
        int m_Button;
    };
    
    class EM_API MouseButtonPressEvent : public MouseButtonEvent {
    public:
        MouseButtonPressEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressEvent: " << m_Button;
			return ss.str();
		}

        EVENT_CLASS_TYPE(MouseButtonPressed);

    };

    class EM_API MouseButtonReleaseEvent : public MouseButtonEvent {
    public:
        MouseButtonReleaseEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleaseEvent: " << m_Button;
			return ss.str();
		}

        EVENT_CLASS_TYPE(MouseButtonReleased);

    };

    class EM_API MouseMove : public Event {
    public:
        MouseMove(float xPos, float yPos) : m_X(xPos), m_Y(yPos) {}

        inline float GetX() { return m_X; }
        inline float GetY() { return m_Y; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMoveEvent: " << m_X << ", " << m_Y;
			return ss.str();
		}

        EVENT_CLASS_TYPE(MouseMoved);

    private:
        float m_X, m_Y;
    };

    class EM_API MouseScroll : public Event {
    public:
        MouseScroll(float xOffset, float yOffset) {}

        inline float GetXOffset() const { return m_XOffset; }
		inline float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrollEvent: " << m_XOffset << ", " << m_YOffset;
			return ss.str();
		}

        EVENT_CLASS_TYPE(MouseScrolled);

    private:
        float m_XOffset, m_YOffset;
    };

}