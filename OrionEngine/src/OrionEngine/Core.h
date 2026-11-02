#pragma once

#ifdef OE_PLATFORM_WINDOWS
	#ifdef OE_BUILD_DLL
		#define ORIONENGINE_API __declspec(dllexport)
	#else
		#define ORIONENGINE_API __declspec(dllimport)
	#endif
#else
	#error Orion Engine only supports Windows!
#endif