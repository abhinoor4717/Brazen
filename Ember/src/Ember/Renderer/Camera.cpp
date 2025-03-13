#include "empch.h"
#include "Ember/Renderer/Camera.h"

namespace Ember {
    Camera::Camera() : m_Position({0,0}) {}
    Camera::Camera(Vec2 pos) : m_Position(pos) {}

    Camera::~Camera() {}

    Vec2 Camera::TranslatePosition(Vec2 pos) {
        return {pos.x-m_Position.x, pos.y-m_Position.y};
    }

}