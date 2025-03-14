#pragma once

#include "Ember/Util/Math.h"

struct Color {
	int r, g, b, a;
};

struct Point {
	int x, y;

	operator Vec2() const {
		return { (float)x, (float)y };
	}

};

struct FPoint {
	float x, y;

	operator Vec2() const {
		return { x,y };
	}

};

struct Line {
	Point start, end;
};

struct FLine {
	FPoint start, end;
};

struct Rect {
	Point pos;
	int w, h;

	Rect(int x, int y, int width, int height)
		: pos{ x,y }, w(width), h(height) {}

	operator SDL_Rect() const {
		return SDL_Rect{ pos.x, pos.y, w, h };
	}

	int Top() const { return pos.y; }
	int Bottom() const { return pos.y + h; }
	int Left() const { return pos.x; }
	int Right() const { return pos.x + w; }

	Point TopLeft() const { return pos; }
	Point TopRight() const { return { pos.x + w, pos.y }; }
	Point BottomLeft() const { return { pos.x, pos.y + h }; }
	Point BottomRight() const { return { pos.x + w, pos.y + h }; }
};

struct FRect {
	FPoint pos;
	float w, h;

	FRect(float x, float y, float width, float height)
		: pos{ x,y }, w(width), h(height) {}

	operator SDL_FRect() const {
		return SDL_FRect{ pos.x, pos.y, w, h };
	}

	float Top() const { return pos.y; }
	float Bottom() const { return pos.y + h; }
	float Left() const { return pos.x; }
	float Right() const { return pos.x + w; }

	FPoint TopLeft() const { return pos; }
	FPoint TopRight() const { return { pos.x + w, pos.y }; }
	FPoint BottomLeft() const { return { pos.x, pos.y + h }; }
	FPoint BottomRight() const { return { pos.x + w, pos.y + h }; }
};

struct Circle {
	Point center;
	int radius;

	Circle(int x, int y, int rad)
		: center{ x,y }, radius(rad) {}
};

struct FCircle {
	FPoint center;
	float radius;

	FCircle(float x, float y, float rad)
		: center{ x,y }, radius(rad) {}
};