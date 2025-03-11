#include <Ember.h>

class Brazen : public Ember::Application {
public:
	Brazen() {}
	~Brazen() {}
};

Ember::Application* Ember::CreateApplication() {
	return new Brazen();
}