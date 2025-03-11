#include "empch.h"
#include "Application.h"

#include "Ember/Core/Events/EventFormatter.h"

namespace Ember {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		auto* window = static_cast<SDL_Window*>(GetWindow()->GetNativeWindow());
		m_Renderer = std::shared_ptr<Renderer>(new Renderer(window));
	}
	Application::~Application() {}

	void Application::Run() {
		while (m_Running) {

			m_Window->OnUpdate();

			

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		m_LayerStack->OnEvent(e);
		//EM_CORE_TRACE("{0}", e);
	}
}