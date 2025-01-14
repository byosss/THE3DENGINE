project("imgui")

# Créer une bibliothèque statique pour ImGui
add_library(${PROJECT_NAME} STATIC
    imgui.cpp
    imgui_draw.cpp
    imgui_widgets.cpp
    imgui_tables.cpp
    backends/imgui_impl_glfw.cpp
    backends/imgui_impl_opengl3.cpp
)

# Ajouter les include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/backends
)

# Lier les bibliothèques nécessaires
target_link_libraries(${PROJECT_NAME} PUBLIC glfw)