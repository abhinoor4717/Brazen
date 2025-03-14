#pragma once

#include "Ember/Core/Core.h"
#include "Ember/Core/LayerStack.h"

namespace Ember {
    class EM_API Scene {
    public:
        Scene();
        ~Scene();

    private:
        std::shared_ptr<LayerStack> m_LayerStack;

    }
}