#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "renderMeshes.h"
#include "dcMisc.h"

#define CameraHeightPosition -300

void GLGS_Init(FGameLoopGameState* GameState)
{
    //  Setup player data.
    InitPlayer(GameState);

    //  Setup camera start.
    dcCamera_SetScreenResolution(&GameState->PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, CameraHeightPosition);
    dcCamera_LookAt(&GameState->PlayerCamera, &GameState->Player->PlayerPosition);
}

void HandlePlayerInput(FGameLoopGameState* GameState)
{
    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;

    // Y AXIS
    if( _PAD(0,PADLup ) & padState )
    {
        MovementFront = 1;
    }
    if( _PAD(0,PADLdown ) & padState )
    {
        MovementFront = -1;
    }

    // X AXIS
    if( _PAD(0,PADLright ) & padState )
    {
        MovemementSide = -1;
    }
    if( _PAD(0,PADLleft ) & padState )
    {
        MovemementSide = 1;
    }

    /*
    if (MovementFront != 0 || MovemementSide != 0)
    {
        if (GameState->Player->CurrentPlayerAction != PLAYER_MOVING)
        {
            GameState->Player->CurrentPlayerAction = PLAYER_MOVING;
            //dcSprite_SetAnimation(&GameState->Player->Animations[PLAYER_MOVING].CurrentSprite, &GameState->Player->Animations[PLAYER_MOVING].Animation);
        }
    }
    else
    {
        if (GameState->Player->CurrentPlayerAction != PLAYER_IDLE)
        {
            GameState->Player->CurrentPlayerAction = PLAYER_IDLE;
        }
    }*/

    if(padState & PADRdown) // X
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    
    //  Move player position.
    GameState->Player->PlayerPosition.vy += MovementFront;
    GameState->Player->PlayerPosition.vx += MovemementSide;

    //  Move camera to follow player.
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, CameraHeightPosition );
    dcCamera_LookAt(&GameState->PlayerCamera, &GameState->Player->PlayerPosition);    
}

void GLGS_Update(FGameLoopGameState* GameState)
{
    //  Move player.
    HandlePlayerInput(GameState);

    //SVECTOR rotation = {0};
    //VECTOR translation = {0, 0, 0, 0};
    //MATRIX transform;
    CVECTOR ColorSprit = {128, 128, 128, 128};

    //SDC_DrawParams draw_params;
    //draw_params.tim = &tim_smile;
    
    /*
    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &transform, &transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &QuadAssetMesh, &transform, &draw_params);
    */

    dcMisc_DrawAxis(GEngineInstance.RenderPtr, &GameState->PlayerCamera); 
    dcSprite_Update(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite);
    dcSprite_Render(GEngineInstance.RenderPtr, &GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, RENDER_WIDTH/2, RENDER_HEIGHT/2, &ColorSprit);
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}

void InitPlayer(FGameLoopGameState* GameState)
{
    VECTOR StartPos =  {0, 0, 0, 0};
    GameState->Player->PlayerPosition = StartPos;

    FAnimationTypes MovingAnimation;
    //FAnimationTypes IdleAnimation;

    MovingAnimation.Animation = HeroRunAnimation;

    GameState->Player->Animations[PLAYER_MOVING] = MovingAnimation;
    //GameState->Player->Animations[PLAYER_IDLE] = IdleAnimation;

    GameState->Player->CurrentPlayerAction = PLAYER_MOVING;
    GameState->Player->CurrentPlayerAnimation = GameState->Player->Animations[GameState->Player->CurrentPlayerAction];
    dcSprite_SetAnimation(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, &GameState->Player->CurrentPlayerAnimation.Animation);
}