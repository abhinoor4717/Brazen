#pragma once

#include "SDL2/SDL.h"
#include "Ember/Core/Core.h"

namespace Ember {
	using MouseCode = uint8_t; // SDL uses uint8_t for mouse buttons

	namespace Mouse {
		enum : MouseCode{
			Button0 = SDL_BUTTON_LEFT,
			Button1 = SDL_BUTTON_MIDDLE,
			Button2 = SDL_BUTTON_RIGHT,
			Button3 = SDL_BUTTON_X1,
			Button4 = SDL_BUTTON_X2,

			Button5 = 5, // SDL doesn't define buttons beyond X1/X2, but you can extend if needed
			Button6 = 6,
			Button7 = 7,

			ButtonLast = Button7,
			ButtonLeft = SDL_BUTTON_LEFT,
			ButtonRight = SDL_BUTTON_RIGHT,
			ButtonMiddle = SDL_BUTTON_MIDDLE
		};
	}
}
