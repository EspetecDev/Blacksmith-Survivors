#ifndef _DC_GAME_LOOP_GAMESTATE_
#define _DC_GAME_LOOP_GAMESTATE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "scene/scene.h"

typedef enum
{
    PLAYER_IDLE,
    PLAYER_MOVING,
    PLAYER_ATTACKING,

    PLAYER_NUM_ANIMATIONS
} PLAYER_ACTION;

typedef struct 
{
    SDC_SpriteAnimation Animation;
    SDC_Sprite CurrentSprite;
} FAnimationTypes;

typedef struct 
{
    FAnimationTypes Animations[PLAYER_NUM_ANIMATIONS];
    PLAYER_ACTION CurrentPlayerAction;
    FAnimationTypes CurrentPlayerAnimation;
    VECTOR PlayerPosition;
    int Speed;
    int RadiusColision;
} FPlayer;

typedef struct
{
    SDC_Camera PlayerCamera;
    SceneMap SceneData;

    FPlayer* Player;
} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

void InitPlayer(FGameLoopGameState* GameState);
char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius);
char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long PlayerRadius, long OtherRadius);
long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition);

#endif