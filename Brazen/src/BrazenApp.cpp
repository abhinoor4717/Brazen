#include <Ember.h>

class MyLayer : public Ember::Layer {
public:
	MyLayer() : Layer("My Layer") {

	}
	~MyLayer() {}

	void OnUpdate(Ember::Renderer& r) override {
		//r.FillScreen({ 0, 149, 255, 255 });
		r.DrawRect(m_Rect, true);
		m_Rect.pos.x += 0.1;
		if (m_Rect.pos.x >= 800)
			m_Rect.pos.x = 0;
	}
private:
	FRect m_Rect = { 0,0,10,10 };
};
class MyLayerTwo : public Ember::Layer {
public:
	MyLayerTwo() : Layer("My Layer") {
		EM_INFO("Mylayer2 initilized!");
	}
	~MyLayerTwo() {}

	void OnUpdate(Ember::Renderer& r) override {
		EM_INFO("Layer update!");
		//r.FillScreen({ 0, 149, 255, 255 });
		r.DrawRect(m_Rect, true);
		m_Rect.pos.x += 0.2;
		if (m_Rect.pos.x >= 800)
			m_Rect.pos.x = 0;
	}
private:
	FRect m_Rect = { 0,0,10,10 };
};

class Brazen : public Ember::Application {
public:
	Brazen() {
		GetLayerStack()->PopLayer();
		//GetLayerStack()->PushBackLayer(new MyLayer());
		GetLayerStack()->PopBackLayer(new MyLayerTwo());
	}
	~Brazen() {}
};

Ember::Application* Ember::CreateApplication() {
	return new Brazen();
}