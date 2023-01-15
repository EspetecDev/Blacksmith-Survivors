#ifndef _DC_GAMEOVER_GAMESTATE
#define _DC_GAMEOVER_GAMESTATE

#include "dcSprite.h"

typedef struct
{
    char GameOverText[10];
    char PressStartText[35];
    char bActivatePressStartEffet;

    SDC_Sprite EnemyRedSprite;


} FGameOverGameState;

void GOGS_Init(FGameOverGameState* GameState);
void GOGS_Update(FGameOverGameState* GameState);
void GOGS_Close(FGameOverGameState* GameState);

#endif