#include <Ember.h>

class BackGround : public Ember::Layer {
public:
	BackGround() : Layer("Background") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		m_Renderer.FillScreen();
	}
private:
	Ember::Renderer& m_Renderer = Ember::Application::GetApplication().GetRenderer();;

};

class ForeGround : public Ember::Layer {
public:
	ForeGround() : Layer("Foreground") {}
	void EventHandler(Ember::Event& e) override {}

	void OnUpdate(Ember::Timestep timestep) override {
		if (Ember::Input::IsKeyPressed(Ember::Key::Right)) {
			EM_TRACE("{0}", timestep.GetMilliseconds());
			m_Rect.pos.x += m_RectSpeed * timestep.GetSeconds()+1;
		}
		if (m_Rect.pos.x >= 1280)
			m_Rect.pos.x = 0;
		m_Renderer.DrawRect(m_Rect, true);
		
	}

private:
	Ember::Renderer& m_Renderer = Ember::Application::GetApplication().GetRenderer();;
	FRect m_Rect{ 0,0,10,10 };
	int m_RectSpeed = 1;
};
	
class Brazen : public Ember::Application {
public:
	Brazen() {

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