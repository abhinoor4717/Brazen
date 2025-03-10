#include "empch.h"
#include "WindowsWindow.h"

#include "Ember/Core/Events/ApplicationEvent.h"

namespace Ember {
	static bool s_SDLInitilized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Height;
		m_Data.Height = props.Height;

		EM_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_SDLInitilized) {
			bool success = true;
			if (SDL_Init(SDL_INIT_VIDEO) < 0) {
				EM_CORE_CRITICAL("SDL could not initilize! SDL error: {0}", SDL_GetError());
				exit(-1);
			}

			s_SDLInitilized = true;
		}

		m_Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Data.Width, m_Data.Height, SDL_WINDOW_SHOWN);
		if (m_Window == nullptr) {
			EM_CORE_CRITICAL("Window could not be initilized! SDL error: {0}", SDL_GetError());
		}
		SDL_SetWindowData(m_Window, "m_Data", &m_Data);
		SetVSync(true);
	}
	
	void WindowsWindow::ParseEvent(const SDL_Event& e) const{
		if (e.type == SDL_QUIT) {
			WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");
			WindowCloseEvent event;
			data.EventCallback(event);

		}
	}

	void WindowsWindow::Shutdown() {
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	void WindowsWindow::OnUpdate() {
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			ParseEvent(e);
		}
	}

	void WindowsWindow::SetVSync(bool enabled) {
		SDL_GLContext glContext = SDL_GL_CreateContext(m_Window);
		if (!glContext) {
			EM_CORE_ERROR("SDL_GL_CreateContext Error: {0}", SDL_GetError());
			exit(-1);
		}
		if (enabled) {
			if (SDL_GL_SetSwapInterval(1) < 0) {
				EM_CORE_ERROR("SDL_GL_SetSwapInterval Error: {0}", SDL_GetError());
			}
		}
		else {
			if (SDL_GL_SetSwapInterval(0) < 0) {
				EM_CORE_ERROR("SDL_GL_SetSwapInterval Error: {0}", SDL_GetError());
			}
		}
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}