#include "Player.h"
#include "../Resources.h"
#include "../engine.h"

#define CameraHeightPosition 300

void PlayerInit(Player* Self, SDC_Camera * PlayerCamera, SceneMap* Map)
{
    // We want the player to start at the center of the grid.
    VECTOR GridC = GetGridCenter(Map, DEBUG_QUAD_SIZE * 2);
    VECTOR StartPos = {GridC.vx, GridC.vy, 0};
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

void PlayerInput(Player* Self, SDC_Camera* PlayerCamera, SceneMap* Map)
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

    // Check if next position is in the grid. If not, we don't want to move.
    if (CanMove(Self, Map))
    {
        // Move camera to follow player.
        dcCamera_SetCameraPosition(PlayerCamera, Self->PlayerPosition.vx, Self->PlayerPosition.vy, CameraHeightPosition);
        dcCamera_LookAt(PlayerCamera, &Self->PlayerPosition);
    }
    else
    {
        Self->PlayerPosition.vy -= MovementFront;
        Self->PlayerPosition.vx -= MovemementSide;
    }
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

char CanMove(Player* Self, SceneMap* Map)
{
    VECTOR StartPos = GetGridCenter(Map, DEBUG_QUAD_SIZE * 2);
    VECTOR FirstEdge = {0, 0, 0};
    VECTOR SecondEdge = {0, StartPos.vy * 2, 0};
    VECTOR ThirdEdge = {StartPos.vx * 2, StartPos.vy * 2, 0};
    VECTOR FourthEdge = {StartPos.vx * 2, 0, 0};

    return !LiesOnLeftHand(FirstEdge, SecondEdge, Self->PlayerPosition) && !LiesOnLeftHand(ThirdEdge, FourthEdge, Self->PlayerPosition) && !LiesOnLeftHand(SecondEdge, ThirdEdge, Self->PlayerPosition) && !LiesOnLeftHand(FourthEdge, FirstEdge, Self->PlayerPosition);
}

char LiesOnLeftHand(VECTOR EdgePosition1, VECTOR EdgePosition2, VECTOR PlayerPosition)
{
    long D = (EdgePosition2.vx - EdgePosition1.vx) * (PlayerPosition.vy - EdgePosition1.vy) - (PlayerPosition.vx - EdgePosition1.vx) * (EdgePosition2.vy - EdgePosition1.vy);
    return D > 0;
}