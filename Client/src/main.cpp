import engine.core.config;
import engine.core.context;
import engine.core.scheduler;
import engine.core.loop;

import std;

using namespace engine;

int main(int argc, char* argv[]) try
{
    // Config config = Config::from_file("config.toml");

    // Context context (
    //     std::make_unique<event::Bus>(config),
    //     std::make_unique<time::Clock>(config),
    //     std::make_unique<input::State>(config),
    //     std::make_unique<asset::Store>(config),
    //     std::make_unique<scene::Director>(config)
    // );

    // Scheduler scheduler;

    // scheduler.enqueue<physics::World>(Phase::Fixed);
    // scheduler.enqueue<graphics::Renderer>(Phase::Render);

    // Loop loop(context, scheduler);

    return 0;

} catch (const std::exception &e) {
    std::cerr << "Unhandled exception: " << e.what() << std::endl;
    return 1;
}