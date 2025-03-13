#include "empch.h"
#include "SDL2/SDL.h"
#include "Ember/Util/PlatformUtils.h"

namespace Ember {
	Uint64 Time::GetTime() {
		return SDL_GetPerformanceCounter();
	}
}