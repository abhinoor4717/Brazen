#pragma once

#include "Core.h"

#include "spdlog\spdlog.h"
#include "spdlog\fmt\ostr.h"

namespace Ember {

	class EM_API Log
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

#ifdef EM_DEBUG

	// Core log macros
	#define EM_CORE_TRACE(...)    ::Ember::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define EM_CORE_INFO(...)     ::Ember::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define EM_CORE_WARN(...)     ::Ember::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define EM_CORE_ERROR(...)    ::Ember::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define EM_CORE_CRITICAL(...)    ::Ember::Log::GetCoreLogger()->critical(__VA_ARGS__)

	// Client log macros
	#define EM_TRACE(...)	      ::Ember::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define EM_INFO(...)	      ::Ember::Log::GetClientLogger()->info(__VA_ARGS__)
	#define EM_WARN(...)	      ::Ember::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define EM_ERROR(...)	      ::Ember::Log::GetClientLogger()->error(__VA_ARGS__)
	#define EM_CRITICAL(...)	      ::Ember::Log::GetClientLogger()->critical(__VA_ARGS__)

#else
	#define EM_CORE_TRACE(...)   
	#define EM_CORE_INFO(...)    
	#define EM_CORE_WARN(...)    
	#define EM_CORE_ERROR(...)   
	#define EM_CORE_CRITICAL(...)
	
	#define EM_TRACE(...)	     
	#define EM_INFO(...)	     
	#define EM_WARN(...)	     
	#define EM_ERROR(...)	     
	#define EM_CRITICAL(...)	 
#endif