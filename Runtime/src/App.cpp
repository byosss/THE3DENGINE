#include "App.h"

App::App() : Time(),
             Event(),
             Input(),
             Scene(),
             Window( Event, Input ),
             isRunning( false )
{
    // Initialize the application
    // --------------------------

    Window.setVSync( false );

    // Initialize the window context
    Renderer = Renderer::Create( API::OpenGL );
    Renderer->init( Window.getHandle() );

    // Add a listener for the WindowCloseEvent
    Event.addListener<WindowCloseEvent>( [this]( const WindowCloseEvent& event ) {
        isRunning = false;
    });

    // Load the scene
    Scene.load();
}

App::~App()
{
    // Shutdown the application
    // -------------------------
    Renderer->shutdown();
}

void App::run()
{
    // Setup the scene
    Scene.setup( Time, Event, Input );

    // Run the gameloop
    isRunning = true;
    while ( isRunning )
    {
        // Update delta time
        Time.tick();

        // Poll events
        Window.pollEvents();

        // Update input
        Input.update();

        // Dispatch events
        Event.dispatchEvents();

        // Update Game Logic
        Scene.update( Time, Event, Input );

        // Fixed Time Step
        while ( Time.fixedTimeStep() ) 
        {
            // Update Physics
            PhysicSystem::simulate( Scene.getRegistry() );

            // Accumulate Time
            Time.fixedTimeStepEnd();
        }

        // Render
        Renderer->draw( Scene );

        // Swap Buffers
        Window.swapBuffers();
    }
}
