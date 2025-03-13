#include "empch.h"
#include "SDL2/SDL.h"
#include "Ember/Core/Input.h"
#include "Ember/Core/Application.h"

namespace Ember {
	bool Input::IsKeyPressed(const KeyCode key)
	{
		return (SDL_GetKeyboardState(nullptr)[SDL_GetScancodeFromKey(key)] == SDL_PRESSED);

	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		return (SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(button));
	}

	Vec2 Input::GetMousePosition()
	{
		int mouseX, mouseY;

		SDL_GetMouseState(&mouseX, &mouseY);

		return {float(mouseX), float(mouseY)};
	}

	float Input::GetMouseX()
	{
		return GetMousePosition().x;
	}

	float Input::GetMouseY()
	{
		return GetMousePosition().y;
	}
}