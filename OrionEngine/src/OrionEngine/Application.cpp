#include "oepch.h"
#include "Application.h"
#include "OrionEngine/Log.h"
#include "OrionEngine/Events/ApplicationEvent.h"

namespace OrionEngine {

    Application::Application() {
    }

    Application::~Application() {
    }

    void Application::Run() {
        WindowResizeEvent e(1280, 720);
        if (e.IsInCategory(EventCategoryApplication)) {
            OE_TRACE(e.ToString());
        }
        if (e.IsInCategory(EventCategoryInput)) {
            OE_TRACE(e.ToString());
        }
        while (true);
    }
}