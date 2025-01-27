#pragma once

#include <string>
#include <unordered_set>

// #include <lua.hpp>

#include "Time/TimeManager.h"
#include "Input/InputManager.h"
#include "Event/EventManager.h"

class ScriptManager {
// public:
//     static ScriptManager& getInstance();

//     void executeScript(const std::string& filePath, int env);
//     void callFunction(const std::string& functionName, int env);
    
//     int createEnv();
//     void closeEnv(int env);

// private:
//     ScriptManager();
//     ~ScriptManager();

//     ScriptManager(const ScriptManager&) = delete;
//     ScriptManager& operator=(const ScriptManager&) = delete;
//     ScriptManager(ScriptManager&&) = delete;
//     ScriptManager& operator=(ScriptManager&&) = delete;

//     lua_State* m_luaState;
//     std::unordered_set<int> m_envs;

//     static int Time_getDeltaTime(lua_State* L);
//     static int Time_getElapsedTime(lua_State* L);
//     static int Time_getFPS(lua_State* L);
//     static int Input_isKeyPressed(lua_State* L);
//     static int Input_isKeyReleased(lua_State* L);
//     static int Input_isKeyRepeated(lua_State* L);
//     static int Input_isMouseButtonPressed(lua_State* L);
//     static int Input_isMouseButtonReleased(lua_State* L);
//     static int Input_getMousePosition(lua_State* L);
//     static int Input_getMouseDelta(lua_State* L);
//     static int Event_addListener(lua_State* L);
//     static int Event_removeListener(lua_State* L);
//     static int Event_addEvent(lua_State* L);
//     static int Event_removeEvent(lua_State* L);
};