#include "Ember/Core/Core.h"
#include "Ember/Util/Math.h"

namespace Ember {
    class Camera {
    public:
        Camera();
        Camera(Vec2 pos);
        ~Camera();

        Vec2 GetPosition() { return m_Position; }
        void SetPosition(Vec2 pos) { m_Position = pos; }

        Vec2 TranslatePosition(Vec2 pos);

    private:
        Vec2 m_Position;

    };
}