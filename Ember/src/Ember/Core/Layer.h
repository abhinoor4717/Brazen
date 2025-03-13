#pragma once

#include "Ember/Core/Core.h"
#include "Ember/Core/Events/Event.h"
#include "Ember/Renderer/Renderer.h"
#include "Ember/Core/Timestep.h"

namespace Ember {
	class EM_API Layer {
	public:
		Layer(const std::string& name);

		void OnEvent(Event& e);

		inline std::string GetName() { return m_Name; }

		virtual void EventHandler(Event& e);
		virtual void OnUpdate(Timestep timestep);
	private:
		const std::string m_Name;
	};
}