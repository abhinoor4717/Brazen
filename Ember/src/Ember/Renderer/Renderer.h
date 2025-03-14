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

		static void Init(SDL_Window* window);
		static void OnWindowResize(int w, int h);

		static void InitCamera(int w, int h) { m_Camera = new Camera(w, h); }
		static Camera& GetCamera() { return *m_Camera; }

		static void FillScreen();
		static void FillScreen(const Color& color);

		static void DrawPoint(const Point& point);
		static void DrawPoint(const Point& point, const Color& color);
		static void DrawPoint(const FPoint& point);
		static void DrawPoint(const FPoint& point, const Color& color);

		static void DrawLine(const Line& line);
		static void DrawLine(const Line& line, const Color& color);
		static void DrawLine(const FLine& line);
		static void DrawLine(const FLine& line, const Color& color);

		static void DrawRect(const Rect& rect, bool filled);
		static void DrawRect(const Rect& rect, const Color& color, bool filled);
		static void DrawRect(const FRect& rect, bool filled);
		static void DrawRect(const FRect& rect, const Color& color, bool filled);

		static void DrawCircle(const Circle& circle, bool filled);
		static void DrawCircle(const Circle& circle, const Color& color, bool filled);
		static void DrawCircle(const FCircle& circle, bool filled);
		static void DrawCircle(const FCircle& circle, const Color& color, bool filled);

		static void RenderGrid();

		static int m_RenderCount;
		
	private:
		static void SetFillColor();
		static void SetFillColor(const Color& color);

		static void SetDrawColor();
		static void SetDrawColor(const Color& color);
		static void Update();

		static void _DrawPoint(const Point& point);
		static void _DrawPoint(const FPoint& point);

		static void _DrawLine(const Line& line);
		static void _DrawLine(const FLine& line);

		static void _DrawRect(const Rect& rect, bool filled);
		static void _DrawRect(const FRect& rect, bool filled);

		static void _DrawCircle(const Circle& circle, bool filled);
		static void _DrawCircle(const FCircle& circle, bool filled);

		static bool _IsCircleWithinView(Vec2 center, int radius);
		
	private:
		static SDL_Renderer* m_Renderer;
		static Camera* m_Camera;
	};
}