#pragma once

#include "Core.h"
#include "Window.h"
#include "Ember/Core/Events/Event.h"
#include "Ember/Core/Events/ApplicationEvent.h"
#include "Ember/Core/LayerStack.h"

namespace Ember {
	
	class EM_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

		inline LayerStack& GetLayerStack() { return m_LayerStack; }

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}