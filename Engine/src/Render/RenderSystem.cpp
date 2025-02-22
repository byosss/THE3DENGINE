#include "RenderSystem.h"

namespace RenderSystem 
{
    void init( WindowManager& window ) 
    {
        // set glad
        if (!gladLoadGLLoader((GLADloadproc)window.getProcAddress())) {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }

        // set viewport
        glViewport(0, 0, window.getWidth(), window.getHeight());
        
        // set depth test
        glEnable(GL_DEPTH_TEST);
    }

    void draw( entt::registry& registry ) 
    {
        clear();
        // light_update(registry);
        // camera_update(registry);
        // model_update(registry);
    }

    void clear() 
    {
        // Clear the screen
        glClearColor( 0.2f, 0.2f, 0.2f, 1.0f );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
}