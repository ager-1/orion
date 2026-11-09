#pragma once
#include "Core.h"
#include "Events/Event.h"
namespace OrionEngine {

	class ORIONENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreateApplication();

}

