workspace "Leecode"
    architecture "x64"
    startproject "Daily_Practice"
    configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Daily_Practice"
    location "Daily_Practice"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Leecode/**.h",
        "%{prj.name}/Leecode/**.cpp",
        "%{prj.name}/interview/**.h",
        "%{prj.name}/interview/**.cpp",
        "%{prj.name}/CXX20_Practice/**.h",
        "%{prj.name}/CXX20_Practice/**.cpp"
    }

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

	filter "configurations:Release"
		runtime "Release"
		optimize "On"

    -- Visual Studio Setting
    filter { "action:vs*" }
        removefiles { "**.cpp" }
    filter {}

    -- XCode Setting
    filter { "action:xcode4" }
        xcodebuildsettings {
            ["GCC_INPUT_FILE_ENCODING"] = "UTF-8",
        }
    filter {}

    filter { "action:xcode4", "files:**.cpp" }
        flags { "ExcludeFromBuild" }
    filter {}
