#ifndef _DC_GAME_LOOP_GAMESTATE
#define _DC_GAME_LOOP_GAMESTATE

typedef struct
{
    int Manel;
} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

#endif