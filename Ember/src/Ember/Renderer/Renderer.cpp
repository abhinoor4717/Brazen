#include "empch.h"
#include "Ember/Renderer/Renderer.h"

namespace Ember {

	int Renderer::m_RenderCount = 0;
	Camera* Renderer::m_Camera;
	SDL_Renderer* Renderer::m_Renderer;

	void Renderer::Init(SDL_Window* window) {
		if (window == nullptr) {
			EM_CORE_ERROR("Renderer window is null!");
			return;
		}

		m_Renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (m_Renderer == nullptr) {
			EM_CORE_ERROR("Renderer could not be initilized!");
			return;
		}

		EM_CORE_TRACE("Renderer initilized");

		m_RenderCount = 0;
	}

	void Renderer::OnWindowResize(int w, int h) {
		m_Camera->SetViewport(w, h);
	}

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

	void Renderer::_DrawPoint(const Point& point){
		Vec2 translatedPos = GetCamera().TranslatePosition({(float) point.x, (float) point.y});
		if (GetCamera().IsWithinView(point))
			SDL_RenderDrawPoint(m_Renderer, translatedPos.x, translatedPos.y);
		m_RenderCount++;
	}
	void Renderer::_DrawPoint(const FPoint& point){
		Vec2 translatedPos = GetCamera().TranslatePosition({point.x, point.y});
		if (GetCamera().IsWithinView(point))
			SDL_RenderDrawPoint(m_Renderer, translatedPos.x, translatedPos.y);
		m_RenderCount++;
	}

	void Renderer::DrawPoint(const Point& point) {
		SetDrawColor();
		_DrawPoint(point);
	}
	void Renderer::DrawPoint(const Point& point, const Color& color) {
		SetDrawColor(color);
		_DrawPoint(point);
	}
	void Renderer::DrawPoint(const FPoint& point) {
		SetDrawColor();
		_DrawPoint(point);
	}
	void Renderer::DrawPoint(const FPoint& point, const Color& color) {
		SetDrawColor(color);
		_DrawPoint(point);
	}

	void Renderer::_DrawLine(const Line& line) {
		Vec2 translatedStartPoint = GetCamera().TranslatePosition({(float) line.start.x, (float) line.start.y});
		Vec2 translatedEndPoint = GetCamera().TranslatePosition({(float) line.end.x, (float) line.end.y});

		SDL_RenderDrawLine(m_Renderer, translatedStartPoint.x, translatedStartPoint.y, translatedEndPoint.x, translatedEndPoint.y);
		m_RenderCount++;
	}
	void Renderer::_DrawLine(const FLine& line) {
		Vec2 translatedStartPoint = GetCamera().TranslatePosition({line.start.x, line.start.y});
		Vec2 translatedEndPoint = GetCamera().TranslatePosition({line.end.x, line.end.y});

		SDL_RenderDrawLineF(m_Renderer, translatedStartPoint.x, translatedStartPoint.y, translatedEndPoint.x, translatedEndPoint.y);
		m_RenderCount++;
	}

	void Renderer::DrawLine(const Line& line) {
		SetDrawColor();
		_DrawLine(line);
	}
	void Renderer::DrawLine(const Line& line, const Color& color) {
		SetDrawColor(color);
		_DrawLine(line);
	}
	void Renderer::DrawLine(const FLine& line) {
		SetDrawColor();
		_DrawLine(line);
	}
	void Renderer::DrawLine(const FLine& line, const Color& color) {
		SetDrawColor(color);
		_DrawLine(line);
	}

