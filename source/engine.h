#ifndef _DC_ENGINE_
#define _DC_ENGINE_

#include "GameStates/game_loop_gamestate.h"

typedef enum
{
    GS_UNDEFINED,
    GS_MAIN_MENU,
    GS_CONTRACT,
    GS_GAME_LOOP,
    GS_GAME_OVER,
} EGameState;

typedef struct
{
    EGameState CurrentGameState;
    EGameState DesiredGameState;
    FGameLoopGameState* GameLoopGameState;

} Engine;

// Global var.
Engine GEngineInstance;

/* Engine Methods  */

void Init(Engine * EnginePtr);

void Update(Engine * EnginePtr);

void Close(Engine * EnginePtr);

/* Gamestate Change */

void ChangeGameState(Engine * EnginePtr, EGameState NewGameState);

#endif