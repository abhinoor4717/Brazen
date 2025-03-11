#pragma once

#include "Core.h"
#include "Window.h"
#include "Ember/Core/Events/Event.h"
#include "Ember/Core/Events/ApplicationEvent.h"
#include "Ember/Core/LayerStack.h"
// #include "Ember/Renderer/Renderer.h"

namespace Ember {
	
	class EM_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void OnEvent(Event& e);

		bool OnWindowClose(WindowCloseEvent& e);

		Window* GetWindow() { return m_Window.get(); }

		inline std::shared_ptr<LayerStack> GetLayerStack() { return m_LayerStack; }

	private:
		bool m_Running = true;

		std::unique_ptr<Window> m_Window;
		std::shared_ptr<LayerStack> m_LayerStack;
		std::shared_ptr<Renderer> m_Renderer;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}