#ifndef _DC_ENGINE_
#define _DC_ENGINE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcMemory.h"
#include "dcMisc.h"
#include "dcCollision.h"
#include "render.h"

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
    SDC_Render * RenderPtr;

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