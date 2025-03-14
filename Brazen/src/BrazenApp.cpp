#include <Ember.h>

class BackGround : public Ember::Layer {
public:
	BackGround() : Layer("Background") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		m_Renderer.FillScreen();
		//m_Renderer.RenderGrid();
	}
private:
	Ember::Renderer& m_Renderer = Ember::Application::GetApplication().GetRenderer();;

};

class ForeGround : public Ember::Layer {
public:
	ForeGround() : Layer("Foreground") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		auto& camera = Ember::Application::GetApplication().GetRenderer().GetCamera();
		EM_TRACE("{0}, {1}", camera.GetWidth(), camera.GetHeight());
		HandleInput(timestep);

		m_Renderer.DrawRect(m_Rect, true);

		m_Renderer.DrawRect(Rect{-2000,0,50,50}, true);
		m_Renderer.DrawRect(Rect{ -3000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -4000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -5000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -6000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -7000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -8000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -9000,0,50,50 }, true);
		m_Renderer.DrawRect(Rect{ -10000,0,50,50 }, true);

		m_Renderer.m_RenderCount = 0;
		
	}

	void HandleInput(Ember::Timestep timestep) {
		if (Ember::Input::IsKeyPressed(Ember::Key::Right)) {
			auto& camera = Ember::Application::GetApplication().GetRenderer().GetCamera();
			auto camPos = camera.GetPosition();
			camPos.x += m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Left)) {
			auto& camera = Ember::Application::GetApplication().GetRenderer().GetCamera();
			auto camPos = camera.GetPosition();
			camPos.x -= m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Up)) {
			auto& camera = Ember::Application::GetApplication().GetRenderer().GetCamera();
			auto camPos = camera.GetPosition();
			camPos.y -= m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
		if (Ember::Input::IsKeyPressed(Ember::Key::Down)) {
			auto& camera = Ember::Application::GetApplication().GetRenderer().GetCamera();
			auto camPos = camera.GetPosition();
			camPos.y += m_RectSpeed * timestep;
			camera.SetPosition(camPos);
		}
	}

private:
	Ember::Renderer& m_Renderer = Ember::Application::GetApplication().GetRenderer();;
	FRect m_Rect{ -1000,0,50,50 };
	int m_RectSpeed = 1000;
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