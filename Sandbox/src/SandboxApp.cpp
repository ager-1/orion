#include <cstdint>
#include <crtdbg.h>
#include <cstddef>
#include <OrionEngine.h>
class ExampleLayer :public OrionEngine::Layer {
public:
	ExampleLayer()
		:Layer("Example"){ }
	void OnUpdate() override {
		//OE_INFO("ExampleLayer::Update");
	}
	void OnEvent(OrionEngine::Event& event) override {
		OE_TRACE("{0}", event.ToString());
	}

};
class Sandbox : public OrionEngine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new OrionEngine::ImGuiLayer());
	}
	~Sandbox() {

	}
};
OrionEngine::Application* OrionEngine::CreateApplication() {
	return new Sandbox();
}