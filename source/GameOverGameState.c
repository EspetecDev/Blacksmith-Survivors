#include "GameOverGameState.h"
#include "engine.h"

void GOGS_Init(FGameOverGameState* GameState)
{

}

void GOGS_Update(FGameOverGameState* GameState)
{
    printf("[GOGS_Update::Update] Enter game over");
    int pad = 0;
    while (GEngineInstance.CurrentGameState == GS_GAME_OVER)
    {
        // Input
        pad = PadRead(0);
        if(pad & PADRleft) // ⬜
        {
            GEngineInstance.DesiredGameState = GS_MAIN_MENU;
        }
    }
}

void GOGS_Close(FGameOverGameState* GameState)
{

}