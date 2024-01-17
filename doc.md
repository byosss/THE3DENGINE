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

### 3.1 Scene and objects description

The virtual scene crafted for this project serves as a demonstration, showcasing the capabilities of the rendering engine. It encompasses key elements designed to highlight various features:

- Camera Control: Users can manipulate the camera using intuitive controls, such as the WASD keys, providing a firsthand experience of dynamic exploration within the 3D environment.

- Model3D Instances: Multiple instances of the Model3D class populate the scene, presenting diverse objects with distinct meshes, textures, and shaders. These objects demonstrate the rendering engine's ability to handle complex 3D models.

- Lights Variety: The scene incorporates different types of lights, including PointLight, DirectionalLight, and SpotLight. This variety showcases the engine's capacity to handle various lighting scenarios, contributing to the visual richness of the scene.
    Dynamic PointLight Manipulation: Users can dynamically add and remove PointLight sources during runtime using the Up and Down keys. This interactive feature demonstrates the engine's real-time adaptability to changes in the lighting environment.

This curated scene not only serves as a demonstration but also provides a hands-on experience for users to interact with and appreciate the rendering engine's capabilities in handling cameras, complex 3D models, and diverse lighting scenarios.

### 3.2 Functionalities

The scene incorporates several key functionalities to enhance user interaction:

**Camera Movement:**
The scene allows the user to control the camera using the **WASD keys** for movement. This enables dynamic exploration of the 3D environment.

**Wireframe Mode Toggle:**
Pressing and holding the **Q key** toggles the wireframe mode for Model3D objects. This feature provides a visual representation of the object's wireframe structure.

**Dynamic PointLight Manipulation:**
The **Up key** dynamically adds PointLight objects to the scene, contributing to real-time changes in lighting. Conversely, the **Down key** removes PointLights as needed.

**Application Termination:**
Pressing the **Escape (Esc) key** allows the user to gracefully exit the application, providing a convenient way to terminate the program.

## 4. Implementation details

### 4.1 Functions and special algorithms
#### 4.1.1. Possible Solutions

In handling the core logic of the application, a central class named Engine has been designed. The Engine class is responsible for orchestrating key aspects of the program, including:

- Scene Loading: Manages the loading and initialization of the virtual scene. This involves loading 3D models, textures, and other assets required for the scene's composition.

- Main Rendering Loop: Orchestrates the main rendering loop, ensuring the continuous update and display of the graphical elements within the scene. This loop is crucial for maintaining real-time interactivity and responsiveness.

- Time Management: For precise control over time-related functionalities, a separate TimeManager class has been introduced. This class provides methods for measuring frame times, handling delta time calculations, and controlling the overall temporal aspects of the application.

- Input Handling: The Engine class interfaces with an InputManager to efficiently manage user inputs. This includes handling keyboard, mouse, and potentially other input devices. The InputManager class abstracts away the intricacies of handling various input sources.

- Resource Management (Future Consideration): While not implemented at the moment, a ResourceManager class is anticipated in the future. This class would be responsible for managing and optimizing the usage of resources such as textures, models, and shaders. Its inclusion would further enhance the scalability and performance of the application as it evolves.

#### 4.1.2. The Motivation of the Chosen Approach

The decision to centralize the application's logic within the Engine class stems from the need for a modular and extensible design. This approach allows for easy integration of new features, facilitates code organization, and enhances the maintainability of the project.

The introduction of dedicated classes like TimeManager and InputManager serves to encapsulate specific functionalities, promoting a clean separation of concerns. This modular structure not only improves code readability but also simplifies debugging and future updates.

The envisioned ResourceManager class reflects a forward-looking approach, anticipating the potential growth of the project. By segregating resource-related tasks, it will enable efficient resource utilization and aid in the seamless integration of additional content as the application evolves.

### 4.2. Graphics Model

Each Model3D instance is associated with a shader, containing instructions for rendering surfaces. Within a Model3D, multiple meshes exist, each potentially linked to one or more textures. During the main rendering loop:

- Lighting Calculation: The Engine computes lighting effects for the scene.

- Shader Activation: The Engine activates each Model3D's shader for rendering.

- Mesh Rendering: The Engine calls a draw function on each mesh, rendering individual components. This process repeats for all meshes, efficiently rendering the entire 3D scene.

### 4.3. Data Structures

Currently, for simplicity, instances of Model3D and various lights are stored in std::vector containers as attributes of the Engine class. This straightforward approach facilitates ease of implementation and quick access to the necessary components during the rendering process.

However, as part of future enhancements, there is a planned introduction of a dedicated Scene class. The Scene class will serve to unify and manage the different elements within the virtual environment, providing a more organized and extensible structure. This abstraction aims to enhance code clarity, maintainability, and scalability as the project evolves.

### 4.4. class hierarchy

The project revolves around three categories of classes:

- General (Engine, TimeManager, InputManager).
- Objects (Model3D, Light, DirectionalLight, SpotLight, Skybox, Camera).
- Resources (Shader, Texture, Mesh).

General objects are instantiated once, with the Engine class at the core of application logic. It handles scene loading, the main loop, object interactions, and manages the TimeManager and InputManager.

Objects, such as Model3D and various lights, are instantiated and stored in std::vectors as needed. All objects support dynamic modifications such as real-time changes in position, rotation, and scale.

Resource objects, including Shader, Texture, and Mesh, ensure the management of graphical resources. Shader compilation and management are handled for rendering, while Texture and Mesh enable dynamic modifications and graphical optimization.

## 5. user manual

Camera Movement: **WASD keys** for camera movement.

Wireframe Mode : hold **Q key** to switch in wireframe mode for Model3D objects.

Dynamic PointLight Manipulation: **Up key** to add PointLight objects, **Down key** to remove PointLights.

Application Termination: **Escape (Esc) key** to gracefully exit the application.

## 6. Conclusions and Further Developments

In conclusion, the present implementation lays a strong foundation for the project's core functionalities. As we look towards the future, several key areas for improvement and expansion have been identified:

- Culling Optimization: Implement advanced culling techniques to enhance rendering efficiency by selectively excluding objects outside the view frustum.

- Shadow Rendering: Explore and integrate shadow mapping techniques to introduce realistic shadow effects, adding depth and dimensionality to the scenes.

- Graphical User Interface (GUI) Refinement: Enhance the GUI with interactive elements and improved user feedback, ensuring a more intuitive and polished user experience.

- Resource Management System: Develop a robust ResourceManager class to efficiently handle and optimize the loading and unloading of graphical resources, contributing to improved performance.

These proposed developments aim to elevate the overall quality of the application, introducing advanced rendering features and optimizing resource utilization for a more immersive and efficient user experience.

## 7. References

https://learnopengl.com/
