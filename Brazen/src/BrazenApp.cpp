#include <Ember.h>

class TestLayer : public Ember::Layer {
public:
	TestLayer() : Layer("Test") {}
	~TestLayer() {}

	void EventHandler(Ember::Event& e) override {
		EM_TRACE("{0} recieved event {1}", GetName(), e);
	}
};


class Brazen : public Ember::Application {
public:
	Brazen() {
		
	}
	~Brazen() {}
};

Ember::Application* Ember::CreateApplication() {
	return new Brazen();
}