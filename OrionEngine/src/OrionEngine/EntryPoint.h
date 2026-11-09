#pragma once
#ifdef OE_PLATFORM_WINDOWS
extern OrionEngine::Application* OrionEngine::CreateApplication();
int main(int argc, char** argv) 
{
	OrionEngine::Log::Init();
	OE_CORE_WARN("Initialized Log!");
	OE_INFO("Hello!");
	auto app = OrionEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif