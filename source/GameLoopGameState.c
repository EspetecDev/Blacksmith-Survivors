#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "characters/EnemyManager.h"
#include "dcMisc.h"

void InitScene(FGameLoopGameState *GameState);
void DrawSceneAssets(FGameLoopGameState *GameState);
void DrawAsset(FGameLoopGameState *GameState, VECTOR *Translation, TIM_IMAGE *AssetTexture);
void DrawUI(FGameLoopGameState *GameState);

void GLGS_Init(FGameLoopGameState *GameState)
{
    //  Setup player data.
    InitPlayer(GameState);

    //  Setup scene data.
    InitScene(GameState);

    // Init enemy manager
    EM_Init(&GEnemyManager);
}

void HandlePlayerInput(FGameLoopGameState *GameState)
{
    u_long padState = PadRead(0);

    if (padState & PADselect) // X
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    if (padState & PADRdown) // X
    {
        EM_SpawnEnemy(&GEnemyManager, ENEMY_BLUE);
    }
    if (padState & PADRright) // O
    {
        EM_SpawnEnemy(&GEnemyManager, ENEMY_RED);
    }
    if (padState & PADRup) // triangle
    {
        EM_SpawnEnemy(&GEnemyManager, ENEMY_GREEN);
    }
    if (padState & PADRleft) // |_|
    {
        EM_SpawnEnemy(&GEnemyManager, ENEMY_YELLOW);
    }
}

void GLGS_Update(FGameLoopGameState *GameState)
{
    //  Move and update player.
    HandlePlayerInput(GameState);

    //  Player input.
    PlayerInput(&GameState->PlayerInstance, &GameState->SceneData);

    //  Update player logic.
    PlayerUpdate(&GameState->PlayerInstance);

    //  Update enemy manager.
    EM_Update(&GEnemyManager);

    //  Draw hero.
    PlayerDraw(&GameState->PlayerInstance);

    //  Draw enemy.
    EM_Draw(&GEnemyManager);

    //  Draw scene assets.
    DrawSceneAssets(GameState);

    // Draw UI.
    //DrawUI(GameState);
}

void GLGS_Close(FGameLoopGameState *GameState)
{
}

void InitPlayer(FGameLoopGameState *GameState)
{
    PlayerInit(&GameState->PlayerInstance, &GameState->SceneData);
}

void InitScene(FGameLoopGameState *GameState)
{
    SceneMap_Init(&GameState->SceneData);
}

void DrawSceneAssets(FGameLoopGameState *GameState)
{
    //Scene
    SceneMap* MyScene = &GameState->SceneData;
    //long CellSize = DEBUG_QUAD_SIZE * 2;
    
    if (MyScene)
    {
        SceneMap_Draw(MyScene);
        for(int Index = 0; Index < GetGridSize(MyScene); Index++)
        {
            //CVECTOR ColorQuad = {RENDER_BG_COLOR_R, RENDER_BG_COLOR_G,RENDER_BG_COLOR_B,255};
            //VECTOR Translation = {(MyScene->MapCellSizes[Index].vx * CellSize + CellSize / 2), (MyScene->MapCellSizes[Index].vy * CellSize + CellSize / 2), 0, 0};
            //VECTOR Scale = {ONE * 2, ONE * 2, 0, 0};
        }
    }
}

char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius)
{
    // Calculate the distance^2 between FirstPosition and SecondPosition
    long Distance = GetDistanceBetweenTwoPoints(FirstPosition, SecondPosition);
    long FinalRadius = DC_MUL(Radius, Radius);
    // Position is in radius if Distance^2 < Radius^2
    return (Distance < FinalRadius);
}

char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long PlayerRadius, long OtherRadius)
{
    // Two "entities" will collide if their colliders intersect or are inside each other.
    // The two "colliders" will intersect when ((r1 - r2)^2 < d^2) || ((r1 + r2)^2) > d^2.
    // The two "colliders" will be conentric if d = 0.

    long SumRadi = DC_MUL((PlayerRadius + OtherRadius), (PlayerRadius + OtherRadius));
    long DiffRadi = DC_MUL((PlayerRadius - OtherRadius), (PlayerRadius - OtherRadius));
    long Distance = GetDistanceBetweenTwoPoints(PlayerPosition, OtherPosition);

    return (Distance > DiffRadi) || (Distance < SumRadi) || Distance == 0 || Distance == PlayerRadius || Distance == OtherRadius;
}

long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition)
{
    long XDistance = (FirstPosition.vx - SecondPosition.vx);
    long YDistance = (FirstPosition.vy - SecondPosition.vy);

    long Distance = DC_MUL(XDistance, XDistance) + DC_MUL(YDistance, YDistance);
    return Distance;
}