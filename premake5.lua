workspace "Brazen"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

project "Ember"
	location "Ember"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "empch.h"
	pchsource "Ember/src/empch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/SDL2/include",
		"%{prj.name}/src",
	}

	filter "action:vs*"
		libdirs { "Ember/vendor/SDL2/lib/msvc" }
	filter "action:gmake*"
		libdirs { "Ember/vendor/SDL2/lib/mingw" }

	postbuildcommands {
		"{MKDIR} ../bin/" .. outputdir .. "/Brazen",
		"{COPY} ../bin/Debug-windows-x86_64/Ember/Ember.dll ../" .. outputdir .. "/Brazen"
		-- "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Brazen"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		links {
			"SDL2",
			"SDL2main",
			"gdi32"
		}

		defines
		{
			"EM_PLATFORM_WINDOWS",
			"EM_BUILD_DLL"
		}

	filter "configurations:Debug"
		defines "EM_DEBUG"
		print("Debug mode")
		symbols "On"

	filter "configurations:Release"
		defines "EM_RELEASE"
		print("Release mode")
		optimize "On"

	filter "configurations:Dist"
		defines "EM_DIST"
		optimize "On"

project "Brazen"
	location "Brazen"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ember/vendor/spdlog/include",
		"Ember/src"
	}

	links
	{
		"Ember",
	}

	postbuildcommands {
		"{ECHO} Running brazen post build commands: abhinoor",
		"{ECHO} was supposed to run %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Brazen",
		"{COPY} %{wks.location}/Ember/vendor/SDL2/lib/SDL2.dll %{cfg.targetdir}",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"EM_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "EM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EM_DIST"
		optimize "On"
