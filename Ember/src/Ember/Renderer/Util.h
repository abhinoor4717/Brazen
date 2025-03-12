#pragma once

struct Color {
	int r, g, b, a;
};

struct Point {
	int x, y;
};

struct FPoint {
	float x, y;
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
		: pos{x,y}, w(width), h(height) {}

	operator SDL_Rect() const {
		return SDL_Rect{ pos.x, pos.y, w, h };
	}
};

struct FRect {
	FPoint pos;
	float w, h;

	FRect(float x, float y, float width, float height)
		: pos{ x,y }, w(width), h(height) {}

	operator SDL_FRect() const {
		return SDL_FRect{pos.x, pos.y, w, h};
	}
};

struct Circle {
	Point center;
	int radius;

	Circle(int x, int y, int rad)
		: center{x,y}, radius(rad) {}
};

struct FCircle {
	FPoint center;
	float radius;

	FCircle(float x, float y, float rad)
		: center{ x,y }, radius(rad) {}
};