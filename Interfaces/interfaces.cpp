#include "../main.h"

ISurface* pSurface = nullptr;
IPanel* pPanel = nullptr;
ICvar* pCvar = nullptr;
IGameEventManager2* pGameEventManager = nullptr;
IBaseClientDLL* pClient = nullptr;
IClientEntityList* pEntList = nullptr;
IVDebugOverlay* pOverlay = nullptr;
IEngineClient* pEngine = nullptr;
IVModelInfo* pModelInfo = nullptr;
IEngineTrace* pEngineTrace = nullptr;
IClientMode* pClientMode = nullptr;

RecvVarProxyFn g_pSequence  = nullptr;

RandomIntFn RandomInt;


VMT* GameEventVMT = nullptr;
VMT* ClientVMT = nullptr;
