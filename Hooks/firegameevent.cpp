#include "../main.h"
#include "index.h" // Index IDs
// Hacks
#include "../Hacks/skinchanger.h"

bool hkFireEventClientSide(void* thisptr, IGameEvent* event){
    if(event){
        skinchanger->FireEventClientSide(event);
    }
    return GameEventVMT->GetOriginalMethod<tFireGameEvent>(FireGameEventIndex)(thisptr, event);
}
