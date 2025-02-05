# THE3DENGINE

**THE3DENGINE** is a 3D game engine developed in C++ with a focus on modularity. It consists of 3 main components:

- **Engine**: A dynamic library that contains the core game engine code, including rendering, physics, etc...
- **Editor**: The graphical interface used for level editing and game development. (not implemented yet)
- **Runtime**: The executable that runs the game using the engine.

## Prerequisites

- **C++ Compiler**: Ensure you have a C++ compiler that supports C++17 or higher.
- **CMake**: Version 3.10 or higher is required for building the project.

## Dependecies

- **GLFW**: For window creation and input handling.
- **GLAD**: For OpenGL loading.
- **EnTT**: For entity-component-system.
- **Lua**: For scripting.
- **ImGui**: For the editor interface.

## Building

1. Clone the repository.
2. Run the following commands in the root directory of the project:

```bash
mkdir build
cd build
cmake ..
make
```

## Running

After building the project, you can run the engine by executing the following command in the build directory:

```bash
./Runtime
```

## License

This project is licensed under the MIT License.  2025
