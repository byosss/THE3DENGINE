#include "Core/Application.h"
#include <iostream>

int main() {
    try {
        Application app;
        
        app.init();
        app.run();
        app.terminate();

        return 0;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
}