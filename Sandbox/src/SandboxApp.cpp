#include <cstdint>
#include <crtdbg.h>
#include <cstddef>
#include <OrionEngine.h>
class Sandbox : public OrionEngine::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};
OrionEngine::Application* OrionEngine::CreateApplication() {
	return new Sandbox();
}