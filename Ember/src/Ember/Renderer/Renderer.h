#pragma once

#include "SDL2/SDL.h"
#include "Ember/Core/Core.h"
#include "Ember/Renderer/Util.h"

namespace Ember {

	class EM_API LayerStack;

	class EM_API Renderer {
		friend class LayerStack;
	public:
		Renderer(SDL_Window* window);
		~Renderer();

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

		
	private:
		void SetFillColor();
		void SetFillColor(const Color& color);

		void SetDrawColor();
		void SetDrawColor(const Color& color);
		void Update();

		void _DrawCircle(const Circle& circle, bool filled);
		void _DrawCircle(const FCircle& circle, bool filled);
		
	private:
		SDL_Renderer* m_Renderer;
	};
}