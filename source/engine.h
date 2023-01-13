#ifndef _DC_ENGINE_
#define _DC_ENGINE_

// screw you code formatter, this one needs to stay on top
#include <stdlib.h>
// now we need to have libgte.h
#include <libgte.h>
// then, these can work; the psyq library is badly written and won't include what it uses
#include <libetc.h>
#include <libgpu.h>
#include <stdio.h>
#include <types.h>

#include "dcMath.h"
#include "dcCamera.h"
#include "render.h"
#include "dcMemory.h"
#include "dcMisc.h"
#include "dcCollision.h"

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