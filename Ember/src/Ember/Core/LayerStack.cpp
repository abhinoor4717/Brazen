#include "empch.h"
#include "LayerStack.h"

namespace Ember {
	LayerStack::LayerStack() {
		PushBackLayer(new Layer("Main"));
	}

	void LayerStack::PushBackLayer(Layer* layer) {
		m_LayerStack.push_back(layer);
	}

	void LayerStack::PopBackLayer(Layer* layer) {
		for (auto it = m_LayerStack.begin(); it != m_LayerStack.end(); it++) {
			if (*it == layer) {
				m_LayerStack.erase(it);
				return;
			}
		}
	}

	void LayerStack::PopLayer() {
		m_LayerStack.pop_back();
	}

	void LayerStack::OnEvent(Event& e) {
		for (auto layer : m_LayerStack) {
			if (!e.Handled)
				layer->OnEvent(e);
		}
	}
}