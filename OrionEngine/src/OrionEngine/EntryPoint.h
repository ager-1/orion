#pragma once
#ifdef OE_PLATFORM_WINDOWS
extern OrionEngine::Application* OrionEngine::CreateApplication();
int main(int argc, char** argv) 
{
	auto app = OrionEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif