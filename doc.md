# Project-Documentation

## 1.Contents
1. Contents
2. Subject specification
3. Scenario
    3.1. scene and objects description
    3.2. functionalities
4. Implementation details
    4.1. functions and special algorithms
           4.1.1. possible solutions
           4.1.2. the motivation of the chosen approach
    4.2. graphics model
    4.3. data structures
    4.4. class hierarchy
5. Graphical user interface presentation / user manual
6. Conclusions and further developments
7. References

## 2.Subject Specification

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
