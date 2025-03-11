#pragma once

#include "Ember/Core/Core.h"
#include "Ember/Core/Layer.h"
#include "Ember/Core/Events/Event.h"

namespace Ember {
	class EM_API LayerStack {
	public:
		LayerStack();

		void PushBackLayer(Layer* layer);
		void PopBackLayer(Layer* layer);
		void PopLayer();

		void OnEvent(Event& e);

	private:
		std::vector<Layer*> m_LayerStack;
	};
}