workspace "Leecode"
    architecture "x64"
    startproject "Daily_Practice"
    configurations
	{
		"Debug"
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
        "%{prj.name}/CXX20_Practice/**.h",
        "%{prj.name}/CXX20_Practice/**.cpp"
    }

    removefiles
    {
        "%{prj.name}/Leecode/**.h",
        "%{prj.name}/Leecode/**.cpp",
        "%{prj.name}/CXX20_Practice/**.h",
        "%{prj.name}/CXX20_Practice/**.cpp"
    }
    
    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"