#include "MenuGameState.h"
#include "engine.h"
// tim files #include ""

void MGS_Init(MenuGameState* MGSPtr)
{
    strcpy(MGSPtr->PressStartText, "PRESS START");
    strcpy(MGSPtr->TeamName, "Demo1 - GameDevChallenge 2023");
}

void MGS_OnEnter(MenuGameState* MGSPtr)
{

}

void MGS_Update(MenuGameState* MGSPtr)
{
    printf("MenuGameState::Update");
    
    int pad = 0;
    while(GEngineInstance.CurrentGameState == GS_MAIN_MENU) //GEngine->
    {
        // Input
        pad = PadRead(0);
        // if(pad & PADstart)
        if(pad & PADRup)  //△
        {
            printf("[MGS_Update::Update] Enter game loop");
            GEngineInstance.DesiredGameState = GS_CONTRACT;
        }

        // Draw texts
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
        FntPrint(MGSPtr->PressStartText);
        FntPrint("\n");
    }
}

void MGS_OnExit(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit");
}