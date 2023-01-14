#include "Player.h"
#include "../Resources.h"
#include "../engine.h"

#define CameraHeightPosition 300

void PlayerInit(Player* Self, SDC_Camera * PlayerCamera, SceneMap* Map)
{
    // We want the player to start at the center of the grid.
    VECTOR StartPos = GetGridCenter(Map, DEBUG_QUAD_SIZE * 2);
    Self->PlayerPosition = StartPos;
    Self->RadiusColision = 32;

    FAnimationTypes MovingAnimation;
    // FAnimationTypes IdleAnimation;

    MovingAnimation.Animation = HeroRunAnimation;

    Self->Animations[PLAYER_MOVING] = MovingAnimation;
    // GameState->Player->Animations[PLAYER_IDLE] = IdleAnimation;

    Self->CurrentPlayerAction = PLAYER_MOVING;
    Self->CurrentPlayerAnimation =Self->Animations[Self->CurrentPlayerAction];
    dcSprite_SetAnimation(&Self->Animations[Self->CurrentPlayerAction].CurrentSprite, &Self->CurrentPlayerAnimation.Animation);
    
    //  Setup camera start.
    dcCamera_SetScreenResolution(PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(PlayerCamera, Self->PlayerPosition.vx, Self->PlayerPosition.vy, CameraHeightPosition);
    dcCamera_LookAt(PlayerCamera, &Self->PlayerPosition);
}

void PlayerInput(Player* Self, SDC_Camera * PlayerCamera)
{
    // Constants player speed.
    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;
    
    // Y AXIS
    if (_PAD(0, PADLup) & padState)
    {
        MovementFront = PlayerSpeed;
    }
    if (_PAD(0, PADLdown) & padState)
    {
        MovementFront = -PlayerSpeed;
    }

    // X AXIS
    if (_PAD(0, PADLright) & padState)
    {
        MovemementSide = PlayerSpeed;
    }
    if (_PAD(0, PADLleft) & padState)
    {
        MovemementSide = -PlayerSpeed;
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
    dcSprite_Update(&Self->Animations[Self->CurrentPlayerAction].CurrentSprite);
}

void PlayerDraw(Player* Self)
{
    // Update player sprite animation.
    const int SpriteXPos = RENDER_WIDTH / 2;
    const int SpriteYPos = RENDER_HEIGHT / 2;

    // Translate Hero position into screen space.
    CVECTOR ColorSprit = {128, 128, 128, 128};
    dcSprite_Render(GEngineInstance.RenderPtr, &Self->Animations[Self->CurrentPlayerAction].CurrentSprite, SpriteXPos, SpriteYPos, &ColorSprit);
}

void PlayerDie(Player* Self)
{

}