#pragma once

#include "SDL2/SDL.h"
#include "Ember/Core/Core.h"
#include "Ember/Renderer/Color.h"

namespace Ember {
	class EM_API Renderer {
	public:
		Renderer(SDL_Window* window);
		~Renderer();
		
		void FillScreen(Color color);
		void Update();

	private:
		void SetDrawColor(Color color);

	private:
		SDL_Renderer* m_Renderer;
	};
}