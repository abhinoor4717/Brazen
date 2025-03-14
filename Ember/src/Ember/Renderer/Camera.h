#include "Ember/Core/Core.h"
#include "Ember/Util/Math.h"

namespace Ember {
    class EM_API Camera {
    public:
        Camera(int w, int h);
        Camera(int w, int h, Vec2 pos);
        ~Camera();

        void SetViewport(int w, int h);

        int GetWidth() { return m_Width; }
        int GetHeight() { return m_Height; }

        Vec2 GetPosition() { return m_Position; }
        void SetPosition(Vec2 pos) { m_Position = pos; }

        Vec2 TranslatePosition(Vec2 pos);
        bool IsWithinView(Vec2 pos);

    private:
        Vec2 m_Position;
        int m_Width, m_Height;
    };
}