# Project-Documentation

## 1. Contents
- 1. Contents
- 2. Subject specification
- 3. Scenario
- 4. Implementation details
- 5. Graphical user interface presentation / user manual
- 6. Conclusions and further developments

## 2. Subject Specification

### Project Overview
The project is a rendering engine utilizing the OpenGL API and implemented in C++. Its primary goal is to serve as an optimized yet powerful engine capable of real-time modification of certain 3D object attributes, such as position, rotation, scaling, and lighting effects.

### Project Structure
- `src/`: Contains source files.
- `include/`: Header files.
- `lib/`: External libraries used by the project.
- `vendor/`: Third-party dependencies or external integrated libraries.
- `assets/`: Project resources (shaders, textures, etc.).
- `build/`: Directory generated during project build.

### Build and Run Instructions using CMake
Generate Build Files:
Open a terminal and navigate to the project root directory.
Move into the 'build' directory: cd build
Run CMake to generate build files: cmake exam

Build the Project:
After CMake successfully generates the build files, execute the build process: cmake --build .

Run the Project:
Once the build process is complete, you can run the executable generated in the 'build' directory : ./exam

## 3. Scenario

### scene and objects description

The project revolves around three categories of classes:

- General (Engine, TimeManager, InputManager).
- Objects (Model3D, Light, DirectionalLight, SpotLight, Skybox, Camera).
- Resources (Shader, Texture, Mesh).

General objects are instantiated once, with the Engine class at the core of application logic. It handles scene loading, the main loop, object interactions, and manages the TimeManager and InputManager.

Objects, such as Model3D and various lights, are instantiated and stored in std::vectors as needed. All objects support dynamic modifications such as real-time changes in position, rotation, and scale.

Resource objects, including Shader, Texture, and Mesh, ensure the management of graphical resources. Shader compilation and management are handled for rendering, while Texture and Mesh enable dynamic modifications and graphical optimization.
