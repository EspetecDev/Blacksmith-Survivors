#ifndef _DC_ENGINE_
#define _DC_ENGINE_

typedef enum
{
    GS_MAIN_MENU,
    GS_CONTRACT,
    GS_GAME_LOOP,
    GS_GAME_OVER,
} EGameState;

typedef struct
{
    EGameState CurrentGameState;
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