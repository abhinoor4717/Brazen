#pragma once

#include "Ember/Core/Events/Event.h"

namespace Ember {
	class EM_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	};

	class EM_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(int width, int height) : m_Width(width), m_Height(height) {}

		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
	private:
		int m_Width;
		int m_Height;
	};

	class EM_API WindowMoveEvent : public Event {
	public:
		WindowMoveEvent(int xPos, int yPos) : m_X(xPos), m_Y(yPos) {}

		int GetX() { return m_X; }
		int GetY() { return m_Y; }

		EVENT_CLASS_TYPE(WindowMoved);

	private:
		int m_X;
		int m_Y;
	};

	class EM_API WindowFocus : public Event {
	public:
		WindowFocus() {}
	
		EVENT_CLASS_TYPE(WindowFocus);

	};

	class EM_API WindowLostFocus : public Event {
	public:
		WindowLostFocus() {}

		EVENT_CLASS_TYPE(WindowLostFocus);
	};
}