#ifndef _DC_GAME_LOOP_GAMESTATE
#define _DC_GAME_LOOP_GAMESTATE

typedef struct
{
    int Manel;
} FGameLoopGameState;

void Init(FGameLoopGameState* GameState);
void Update(FGameLoopGameState* GameState);
void Close(FGameLoopGameState* GameState);

#endif