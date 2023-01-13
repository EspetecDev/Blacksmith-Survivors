#include <libetc.h>
#include "MenuGameState.h"
// #include "GEngine.h"
// tim files #include ""


struct MenuGameState
{
    char PressStartText[] = "PRESS START";
    char TeamName[] = "Demo1 - GameDevChallenge 2023";
    bool bChangeGameState = false;
};

void MenuGameState__OnEnter() {
   printf("MenuGameState::OnEnter");
}

void MenuGameState__Update() {
    printf("MenuGameState::Update");


    int pad = 0;
    while(GEngine->CurrentGameState != EGameStates::MenuGameState) //GEngine->
    {
        pad = PadRead(0);

        if(pad & PADstart)
        {
            //GEngine->CurrentGameState = GameGameState;
        }

        Render();
    }
}

void MenuGameState__OnExit() {
   printf("MenuGameState::OnExit");
}

void Render()
{
    FntPrint("GameDev Challenge Texture Demo\n");
}