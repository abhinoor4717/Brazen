#include "empch.h"
#include "WindowsWindow.h"

#include "Ember/Core/Events/ApplicationEvent.h"
#include "Ember/Core/Events/KeyEvent.h"
#include "Ember/Core/Events/MouseEvent.h"



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

		m_Window = SDL_CreateWindow("Ember", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, m_Data.Width, m_Data.Height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		if (m_Window == nullptr) {
			EM_CORE_CRITICAL("Window could not be initilized! SDL error: {0}", SDL_GetError());
		}
		SDL_SetWindowData(m_Window, "m_Data", &m_Data);
		SetVSync(true);
	}
	
	void WindowsWindow::ParseEvent(const SDL_Event& e) const{

		switch (e.type) {
			case SDL_QUIT: {
				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");
				WindowCloseEvent event;
				data.EventCallback(event);
				break;
			}

			// Window Events
			case SDL_WINDOWEVENT: {
				switch (e.window.event) {
					case SDL_WINDOWEVENT_RESIZED: {
						WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

						data.Width = e.window.data1;
						data.Height = e.window.data2;

						WindowResizeEvent event(e.window.data1, e.window.data2);
						data.EventCallback(event);
						break;
					}
					case SDL_WINDOWEVENT_MOVED: {
						WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

						WindowMoveEvent event(e.window.data1, e.window.data2);
						data.EventCallback(event);
						break;
					}
					case SDL_WINDOWEVENT_FOCUS_GAINED: {
						WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

						WindowFocus event;
						data.EventCallback(event);
						break;
					}
					case SDL_WINDOWEVENT_FOCUS_LOST: {
						WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

						WindowLostFocus event;
						data.EventCallback(event);
						break;
					}
				}
				break;
			}
			
			// Key Events
			case (SDL_KEYDOWN): {
				if (e.key.keysym.sym == SDLK_UNKNOWN) break;

				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				KeyPressEvent event((int) e.key.keysym.sym, (int) e.key.keysym.scancode, (int) e.key.keysym.mod, e.key.repeat);
				data.EventCallback(event);
				break;
			}
			case (SDL_KEYUP): {
				if (e.key.keysym.sym == SDLK_UNKNOWN) break;

				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				KeyReleaseEvent event((int) e.key.keysym.sym, (int) e.key.keysym.scancode, (int) e.key.keysym.mod);
				data.EventCallback(event);
				break;
			}

			// Mouse Events
			case (SDL_MOUSEBUTTONDOWN): {
				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				MouseButtonPressEvent event(e.button.button);
				data.EventCallback(event);
				break;
			}
			case (SDL_MOUSEBUTTONUP): {
				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				MouseButtonReleaseEvent event(e.button.button);
				data.EventCallback(event);
				break;
			}
			case (SDL_MOUSEMOTION): {
				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				MouseMove event(e.motion.x, e.motion.y);
				data.EventCallback(event);
				break;
			}
			case (SDL_MOUSEWHEEL): {
				WindowData& data = *(WindowData*)SDL_GetWindowData(m_Window, "m_Data");

				MouseScroll event(e.wheel.x, e.wheel.y);
				data.EventCallback(event);
				break;
			}
			
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