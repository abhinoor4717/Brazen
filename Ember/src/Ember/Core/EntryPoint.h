#pragma once

#ifdef EM_PLATFORM_WINDOWS

extern Ember::Application* Ember::CreateApplication();

#include "Log.h"

int main(int agrc, char** argv) {

	Ember::Log::Init();

	EM_CORE_INFO("Welcome to Ember Engine!");

	auto app = Ember::CreateApplication();
	app->Run();
	delete app;

}

#endif