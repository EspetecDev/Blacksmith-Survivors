#ifndef _DC_GAME_LOOP_GAMESTATE
#define _DC_GAME_LOOP_GAMESTATE

#include "dcMath.h"
#include "dcCamera.h"

typedef struct
{
    SDC_Camera PlayerCamera;
    VECTOR PlayerPosition;

} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

#endif