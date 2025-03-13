#include "Ember/Core/Core.h"
#include "Ember/Core/KeyCodes.h"
#include "Ember/Core/MouseCodes.h"
#include "Ember/Util/Math.h"

namespace Ember {
	class EM_API Input {
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static Vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}