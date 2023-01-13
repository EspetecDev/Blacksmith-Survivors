#include "engine.h"

/* Forward declarations. */

void UpdateGameState(Engine * EnginePtr);
void OnChangeGameState(Engine * EnginePtr);

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
    
    EnginePtr->RenderPtr = malloc3(sizeof(SDC_Render));
    CVECTOR BackgroundColor = {RENDER_BG_COLOR_R, RENDER_BG_COLOR_G, RENDER_BG_COLOR_B};
    dcRender_Init( EnginePtr->RenderPtr, RENDER_WIDTH, RENDER_HEIGHT, BackgroundColor, 4096, 8192, RENDER_MODE_PAL);




    //  Init game state.

    //  Start game state.
    ChangeGameState(EnginePtr, GS_MAIN_MENU);
}

void Update(Engine * EnginePtr)
{
    if(EnginePtr->CurrentGameState != EnginePtr->DesiredGameState)
    {
        OnChangeGameState(EnginePtr);
    }

    UpdateGameState(EnginePtr);

    // RENDER
    FntPrint("GameDev Challenge Sphere Demo\n");
    
    dcRender_SwapBuffers(&EnginePtr->RenderPtr);
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
        break;
        case GS_CONTRACT:
        break;
        case GS_GAME_LOOP:
        break;
        case GS_GAME_OVER:
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
        break;
        case GS_CONTRACT:
        break;
        case GS_GAME_LOOP:
        break;
        case GS_GAME_OVER:
        break;
        default:
        break;
    }

    EnginePtr->CurrentGameState = EnginePtr->DesiredGameState;

    // Enter game state
    switch(EnginePtr->CurrentGameState)
    {
        case GS_MAIN_MENU:
        break;
        case GS_CONTRACT:
        break;
        case GS_GAME_LOOP:
        break;
        case GS_GAME_OVER:
        break;
        default:
        break;
    }
}