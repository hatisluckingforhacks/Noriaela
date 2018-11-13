cmake_minimum_required(VERSION 3.12)
project(Noriaela)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./bin)

set(SOURCE_FILES main.cpp main.h Hacks/skinchanger.cpp Hacks/skinchanger.h hacks.h Hooks/framestage.cpp Hooks/firegameevent.cpp Interfaces/Hooks.cpp Interfaces/Hooks.h Interfaces/interfaces.cpp Interfaces/interfaces.h SDK/C_BaseEntity.h SDK/Vector.h SDK/Color.h SDK/common.h SDK/CUserCmd.h SDK/GameEvent.h SDK/IBaseClientDLL.h SDK/IClientEntityList.h SDK/ICvar.h SDK/IEngineClient.h SDK/IEngineTrace.h SDK/IMaterial.h SDK/IPanel.h SDK/ISurface.h SDK/IVDebugOverlay.h SDK/IVModelInfo.h SDK/netvarmanager.cpp SDK/netvarmanager.h SDK/offsets.cpp SDK/offsets.h SDK/Others.h SDK/VMatrix.h SDK/VMT.h)
add_library(Noriaela SHARED ${SOURCE_FILES})
