#ifndef _DC_GAME_LOOP_GAMESTATE_
#define _DC_GAME_LOOP_GAMESTATE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "scene/scene.h"
#include "player/player.h"
#include "Contract.h"
#include "characters/EnemyManager.h"

typedef struct
{
    Player PlayerInstance;
    SceneMap SceneData;
    ContractData Contract;
    EnemyManager* MyEnemyManager;
} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

void InitPlayer(FGameLoopGameState* GameState);
char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius);
char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long PlayerRadius, long OtherRadius);
long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition);

#endif