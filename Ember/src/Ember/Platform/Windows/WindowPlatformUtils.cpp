#include "empch.h"
#include "SDL2/SDL.h"
#include "Ember/Util/PlatformUtils.h"

namespace Ember {
	float Time::GetTime() {
		//return SDL_GetPerformanceCounter() / SDL_GetPerformanceFrequency();
		return SDL_GetTicks();
	}
}