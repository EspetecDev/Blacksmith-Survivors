#include "Player.h"
#include "../Resources.h"
#include "../engine.h"

#define CameraHeightPosition 300

void PlayerChangeAnim(Player* Self, PLAYER_ACTION NewAction);

void PlayerInit(Player* Self, SceneMap* Map)
{
    VECTOR StartPos = Scene_GetMapCenter();
    Self->PlayerPosition = StartPos;
    Self->CameraPosition.vx = Self->PlayerPosition.vx - RENDER_WIDTH/2;
    Self->CameraPosition.vy = Self->PlayerPosition.vy - RENDER_HEIGHT/2; 
    Self->RadiusColision = 16;

    Self->Animations[PLAYER_MOVING] = HeroWalkAnimations;
    Self->Animations[PLAYER_ATTACKING] = HeroAttackAnimations;
    Self->CurrentPlayerAction = PLAYER_MOVING;

    dcSprite_SetAnimation(&Self->CurrentSprite[PLAYER_MOVING], &Self->Animations[PLAYER_MOVING]);
    dcSprite_SetAnimation(&Self->CurrentSprite[PLAYER_ATTACKING], &Self->Animations[PLAYER_ATTACKING]);
}

void PlayerChangeAnim(Player* Self, PLAYER_ACTION NewAction)
{
    if(Self->CurrentPlayerAction != NewAction)
    {
        Self->CurrentPlayerAction = NewAction;
    }
}

void PlayerInput(Player* Self, SceneMap* Map)
{
    // Constants player speed.
    const int PlayerMovementForward = 8;
    const int PlayerMovementSide = 8;

    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;
    
    PlayerChangeAnim(Self, PLAYER_MOVING);
    
    // Y AXIS
    if (_PAD(0, PADLup) & padState)
    {
        MovementFront = -PlayerMovementForward;
        PlayerChangeAnim(Self, PLAYER_MOVING);
    }
    if (_PAD(0, PADLdown) & padState)
    {
        MovementFront = PlayerMovementForward;
        PlayerChangeAnim(Self, PLAYER_MOVING);
    }

    // X AXIS
    if (_PAD(0, PADLright) & padState)
    {
        MovemementSide = PlayerMovementSide;
        PlayerChangeAnim(Self, PLAYER_MOVING);
    }
    if (_PAD(0, PADLleft) & padState)
    {
        MovemementSide = -PlayerMovementSide;
        PlayerChangeAnim(Self, PLAYER_MOVING);
    }

    VECTOR ExpectedPos = {Self->PlayerPosition.vx + MovemementSide, Self->PlayerPosition.vy + MovementFront, 0, 0};
    if (Scene_IsInsidedBounds(&ExpectedPos))
    {
        Self->PlayerPosition.vy += MovementFront;
        Self->PlayerPosition.vx += MovemementSide;
        Self->CameraPosition.vx = Self->PlayerPosition.vx - RENDER_WIDTH/2;
        Self->CameraPosition.vy = Self->PlayerPosition.vy - RENDER_HEIGHT/2; 
    }
}

void PlayerUpdate(Player* Self)
{
    //  Check which animation to play.
    dcSprite_Update(&Self->CurrentSprite[Self->CurrentPlayerAction]);
}

void PlayerDraw(Player* Self)
{
    // Update player sprite animation.
    const int SpriteXPos = RENDER_WIDTH / 2;
    const int SpriteYPos = RENDER_HEIGHT / 2;

    // Translate Hero position into screen space.
    CVECTOR ColorSprit = {128, 128, 128, 128};
    dcSprite_Render(GEngineInstance.RenderPtr, &Self->CurrentSprite[Self->CurrentPlayerAction], SpriteXPos, SpriteYPos, &ColorSprit);
}

void PlayerDie(Player* Self)
{

}

char CanMove(Player* Self, SceneMap* Map)
{
    return 1;
}

char LiesOnLeftHand(VECTOR EdgePosition1, VECTOR EdgePosition2, VECTOR PlayerPosition)
{
    long D = (EdgePosition2.vx - EdgePosition1.vx) * (PlayerPosition.vy - EdgePosition1.vy) - (PlayerPosition.vx - EdgePosition1.vx) * (EdgePosition2.vy - EdgePosition1.vy);
    return D > 0;
}