#pragma once

#include <string>

#include "Scripting/ScriptManager.h"

class Script {
public:
    // // Constructor
    // Script(const std::string& path) : scriptPath(path) {
    //     envName = ScriptingManager::getInstance().createEnv();
    // }
    // // Destructor
    // ~Script() {
    //     ScriptingManager::getInstance().closeEnv(envName);
    // }
    // // Load and Execute the script
    // void execute() {
    //     ScriptingManager::getInstance().executeScript(scriptPath, envName);
    // }
    // // Call a function from the script
    // void callFunction(const std::string& functionName) {
    //     ScriptingManager::getInstance().callFunction(functionName, envName);
    // }

private:
    std::string scriptPath;
    int envName;
};