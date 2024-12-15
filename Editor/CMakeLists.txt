project(Editor)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED Widgets OpenGL)

set(PROJECT_SOURCES
        main.cpp
        OpenGLWindow.h
        OpenGLWindow.cpp
)

add_executable(Editor ${PROJECT_SOURCES})

target_link_libraries(Editor PRIVATE Engine)
target_link_libraries(Editor PRIVATE Qt6::Widgets Qt6::OpenGL)