	void Renderer::_DrawRect(const Rect& rect, bool filled) {
		Vec2 translatedPos = GetCamera().TranslatePosition({ (float)rect.pos.x, (float)rect.pos.y });

		auto& cam = GetCamera();
		
		if (cam.IsWithinView(rect.TopLeft()) || cam.IsWithinView(rect.TopRight()) || cam.IsWithinView(rect.BottomRight()) || cam.IsWithinView(rect.BottomLeft())) {
			Rect translatedRect = { (int) translatedPos.x, (int) translatedPos.y, rect.w, rect.h };
			SDL_Rect tempRect = SDL_Rect(translatedRect);
			if (filled)
				SDL_RenderFillRect(m_Renderer, &tempRect);
			else
				SDL_RenderDrawRect(m_Renderer, &tempRect);
			m_RenderCount++;
		}

	}
	void Renderer::_DrawRect(const FRect& rect, bool filled) {
		Vec2 translatedPos = GetCamera().TranslatePosition({ (float)rect.pos.x, (float)rect.pos.y });

		auto& cam = GetCamera();

		if (cam.IsWithinView(rect.TopLeft()) || cam.IsWithinView(rect.TopRight()) || cam.IsWithinView(rect.BottomRight()) || cam.IsWithinView(rect.BottomLeft())) {
			FRect translatedRect = { translatedPos.x, translatedPos.y, rect.w, rect.h };
			SDL_FRect tempRect = SDL_FRect(translatedRect);
			if (filled)
				SDL_RenderFillRectF(m_Renderer, &tempRect);
			else
				SDL_RenderDrawRectF(m_Renderer, &tempRect);
			m_RenderCount++;
		}

	}

	void Renderer::DrawRect(const Rect& rect, bool filled) {
		SetDrawColor();
		_DrawRect(rect, filled);
	}
	void Renderer::DrawRect(const Rect& rect, const Color& color, bool filled) {
		SetDrawColor(color);
		_DrawRect(rect, filled);
	}
	void Renderer::DrawRect(const FRect& rect, bool filled) {
		SetDrawColor();
		_DrawRect(rect, filled);
	}
	void Renderer::DrawRect(const FRect& rect, const Color& color, bool filled) {
		SetDrawColor(color);
		_DrawRect(rect, filled);
	}

	bool Renderer::_IsCircleWithinView(Vec2 center, int radius) {
		auto& cam = GetCamera();

		Vec2 screenCenter = cam.TranslatePosition(center);

		float left = (float)(screenCenter.x - radius);
		float right = (float)(screenCenter.x + radius);
		float top = (float)(screenCenter.y - radius);
		float bottom = (float)(screenCenter.y + radius);

		return (cam.IsWithinView({ left, top }) || cam.IsWithinView({ right, top }) ||
			cam.IsWithinView({ left, bottom }) || cam.IsWithinView({ right, bottom }));
	}

	void Renderer::_DrawCircle(const Circle& circle, bool filled) {
		auto& cam = GetCamera();

		if (_IsCircleWithinView(circle.center, circle.radius))
			return;

		Vec2 translatedCenter = cam.TranslatePosition(circle.center);
		int centerX = translatedCenter.x;
		int centerY = translatedCenter.y;
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
		m_RenderCount++;

	}
	void Renderer::_DrawCircle(const FCircle& circle, bool filled) {
		auto& cam = GetCamera();

		if (_IsCircleWithinView(circle.center, circle.radius))
			return;

		Vec2 translatedCenter = cam.TranslatePosition(circle.center);
		float centerX = translatedCenter.x;
		float centerY = translatedCenter.y;
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
		m_RenderCount++;
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

	void Renderer::RenderGrid() {
		int cellSize = 100;

		Vec2 camPos = GetCamera().GetPosition();
		int screenWidth = GetCamera().GetWidth();
		int screenHeight = GetCamera().GetHeight();

		// Compute the visible grid range
		int startX = (((int)camPos.x / cellSize) * cellSize)-cellSize;
		int startY = (((int)camPos.y / cellSize) * cellSize)-cellSize;
		int endX = startX + screenWidth + cellSize;
		int endY = startY + screenHeight + cellSize;

		for (int x = startX; x < endX; x += cellSize) {
			for (int y = startY; y < endY; y += cellSize) {
				DrawRect(Rect{ x, y, cellSize, cellSize }, false);
			}
		}
	}
}