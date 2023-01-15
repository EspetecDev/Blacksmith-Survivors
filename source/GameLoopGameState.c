#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "characters/EnemyManager.h"
#include "dcMisc.h"
#include "Contract.h"
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
    
    
    EM_SpawnEnemy(&GameState->MyEnemyManager, ENEMY_BLUE, &GameState->PlayerInstance);
}

void GLGS_Update(FGameLoopGameState *GameState)
{
    //  Player input.
    PlayerInput(&GameState->PlayerInstance, &GameState->SceneData);

    //  Update player logic.
    PlayerUpdate(&GameState->PlayerInstance);

    //  Update enemy manager.
    //EM_Update(&GameState->MyEnemyManager, &GameState->PlayerInstance);

    //  Draw hero.
    PlayerDraw(&GameState->PlayerInstance);
    

    //  Draw enemy.
    for(int i=0;i<GameState->MyEnemyManager.NumberBlueEnemy;i++)
    {
        EnemyDraw(&GameState->MyEnemyManager.BlueEnemies[i], &GameState->PlayerInstance);
    }

    //EM_Draw(&GameState->MyEnemyManager, &GameState->PlayerInstance);

    //  Draw scene.
    SceneMap_Draw(&GameState->SceneData, &GameState->PlayerInstance.CameraPosition);
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