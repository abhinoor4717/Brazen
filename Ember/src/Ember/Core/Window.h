#pragma once

#include "empch.h"
#include "Ember/Core/Core.h"
#include "Ember/Core/Events/Event.h"

namespace Ember {
    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Ember",
            unsigned int width = 1280,
            unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class EM_API Window {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        inline virtual unsigned int GetWidth() const = 0;
        inline virtual unsigned int GetHeight() const = 0;
        virtual void* GetNativeWindow() const = 0;

        //Window attributes
        inline virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());

    };
}