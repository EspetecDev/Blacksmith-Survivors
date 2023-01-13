#ifndef _DC_GAMEOVER_GAMESTATE
#define _DC_GAMEOVER_GAMESTATE

typedef struct
{
    int Manel;
} FGameOverGameState;

void GOGS_Init(FGameOverGameState* GameState);
void GOGS_Update(FGameOverGameState* GameState);
void GOGS_Close(FGameOverGameState* GameState);

#endif