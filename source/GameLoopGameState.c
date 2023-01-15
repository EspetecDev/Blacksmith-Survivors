#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "characters/EnemyManager.h"
#include "Contract.h"
#include "dcMisc.h"
#include <assert.h>

void InitScene(FGameLoopGameState *GameState);

void GLGS_Init(FGameLoopGameState *GameState)
{
    // Contract setup.
    ContractInit(&GameState->Contract);

    //  Setup player data.
    InitPlayer(GameState);

    //  Setup scene data.
    InitScene(GameState);

    // Init enemy manager
    EM_Init(&GameState->MyEnemyManager, &GameState->SceneData, &GameState->PlayerInstance);

    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_BLUE, &GameState->PlayerInstance);
    }

    GameState->CurrentTicks = 0;
    GameState->CurrentSeconds = 0;
}

void HandlePlayerInput(FGameLoopGameState *GameState)
{
}

void GLGS_Update(FGameLoopGameState *GameState)
{
    int currentTicksDebug = ++GameState->CurrentTicks;
    if(currentTicksDebug == 50)
    {
        ++GameState->CurrentSeconds;
        GameState->CurrentTicks = 0;
    }
    
    char TimeStr[4];
    sprintf( TimeStr, "%d", GOAL_TIME - GameState->CurrentSeconds );
    CVECTOR Color = {128, 128, 128};
    dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH - 4 * RENDER_FONT_CHAR_SIZE, 20, &Color, TimeStr);
    if(GameState->CurrentSeconds >= GOAL_TIME)
    {
        if (ContractCheckWon(&GameState->Contract) || ContractCheckDefeat(&GameState->Contract))
        {
            ChangeGameState(&GEngineInstance, GS_MAIN_MENU);
        }
    }
    else
    {

        //  Player input.
        PlayerInput(&GameState->PlayerInstance, &GameState->SceneData);

        //  Update player logic.
        PlayerUpdate(&GameState->PlayerInstance);

        //  Update enemy manager.
        EM_Update(&GameState->MyEnemyManager, &GameState->PlayerInstance, &GameState->Contract);

        //  Draw hero.
        PlayerDraw(&GameState->PlayerInstance);
        
        //  Draw enemy.
        EM_Draw(&GameState->MyEnemyManager, &GameState->PlayerInstance);

        //  Draw scene.
        SceneMap_Draw(&GameState->SceneData, &GameState->PlayerInstance.CameraPosition);
    }
}

void GLGS_Close(FGameLoopGameState *GameState)
{
    GameState->CurrentTicks = 0;
    GameState->CurrentSeconds = 0;
}

void InitPlayer(FGameLoopGameState *GameState)
{
    PlayerInit(&GameState->PlayerInstance, &GameState->SceneData);
}

void InitScene(FGameLoopGameState *GameState)
{
    SceneMap_Init(&GameState->SceneData);
}