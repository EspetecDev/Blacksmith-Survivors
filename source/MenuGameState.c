#include "engine.h"
#include "MenuGameState.h"
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
    while(GEngineInstance.CurrentGameState != GS_MAIN_MENU) //GEngine->
    {
        pad = PadRead(0);

        if(pad & PADstart)
        {
            printf("[MenuGameState::Update] Enter game loop");
            GEngineInstance.CurrentGameState = GS_GAME_LOOP;
        }
    }
}

void MGS_OnExit(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit");
}