project("lua")

# add files from the source directory
file(GLOB_RECURSE SOURCES "src/*.c")

# add the executable
add_library(${PROJECT_NAME} STATIC ${SOURCES})
set_target_properties(glad PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(${PROJECT_NAME} PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
