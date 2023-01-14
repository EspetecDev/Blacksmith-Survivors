#include "engine.h"
#include <malloc.h>

Engine GEngineInstance;

/* Forward declarations. */

void UpdateGameState(Engine * EnginePtr);
void OnChangeGameState(Engine * EnginePtr);
// Debug
char* GetCurrentGSString(Engine * EnginePtr);

/* Engine Methods  */

void Init(Engine * EnginePtr)
{
    // Setup engine start vars.
    EnginePtr->CurrentGameState = GS_UNDEFINED;
    EnginePtr->DesiredGameState = GS_UNDEFINED;

    // Start PSX systems.
    dcMemory_Init();
    PadInit(0);
    InitGeom();
    
    EnginePtr->RenderPtr = (SDC_Render*)malloc3(sizeof(SDC_Render));
    CVECTOR BackgroundColor = {RENDER_BG_COLOR_R, RENDER_BG_COLOR_G, RENDER_BG_COLOR_B};
    dcRender_Init( EnginePtr->RenderPtr, RENDER_WIDTH, RENDER_HEIGHT, BackgroundColor, 4096, 8192, RENDER_MODE_PAL);
    
    //  Resources.
    Resources_LoadTextureResources();
    Resources_LoadSpriteResources();

    //  Init game state.
    EnginePtr->GameLoopGameState = (FGameLoopGameState*)malloc3(sizeof(FGameLoopGameState));
    EnginePtr->ContractGameState = (FContractGameState*)malloc3(sizeof(FContractGameState));
    EnginePtr->GameOverGameState = (FGameOverGameState*)malloc3(sizeof(FGameOverGameState));
    EnginePtr->MenuGameState = (MenuGameState*)malloc3(sizeof(MenuGameState));

    GLGS_Init(EnginePtr->GameLoopGameState);
    CGS_Init(EnginePtr->ContractGameState);
    GOGS_Init(EnginePtr->GameOverGameState);
    MGS_Init(EnginePtr->MenuGameState);
    
    //  Start game state.
    ChangeGameState(EnginePtr, GS_GAME_LOOP);
}

void Update(Engine * EnginePtr)
{
    if(EnginePtr->CurrentGameState != EnginePtr->DesiredGameState)
    {
        OnChangeGameState(EnginePtr);
    }

     // RENDER
    FntPrint("Demo1 - The Game\n");
    char debugGS[50] = "CurrentGS: ";
    char currentGS[15] = "";
    strcpy(currentGS, GetCurrentGSString(EnginePtr));
    strcat(debugGS, currentGS);
    FntPrint(debugGS);


    UpdateGameState(EnginePtr);

   
    
    dcRender_SwapBuffers(EnginePtr->RenderPtr);
}

void Close(Engine * EnginePtr)
{

}

/* Gamestate Change */

void UpdateGameState(Engine * EnginePtr)
{
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Update(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Update(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Update(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Update(EnginePtr->GameOverGameState);
        break;
        default:
        break;
    }
}

void ChangeGameState(Engine * EnginePtr, EGameState NewGameState)
{
    EnginePtr->DesiredGameState = NewGameState;
}

void OnChangeGameState(Engine * EnginePtr)
{
    // Exit game state
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Close(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Close(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Close(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Update(EnginePtr->GameOverGameState);
        break;
        default:
        break;
    }

    EnginePtr->CurrentGameState = EnginePtr->DesiredGameState;

    // Enter game state
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            MGS_Init(EnginePtr->MenuGameState);
        break;
        case GS_CONTRACT:
            CGS_Init(EnginePtr->ContractGameState);
        break;
        case GS_GAME_LOOP:
            GLGS_Init(EnginePtr->GameLoopGameState);
        break;
        case GS_GAME_OVER:
            GOGS_Init(EnginePtr->GameOverGameState);
        break;
        default:
        break;
    }
}

// DEBUG
char* GetCurrentGSString(Engine * EnginePtr)
{
    char* CurrentGSString;
    switch (EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
            CurrentGSString = "GS_MAIN_MENU";
        break;
        case GS_CONTRACT:
            CurrentGSString = "GS_CONTRACT";
        break;
        case GS_GAME_LOOP:
            CurrentGSString = "GS_GAME_LOOP";
        break;
        case GS_GAME_OVER:
            CurrentGSString = "GS_GAME_OVER";
        break;
        default:
            CurrentGSString = "";
        break;
    }
    return CurrentGSString;
}