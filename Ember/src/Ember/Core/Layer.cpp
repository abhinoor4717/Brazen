#include "empch.h"
#include "Layer.h"

#include "Ember/Core/Application.h"
#include "Ember/Core/Events/EventFormatter.h"

namespace Ember {

	Layer::Layer(const std::string& name) : m_Name(name) {}

	void Layer::OnEvent(Event& e) {
		EventHandler(e);
	}

	void Layer::EventHandler(Event& e) {
		EM_INFO("Layer \"{0}\" recieved {1}", m_Name, e);
	}

	void Layer::OnUpdate(Timestep timestep) {
		Application::GetApplication().GetRenderer().FillScreen();
	}
}