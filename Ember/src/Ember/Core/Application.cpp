#include "empch.h"
#include "Application.h"

namespace Ember {
	Application::Application() {
		EM_INFO("Application created!");
	}
	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {
			
		}
	}

	void Application::OnEvent() {}
}