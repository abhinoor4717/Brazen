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
	Renderer::~Renderer() {};

	void Renderer::SetDrawColor(Color color) {
		SDL_SetRenderDrawColor(m_Renderer, color.r, color.g, color.b, color.a);
	}

	void Renderer::Update() {
		SDL_RenderPresent(m_Renderer);
	}

	void Renderer::FillScreen(Color color) {
		SetDrawColor(color);
		SDL_RenderClear(m_Renderer);
	}
}