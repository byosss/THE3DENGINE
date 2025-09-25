# THE3DENGINE

![C++23](https://img.shields.io/badge/C%2B%2B-23-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.30+-brightgreen.svg)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)

**THE3DENGINE** is a 3D game engine developed in (modern) c++ with a focus on modularity. It consists of 3 main components:

- **Engine**: The core of the engine, responsible for rendering, physics, and other core functionalities.
- **Editor**: A graphical user interface for creating and editing game scenes (not implemented yet).
- **Client**: Runtime application for running games created with the engine.

## Prerequisites

- **C++ Compiler**: Standard **C++23** or higher is required.
- **CMake**: Version **3.30** or higher is required.

## Dependencies

- **Qt6**: For the editor GUI (*not implemented yet*).
- **GLAD**: For OpenGL loading (not implemented yet).
- **Lua**: For scripting (not implemented yet).

## Building

1. Clone the repository.
```bash
git clone https://github.com/byosss/THE3DENGINE.git
cd THE3DENGINE
```

2. Create a build directory.
```bash
mkdir build
cd build
```

3. Compile the project using CMake
```bash
cmake ..
cmake --build .
```

## License

This project is licensed under the MIT License.
