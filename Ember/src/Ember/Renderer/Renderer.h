#pragma once

#include "SDL2/SDL.h"
#include "Ember/Core/Core.h"
#include "Ember/Util/RendererUtil.h"
#include "Ember/Renderer/Camera.h"

namespace Ember {

	class EM_API LayerStack;

	class EM_API Renderer {
		friend class LayerStack;
	public:
		Renderer(SDL_Window* window);
		~Renderer();

		void OnWindowResize(int w, int h);

		void InitCamera(int w, int h) { m_Camera = new Camera(w, h); }
		Camera& GetCamera() { return *m_Camera; }

		void FillScreen();
		void FillScreen(const Color& color);

		void DrawPoint(const Point& point);
		void DrawPoint(const Point& point, const Color& color);
		void DrawPoint(const FPoint& point);
		void DrawPoint(const FPoint& point, const Color& color);

		void DrawLine(const Line& line);
		void DrawLine(const Line& line, const Color& color);
		void DrawLine(const FLine& line);
		void DrawLine(const FLine& line, const Color& color);

		void DrawRect(const Rect& rect, bool filled);
		void DrawRect(const Rect& rect, const Color& color, bool filled);
		void DrawRect(const FRect& rect, bool filled);
		void DrawRect(const FRect& rect, const Color& color, bool filled);

		void DrawCircle(const Circle& circle, bool filled);
		void DrawCircle(const Circle& circle, const Color& color, bool filled);
		void DrawCircle(const FCircle& circle, bool filled);
		void DrawCircle(const FCircle& circle, const Color& color, bool filled);

		void RenderGrid();

		int m_RenderCount=0;
		
	private:
		void SetFillColor();
		void SetFillColor(const Color& color);

		void SetDrawColor();
		void SetDrawColor(const Color& color);
		void Update();

		void _DrawPoint(const Point& point);
		void _DrawPoint(const FPoint& point);

		void _DrawLine(const Line& line);
		void _DrawLine(const FLine& line);

		void _DrawRect(const Rect& rect, bool filled);
		void _DrawRect(const FRect& rect, bool filled);

		void _DrawCircle(const Circle& circle, bool filled);
		void _DrawCircle(const FCircle& circle, bool filled);

		bool _IsCircleWithinView(Vec2 center, int radius);
		
	private:
		SDL_Renderer* m_Renderer;
		Camera* m_Camera;
	};
}