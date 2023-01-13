#ifndef _DC_ENGINE_
#define _DC_ENGINE_

typedef enum
{
    GS_MAIN_MENU,
    GS_CONTRACT,
    GS_GAME_LOOP,
    GS_GAME_OVER
} GameState;



typedef struct
{
    EGameState CurrentGameState = EGameState::GS_MAIN_MENU;

} Engine;
Engine EngineInstance;

/* Engine Methods  */

void Init(Engine * EnginePtr);

void Update(Engine * EnginePtr);

void Close(Engine * EnginePtr);


/* Gamestate Change */

v

#endif