project("glad")

# Créer une bibliothèque statique pour Glad
add_library(${PROJECT_NAME} STATIC
    glad/glad.c
)

# Ajouter les include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)