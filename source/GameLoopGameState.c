#include "GameLoopGameState.h"
#include "engine.h"

void GLGS_Init(FGameLoopGameState* GameState)
{

}

void GLGS_Update(FGameLoopGameState* GameState)
{
    printf("[GLGS_Update::Update] Enter game loop");
    int pad = 0;
    while (GEngineInstance.CurrentGameState == GS_GAME_LOOP)
    {
        // Input
        pad = PadRead(0);
        if(pad & PADRdown) // X
        {
            GEngineInstance.DesiredGameState = GS_GAME_OVER;
        }
    }
    
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}