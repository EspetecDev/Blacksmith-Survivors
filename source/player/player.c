#include "Player.h"
#include "../Resources.h"
#include "../engine.h"

#define CameraHeightPosition 300

void PlayerChangeAnim(Player* Self, PLAYER_ACTION NewAction);

void PlayerInit(Player* Self, SDC_Camera * PlayerCamera)
{
    VECTOR StartPos = {0, 0, 0, 0};
    Self->PlayerPosition = StartPos;
    Self->RadiusColision = 32;

    Self->Animations[PLAYER_IDLE] = HeroIdleAnimations;
    Self->Animations[PLAYER_MOVING] = HeroWalkAnimations;
    //Self->Animations[PLAYER_ATTACKING] = HeroAttackAnimations;
    Self->CurrentPlayerAction = PLAYER_IDLE;

    dcSprite_SetAnimation(&Self->CurrentSprite[PLAYER_IDLE], &Self->Animations[PLAYER_IDLE]);
    dcSprite_SetAnimation(&Self->CurrentSprite[PLAYER_MOVING], &Self->Animations[PLAYER_MOVING]);
    //dcSprite_SetAnimation(&Self->CurrentSprite[PLAYER_ATTACKING], &Self->Animations[PLAYER_ATTACKING]);

    //  Setup camera start.
    dcCamera_SetScreenResolution(PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(PlayerCamera, Self->PlayerPosition.vx, Self->PlayerPosition.vy, CameraHeightPosition);
    dcCamera_LookAt(PlayerCamera, &Self->PlayerPosition);
}

void PlayerChangeAnim(Player* Self, PLAYER_ACTION NewAction)
{
    if(Self->CurrentPlayerAction != NewAction)
    {
        Self->CurrentPlayerAction = NewAction;
    }
}

void PlayerInput(Player* Self, SDC_Camera * PlayerCamera)
{
    // Constants player speed.
    const int PlayerMovementForward = 100;
    const int PlayerMovementSide = 100;

    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;
    
    PlayerChangeAnim(Self, PLAYER_IDLE);
    
    // Y AXIS
    if (_PAD(0, PADLup) & padState)
    {
        MovementFront = PlayerMovementForward;
        PlayerChangeAnim(Self, PLAYER_MOVING);
    }
    if (_PAD(0, PADLdown) & padState)
    {
        MovementFront = -PlayerMovementForward;
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

    Self->PlayerPosition.vy += MovementFront;
    Self->PlayerPosition.vx += MovemementSide;

    //  Move camera to follow player.
    dcCamera_SetCameraPosition(PlayerCamera, Self->PlayerPosition.vx, Self->PlayerPosition.vy, CameraHeightPosition);
    dcCamera_LookAt(PlayerCamera, &Self->PlayerPosition);
}

void PlayerUpdate(Player* Self)
{
    //  Check which animation to play.

    // Update animation.
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