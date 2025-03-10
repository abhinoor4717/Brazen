#pragma once

#include "Ember/Core/Events/Event.h"

namespace Ember {
	class EM_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	};
}