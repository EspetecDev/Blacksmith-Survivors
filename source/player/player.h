#ifndef _DC_PLAYERINSTANCE_
#define _DC_PLAYERINSTANCE_

#include "dcMath.h"
#include "dcCamera.h"
#include "dcSprite.h"
#include "../scene/scene.h"

typedef enum
{
    PLAYER_UNKNOWN,
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

    SDC_Sprite CurrentSprite[PLAYER_NUM_ANIMATIONS];
    SDC_SpriteAnimation Animations[PLAYER_NUM_ANIMATIONS];
    PLAYER_ACTION CurrentPlayerAction;
} Player;

/* Player Methods  */

void PlayerInit(Player* Self, SDC_Camera * PlayerCamera, SceneMap* Map);
void PlayerInput(Player* Self, SDC_Camera * PlayerCamera, SceneMap* Map);
void PlayerUpdate(Player* Self);
void PlayerDraw(Player* Self);
void PlayerDie(Player* Self);

char CanMove(Player* Self, SceneMap* Map);
char LiesOnLeftHand(VECTOR EdgePosition1, VECTOR EdgePosition2, VECTOR PlayerPosition);
#endif