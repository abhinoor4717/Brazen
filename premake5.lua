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

	libdirs {
		"Ember/vendor/SDL2/lib"
	}

	links {
		"SDL2",
		"SDL2main",
		"gdi32"
	}

	postbuildcommands
		{
			"{MKDIR} ../bin/" .. outputdir .. "/Brazen",
			"{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Brazen"
		}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"
		-- linkoptions { "/NODEFAULTLIB:LIBCMTD.lib", "/NODEFAULTLIB:msvcprtd.lib" }

		defines
		{
			"EM_PLATFORM_WINDOWS",
			"EM_BUILD_DLL"
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
		"%{prj.name}/vendor/SDL2/include",
		"Ember/src"
	}

	libdirs {
		"Ember/vendor/SDL2/lib"
	}

	links
	{
		"Ember",
		"SDL2",
		"SDL2main"
	}

	postbuildcommands {
		"{COPY} ../Ember/vendor/SDL2/SDL2.dll ../bin/" .. outputdir .. "/Brazen"
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
