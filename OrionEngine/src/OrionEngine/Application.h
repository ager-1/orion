#pragma once
#include "Core.h"
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

