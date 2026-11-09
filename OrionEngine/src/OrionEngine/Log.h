#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
namespace OrionEngine {

	class ORIONENGINE_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}
//Core Log Macros
#define OE_CORE_TRACE(...)	::OrionEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OE_CORE_INFO(...)	::OrionEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OE_CORE_WARN(...)	::OrionEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OE_CORE_ERROR(...)	::OrionEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OE_CORE_FATAL(...)	::OrionEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log Macros
#define OE_TRACE(...)		::OrionEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OE_INFO(...)		::OrionEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define OE_WARN(...)		::OrionEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OE_ERROR(...)		::OrionEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define OE_FATAL(...)		::OrionEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)