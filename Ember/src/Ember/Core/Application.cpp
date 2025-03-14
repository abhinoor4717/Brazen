#include "empch.h"
#include "Application.h"

#include "Ember/Core/Events/EventFormatter.h"
#include "Ember/Util/PlatformUtils.h"

namespace Ember {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Application = nullptr;

	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		s_Application = this;

		m_LayerStack = std::make_shared<LayerStack>();

		auto* window = static_cast<SDL_Window*>(GetWindow()->GetNativeWindow());

		Renderer::Init(window);
		Renderer::InitCamera(GetWindow()->GetWidth(), GetWindow()->GetHeight());
	}
	Application::~Application() {}

	void Application::Run() {

		while (m_Running) {

			auto time = Time::GetTime();
			Timestep timestep = (float)((time - m_LastFrameTime)*1000 / (double)SDL_GetPerformanceFrequency() );
			m_LastFrameTime = time;
			// EM_CORE_TRACE("FPS: {0}", 1000 / timestep.GetMilliseconds());

			m_LayerStack->OnUpdate(timestep);

			m_Window->OnUpdate();

		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e) {
		EM_TRACE("{0}", e.ToString());
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return false;
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OnWindowResize));

		m_LayerStack->OnEvent(e);
	}
}