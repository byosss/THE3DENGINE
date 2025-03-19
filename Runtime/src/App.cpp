#include "App.h"

#include "config.h"

App::App()
{
    // Add a listener for the WindowCloseEvent
    Event.addListener<WindowCloseEvent>( [this]( const WindowCloseEvent& event ) {
        isRunning = false;
    });

    // Initialize the window
    Window.createWindow( 800, 600, "wowow" );
    Window.init( Event, Input );


    // Initialize the window context
    auto renderContext = Window.getRenderContext();
    Render.init( std::move( renderContext ) );

    // Load the scene
    // load( Scene );
}

App::~App()
{
    // Shutdown the application
    // -------------------------
    Render.terminate();
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
        Render.draw( Scene );
    }
}
