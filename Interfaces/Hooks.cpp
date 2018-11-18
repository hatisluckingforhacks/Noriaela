#include "../main.h"
#include "../Hooks/index.h" // Index IDs
// Hacks
#include "../Hacks/skinchanger.h"

void InitializeInterfaces() {
    pSurface = GetInterface<ISurface>("./bin/osx64/vguimatsurface.dylib", "VGUI_Surface");
    pPanel = GetInterface<IPanel>("./bin/osx64/vgui2.dylib", "VGUI_Panel");
    pGameEventManager = GetInterface<IGameEventManager2>("./bin/osx64/engine.dylib", "GAMEEVENTSMANAGER002", true);
    pCvar = GetInterface<ICvar>("./bin/osx64/materialsystem.dylib", "VEngineCvar");
    pClient = GetInterface<IBaseClientDLL>("./csgo/bin/osx64/client_panorama.dylib", "VClient");
    pEngine = GetInterface<IEngineClient>("./bin/osx64/engine.dylib", "VEngineClient");
    pEntList = GetInterface<IClientEntityList>("./csgo/bin/osx64/client_panorama.dylib", "VClientEntityList");
    pOverlay = GetInterface<IVDebugOverlay>("./bin/osx64/engine.dylib", "VDebugOverlay");
    pEngineTrace = GetInterface<IEngineTrace>("./bin/osx64/engine.dylib", "EngineTraceClient");
    pModelInfo = GetInterface<IVModelInfo>("./bin/osx64/engine.dylib", "VModelInfoClient");
}

void InitializeVMTs() {
    GameEventVMT = new VMT(pGameEventManager);
    ClientVMT = new VMT(pClient);
    
    void* handle = dlopen("./csgo/bin/osx64/client_panorama.dylib", RTLD_NOLOAD | RTLD_NOW);
    RandomInt = reinterpret_cast<RandomIntFn>(dlsym(handle, "RandomInt"));
    dlclose(handle);
}

void InitializeHooks() {
    GameEventVMT->HookVM((void*)hkFireEventClientSide, FireGameEventIndex);
    GameEventVMT->ApplyVMT();
    ClientVMT->HookVM((void*)hkFrameStage, FrameStageIndex);
    ClientVMT->ApplyVMT();

    g_pSequence = (RecvVarProxyFn)NetVarManager::HookProp("DT_BaseViewModel", "m_nSequence", HSequenceProxyFn);
    pCvar->ConsoleColorPrintf(Color::Green(),   "Successfully injected Noriaela\n");
}

void PrintInfo() {
    pCvar->ConsoleColorPrintf(Color::Red(),     "Noriaela Version 3");
    pCvar->ConsoleColorPrintf(Color::Red(),     "Coded by :\n");
    pCvar->ConsoleColorPrintf(Color::Red(),     "Warlauke\n");
    pCvar->ConsoleColorPrintf(Color::Green(),   "Gloves added.\n");
}
