#include "empch.h"
#include "Ember/Renderer/Renderer.h"

namespace Ember {
	Renderer::Renderer(SDL_Window* window) {
		if (window == nullptr) {
			EM_CORE_ERROR("Renderer window is null!");
			Renderer::~Renderer();
		}

		m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (m_Renderer == nullptr) {
			EM_CORE_ERROR("Renderer could not be initilized!");
			Renderer::~Renderer();
		}

		EM_CORE_TRACE("Renderer initilized");

	}
	Renderer::~Renderer() {
		SDL_DestroyRenderer(m_Renderer);
	};

	void Renderer::Update() {
		SDL_RenderPresent(m_Renderer);
	}

	void Renderer::FillScreen() {
		SetFillColor();
	}
	void Renderer::FillScreen(const Color& color) {
		SetFillColor(color);
	}

	void Renderer::SetFillColor() {
		SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 0);
		SDL_RenderClear(m_Renderer);
	}
	void Renderer::SetFillColor(const Color& color) {
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
		SDL_RenderClear(m_Renderer);
	}

	void Renderer::SetDrawColor() {
		SDL_SetRenderDrawColor(m_Renderer, 255, 255, 255, 255);
	}
	void Renderer::SetDrawColor(const Color& color) {
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
	}


	void Renderer::DrawPoint(const Point& point) {
		SetDrawColor();
		SDL_RenderDrawPoint(m_Renderer, point.x, point.y);
	}
	void Renderer::DrawPoint(const Point& point, const Color& color) {
		SetDrawColor(color);
		SDL_RenderDrawPoint(m_Renderer, point.x, point.y);
	}
	void Renderer::DrawPoint(const FPoint& point) {
		SetDrawColor();
		SDL_RenderDrawPointF(m_Renderer, point.x, point.y);
	}
	void Renderer::DrawPoint(const FPoint& point, const Color& color) {
		SetDrawColor(color);
		SDL_RenderDrawPointF(m_Renderer, point.x, point.y);
	}

	void Renderer::DrawLine(const Line& line) {
		SetDrawColor();
		SDL_RenderDrawLine(m_Renderer, line.start.x, line.start.y, line.end.x, line.end.y);
	}
	void Renderer::DrawLine(const Line& line, const Color& color) {
		SetDrawColor(color);
		SDL_RenderDrawLine(m_Renderer, line.start.x, line.start.y, line.end.x, line.end.y);
	}
	void Renderer::DrawLine(const FLine& line) {
		SetDrawColor();
		SDL_RenderDrawLineF(m_Renderer, line.start.x, line.start.y, line.end.x, line.end.y);
	}
	void Renderer::DrawLine(const FLine& line, const Color& color) {
		SetDrawColor(color);
		SDL_RenderDrawLineF(m_Renderer, line.start.x, line.start.y, line.end.x, line.end.y);
	}

	void Renderer::DrawRect(const Rect& rect, bool filled) {
		SetDrawColor();
		SDL_Rect tempRect = SDL_Rect(rect);
		if (filled)
			SDL_RenderFillRect(m_Renderer, &tempRect);
		else
			SDL_RenderDrawRect(m_Renderer, &tempRect);
	}
	void Renderer::DrawRect(const Rect& rect, const Color& color, bool filled) {
		SetDrawColor(color);
		SDL_Rect tempRect = SDL_Rect(rect);
		if (filled)
			SDL_RenderFillRect(m_Renderer, &tempRect);
		else
			SDL_RenderDrawRect(m_Renderer, &tempRect);
	}
	void Renderer::DrawRect(const FRect& rect, bool filled) {
		SetDrawColor();
		SDL_FRect tempRect = SDL_FRect(rect);
		if (filled)
			SDL_RenderFillRectF(m_Renderer, &tempRect);
		else
			SDL_RenderDrawRectF(m_Renderer, &tempRect);
	}
	void Renderer::DrawRect(const FRect& rect, const Color& color, bool filled) {
		SetDrawColor(color);
		SDL_FRect tempRect = SDL_FRect(rect);
		if (filled)
			SDL_RenderFillRectF(m_Renderer, &tempRect);
		else
			SDL_RenderDrawRectF(m_Renderer, &tempRect);
	}

	void Renderer::_DrawCircle(const Circle& circle, bool filled) {
		int centerX = circle.center.x;
		int centerY = circle.center.y;
		int x = circle.radius, y = 0;
		int err = 0;

		if (filled) {
			while (x >= y) {
				SDL_RenderDrawLine(m_Renderer, centerX - x, centerY + y, centerX + x, centerY + y);
				SDL_RenderDrawLine(m_Renderer, centerX - x, centerY - y, centerX + x, centerY - y);

				SDL_RenderDrawLine(m_Renderer, centerX - y, centerY + x, centerX + y, centerY + x);
				SDL_RenderDrawLine(m_Renderer, centerX - y, centerY - x, centerX + y, centerY - x);

				y++;
				err += 1 + 2 * y;
				if (err > 0) {
					x--;
					err += 1 - 2 * x;
				}
			}
		}
		else {
			while (x >= y) {
				SDL_RenderDrawPoint(m_Renderer, centerX + x, centerY + y);
				SDL_RenderDrawPoint(m_Renderer, centerX + y, centerY + x);
				SDL_RenderDrawPoint(m_Renderer, centerX - y, centerY + x);
				SDL_RenderDrawPoint(m_Renderer, centerX - x, centerY + y);
				SDL_RenderDrawPoint(m_Renderer, centerX - x, centerY - y);
				SDL_RenderDrawPoint(m_Renderer, centerX - y, centerY - x);
				SDL_RenderDrawPoint(m_Renderer, centerX + y, centerY - x);
				SDL_RenderDrawPoint(m_Renderer, centerX + x, centerY - y);

				y++;
				err += 1 + 2 * y;
				if (err > 0) {
					x--;
					err += 1 - 2 * x;
				}
			}
		}

	}
	void Renderer::_DrawCircle(const FCircle& circle, bool filled) {
		float centerX = circle.center.x;
		float centerY = circle.center.y;
		float x = circle.radius, y = 0;
		float err = 0;

		if (filled) {
			while (x >= y) {
				SDL_RenderDrawLineF(m_Renderer, centerX - x, centerY + y, centerX + x, centerY + y);
				SDL_RenderDrawLineF(m_Renderer, centerX - x, centerY - y, centerX + x, centerY - y);

				SDL_RenderDrawLineF(m_Renderer, centerX - y, centerY + x, centerX + y, centerY + x);
				SDL_RenderDrawLineF(m_Renderer, centerX - y, centerY - x, centerX + y, centerY - x);

				y++;
				err += 1 + 2 * y;
				if (err > 0) {
					x--;
					err += 1 - 2 * x;
				}
			}
		}
		else {
			while (x >= y) {
				SDL_RenderDrawPointF(m_Renderer, centerX + x, centerY + y);
				SDL_RenderDrawPointF(m_Renderer, centerX + y, centerY + x);
				SDL_RenderDrawPointF(m_Renderer, centerX - y, centerY + x);
				SDL_RenderDrawPointF(m_Renderer, centerX - x, centerY + y);
				SDL_RenderDrawPointF(m_Renderer, centerX - x, centerY - y);
				SDL_RenderDrawPointF(m_Renderer, centerX - y, centerY - x);
				SDL_RenderDrawPointF(m_Renderer, centerX + y, centerY - x);
				SDL_RenderDrawPointF(m_Renderer, centerX + x, centerY - y);

				y++;
				err += 1 + 2 * y;
				if (err > 0) {
					x--;
					err += 1 - 2 * x;
				}
			}
		}
	}

	void Renderer::DrawCircle(const Circle& circle, bool filled) {
		SetDrawColor();
		_DrawCircle(circle, filled);
	}
	void Renderer::DrawCircle(const Circle& circle, const Color& color, bool filled) {
		SetDrawColor(color);
		_DrawCircle(circle, filled);
	}
	void Renderer::DrawCircle(const FCircle& circle, bool filled) {
		SetDrawColor();
		_DrawCircle(circle, filled);
	}
	void Renderer::DrawCircle(const FCircle& circle, const Color& color, bool filled) {
		SetDrawColor(color);
		_DrawCircle(circle, filled);
	}
}