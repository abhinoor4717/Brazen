#pragma once

#include "SDL2/SDL.h"
#include "Ember/Core/Core.h"
#include "Ember/Renderer/Color.h"

namespace Ember {

	class EM_API LayerStack;

	class EM_API Renderer {
		friend class LayerStack;
	public:
		Renderer(SDL_Window* window);
		~Renderer();
		
		void FillScreen(Color color);
		
	private:
		void SetDrawColor(Color color);
		void Update();
		
	private:
		SDL_Renderer* m_Renderer;
	};
}