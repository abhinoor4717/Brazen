#include <Ember.h>

class BackGround : public Ember::Layer {
public:
	BackGround() : Layer("Background") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		Ember::Renderer::FillScreen();
		Ember::Renderer::m_RenderCount = 0;
		Ember::Renderer::RenderGrid();
	}

};

class ForeGround : public Ember::Layer {
public:
	ForeGround() : Layer("Foreground") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		auto& cam = Ember::Renderer::GetCamera();
		HandleInput(timestep);

		Ember::Renderer::DrawRect(m_Rect, true);

		// EM_TRACE("{0}", Ember::Renderer::m_RenderCount);
		
	}

	void HandleInput(Ember::Timestep timestep) {
		auto& camera = Ember::Renderer::GetCamera();
		if (Ember::Input::IsKeyPressed(Ember::Key::Right)) {
			auto camPos = camera.GetPosition();
			camPos.x += m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Left)) {
			auto camPos = camera.GetPosition();
			camPos.x -= m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Up)) {
			auto camPos = camera.GetPosition();
			camPos.y -= m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Down)) {
			auto camPos = camera.GetPosition();
			camPos.y += m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
	}

private:
	FRect m_Rect{ -1000,0,50,50 };
	int m_RectSpeed = 500;
};
	
class Brazen : public Ember::Application {
public:
	Brazen() {

		//Ember::Application::GetApplication().GetRenderer().GetCamera().SetPosition({10,5});

		auto ls = GetLayerStack();
		ls->PopLayer();

		ls->PushBackLayer(new BackGround());
		ls->PushBackLayer(new ForeGround());
	}
	~Brazen() {}
};

Ember::Application* Ember::CreateApplication() {
	return new Brazen();
}