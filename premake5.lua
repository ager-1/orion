workspace "OrionEngine"
    architecture "x64"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "OrionEngine"
    location "OrionEngine"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    pchheader "oepch.h"
    pchsource "OrionEngine/src/oepch.cpp"

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "OrionEngine/src"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {"/utf-8"}
        defines
        {
            "OE_PLATFORM_WINDOWS",
            "OE_BUILD_DLL"
        }
        postbuildcommands
        {
            ("{COPYDIR} \"%{cfg.buildtarget.relpath}\" \"../bin/" .. outputdir .. "/Sandbox\"")
        }

    filter "configurations:Debug"
        defines "OE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "OE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
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
        "OrionEngine/vendor/spdlog/include",
        "OrionEngine/src"
    }

    links 
    {
        "OrionEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"
        buildoptions {"/utf-8"}
        defines
        {
            "OE_PLATFORM_WINDOWS"
        }     

    filter "configurations:Debug"
        defines "OE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "OE_DIST"
        optimize "On"