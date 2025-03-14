#include "empch.h"
#include "Ember/Renderer/Camera.h"

namespace Ember {
    Camera::Camera(int w, int h) : m_Width(w), m_Height(h), m_Position({0,0}) {}
    Camera::Camera(int w, int h, Vec2 pos) : m_Width(w), m_Height(h), m_Position(pos) {}

    Camera::~Camera() {}

    void Camera::SetViewport(int w, int h) {
        m_Width = w;
        m_Height = h;
        EM_TRACE("Viewport updated: {0}, {1}", m_Width, m_Height);
    }

    Vec2 Camera::TranslatePosition(Vec2 pos) {
        return {pos.x-m_Position.x, pos.y-m_Position.y};
    }

    bool Camera::IsWithinView(Vec2 worldPos) {

        auto screenPos = TranslatePosition(worldPos);
        
        return (screenPos.x >= 0 && screenPos.x <= m_Width
            && screenPos.y >= 0 && screenPos.y <= m_Height);

    }

}