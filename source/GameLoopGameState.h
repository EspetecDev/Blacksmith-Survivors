#ifndef _DC_GAME_LOOP_GAMESTATE_
#define _DC_GAME_LOOP_GAMESTATE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"

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
} FPlayer;

typedef struct
{
    SDC_Camera PlayerCamera;
    FPlayer* Player;
} FGameLoopGameState;

void GLGS_Init(FGameLoopGameState* GameState);
void GLGS_Update(FGameLoopGameState* GameState);
void GLGS_Close(FGameLoopGameState* GameState);

void InitPlayer(FGameLoopGameState* GameState);
void ManageInput(FGameLoopGameState* GameState);

#endif