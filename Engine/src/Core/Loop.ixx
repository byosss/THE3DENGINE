export module engine.core.loop;

import engine.core.context;
import engine.core.scheduler;

import std;

namespace engine {

    export class Loop {
    public:
        Loop(Context& context, Scheduler& scheduler) : context_(context), scheduler_(scheduler) {

        }

        ~Loop() {

        }

        int run() {

            return 0;
        }


        void step(std::chrono::steady_clock::duration dt) {

        }

    private:
        Context& context_;
        Scheduler& scheduler_;

        bool running = false;
    };

} // namespace engine