#ifndef _DC_PLAYERINSTANCE_
#define _DC_PLAYERINSTANCE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "../scene/scene.h"

typedef struct 
{
    SDC_SpriteAnimation Animation;
    SDC_Sprite CurrentSprite;
} FAnimationTypes;

typedef enum
{
    PLAYER_IDLE,
    PLAYER_MOVING,
    PLAYER_ATTACKING,

    PLAYER_NUM_ANIMATIONS
} PLAYER_ACTION;

typedef struct 
{
    VECTOR PlayerPosition;
    int Speed;
    int RadiusColision;

    FAnimationTypes Animations[PLAYER_NUM_ANIMATIONS];
    PLAYER_ACTION CurrentPlayerAction;
    FAnimationTypes CurrentPlayerAnimation;
} Player;

/* Player Methods  */

void PlayerInit(Player* Self, SDC_Camera * PlayerCamera, SceneMap* Map);
void PlayerInput(Player* Self, SDC_Camera * PlayerCamera);
void PlayerUpdate(Player* Self);
void PlayerDraw(Player* Self);
void PlayerDie(Player* Self);

#endif