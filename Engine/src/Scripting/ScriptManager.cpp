#include "ScriptManager.h"

// ScriptManager& ScriptManager::getInstance() {
//     static ScriptManager instance;
//     return instance;
// }

// ScriptManager::ScriptManager() : m_luaState(luaL_newstate()) 
// {
//     if (!m_luaState) {
//         std::cerr << "Failed to create Lua state" << std::endl;
//         return;
//     }

//     luaL_openlibs(m_luaState);

//     // Register Time functions
//     lua_pushcfunction(m_luaState, Time_getDeltaTime);
//     lua_setfield(m_luaState, -2, "getDeltaTime");
//     lua_pushcfunction(m_luaState, Time_getElapsedTime);
//     lua_setfield(m_luaState, -2, "getElapsedTime");
//     lua_pushcfunction(m_luaState, Time_getFPS);
//     lua_setfield(m_luaState, -2, "getFPS");
//     lua_setglobal(m_luaState, "Time");

//     // Register Input functions
//     lua_pushcfunction(m_luaState, Input_isKeyPressed);
//     lua_setfield(m_luaState, -2, "isKeyPressed");
//     lua_pushcfunction(m_luaState, Input_isKeyReleased);
//     lua_setfield(m_luaState, -2, "isKeyReleased");
//     lua_pushcfunction(m_luaState, Input_isKeyRepeated);
//     lua_setfield(m_luaState, -2, "isKeyRepeated");
//     lua_pushcfunction(m_luaState, Input_isMouseButtonPressed);
//     lua_setfield(m_luaState, -2, "isMouseButtonPressed");
//     lua_pushcfunction(m_luaState, Input_isMouseButtonReleased);
//     lua_setfield(m_luaState, -2, "isMouseButtonReleased");
//     lua_pushcfunction(m_luaState, Input_getMousePosition);
//     lua_setfield(m_luaState, -2, "getMousePosition");
//     lua_pushcfunction(m_luaState, Input_getMouseDelta);
//     lua_setfield(m_luaState, -2, "getMouseDelta");
//     lua_setglobal(m_luaState, "Input");

//     // Register Event functions
//     lua_pushcfunction(m_luaState, Event_addListener);
//     lua_setfield(m_luaState, -2, "addListener");
//     lua_pushcfunction(m_luaState, Event_removeListener);
//     lua_setfield(m_luaState, -2, "removeListener");
//     lua_pushcfunction(m_luaState, Event_addEvent);
//     lua_setfield(m_luaState, -2, "addEvent");
//     lua_pushcfunction(m_luaState, Event_removeEvent);
//     lua_setfield(m_luaState, -2, "removeEvent");
//     lua_setglobal(m_luaState, "Event");

//     // Expose the constants KEY
//     lua_newtable(m_luaState);
//     lua_pushinteger(m_luaState, KEY::PRESS);
//     lua_setfield(m_luaState, -2, "PRESS");
//     lua_pushinteger(m_luaState, KEY::RELEASE);
//     lua_setfield(m_luaState, -2, "RELEASE");
//     lua_pushinteger(m_luaState, KEY::REPEAT);
//     lua_setfield(m_luaState, -2, "REPEAT");
//     lua_pushinteger(m_luaState, KEY::A);
//     lua_setfield(m_luaState, -2, "A");
//     lua_pushinteger(m_luaState, KEY::B);
//     lua_setfield(m_luaState, -2, "B");
//     // ... Add the other keys in the same way
//     lua_setglobal(m_luaState, "KEY");

//     // Expose the constants MOUSE
//     lua_newtable(m_luaState);
//     lua_pushinteger(m_luaState, MOUSE::PRESS);
//     lua_setfield(m_luaState, -2, "PRESS");
//     lua_pushinteger(m_luaState, MOUSE::RELEASE);
//     lua_setfield(m_luaState, -2, "RELEASE");
//     lua_pushinteger(m_luaState, MOUSE::LEFT);
//     lua_setfield(m_luaState, -2, "LEFT");
//     // ... Add the other mouse buttons in the same way
//     lua_setglobal(m_luaState, "MOUSE");

//     // Register Math functions ?
//     // Register Scene functions ?

//     lua_newmetatable(m_luaState, "env_meta");
//     lua_pushstring(m_luaState, "__index");
//     lua_pushvalue(m_luaState, LUA_GLOBALSINDEX);
//     lua_settable(m_luaState, -3);
//     lua_pop(m_luaState, 1);
// }

// ScriptManager::~ScriptManager() {
//     for (int env : m_envs) {
//         luaL_unref(m_luaState, LUA_REGISTRYINDEX, env);
//     }
//     lua_close(m_luaState);
// }

// // global meta table __index for env to share global variables between scripts such as Time, Input, Event
