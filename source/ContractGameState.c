#include "ContractGameState.h"
#include "engine.h"

void CGS_Init(FContractGameState* GameState)
{

}

void CGS_Update(FContractGameState* GameState)
{
    printf("[CGS_Update::Update] Enter contract\n");
    int pad = 0;
    if (GEngineInstance.CurrentGameState == GS_CONTRACT)
    {
        // Input
        pad = PadRead(0);
        if(pad & PADRright) // ⭘
        {
            GEngineInstance.DesiredGameState = GS_GAME_LOOP;
        }
    }
}

void CGS_Close(FContractGameState* GameState)
{

}