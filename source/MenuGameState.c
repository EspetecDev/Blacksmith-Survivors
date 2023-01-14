#include "MenuGameState.h"
#include "engine.h"
// tim files #include ""

void MGS_Init(MenuGameState* MGSPtr)
{
    strcpy(MGSPtr->PressStartText, "PRESS START");
    strcpy(MGSPtr->TeamName, "Demo1 - GameDevChallenge 2023");
}

void MGS_Update(MenuGameState* MGSPtr)
{
    if(GEngineInstance.CurrentGameState == GS_MAIN_MENU) 
    {
        // Input
        int pad = 0;
        pad = PadRead(0);
        // if(pad & PADstart)
        if(pad & PADRup)  //△
        {
            GEngineInstance.DesiredGameState = GS_CONTRACT;
        }

        // Draw texts
        // FntPrint(MGSPtr->PressStartText);
    }
}

void MGS_Close(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit\n");
}