project(Engine LANGUAGES CXX)

add_library(Engine STATIC)

target_sources(Engine
    PUBLIC
    FILE_SET modules TYPE CXX_MODULES FILES

        src/Types.ixx

        src/Core/Loop.ixx
        src/Core/Config.ixx
        src/Core/Context.ixx
        src/Core/Scheduler.ixx
#
#        src/System/Graphics/Graphics.ixx
#
#        src/System/Physics/Physics.ixx
#
#        src/Service/Time/Time.ixx
#        src/Service/Time/Clock.cppm
#        src/Service/Time/Utils.cppm
#
#        src/Base/Math/Math.ixx
#        src/Base/Math/Vector/Vector.cppm
#        src/Base/Math/Vector/Vector3.cppm
#
#        src/Log/Log.ixx
#
#        src/Platform/Platform.ixx
#        src/Platform/Window.cppm
#        src/Platform/Event.cppm

    PRIVATE
#        $<$<PLATFORM_ID:Windows>:src/Platform/Windows/Window.cpp>
#        $<$<PLATFORM_ID:Windows>:src/Platform/Windows/Event.cpp>
)
