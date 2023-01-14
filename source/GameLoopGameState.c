#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"


#include "dcMisc.h"

#define CUBESIZE 100
#define QUADUVRES 32

static SDC_VertexTextured quad_vertices[] = {
    {{ -CUBESIZE / 2, -CUBESIZE / 2, 0, 0}, 0, QUADUVRES},
    {{ -CUBESIZE / 2, CUBESIZE / 2, 0, 0}, 0, 0},
    {{ CUBESIZE / 2, CUBESIZE / 2, 0, 0}, QUADUVRES, 0},
    {{ CUBESIZE / 2, -CUBESIZE / 2, 0, 0}, QUADUVRES, QUADUVRES}
};
static u_short quad_indices[] = { 0, 3, 1, 3, 2, 1 };
static SDC_Mesh3D quadMesh = { quad_vertices, quad_indices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED };

void GLGS_Init(FGameLoopGameState* GameState)
{
    VECTOR StartPos =  {0, 0, -300, 0};
    GameState->Player->PlayerPosition = StartPos;

    //  Prepare camera in 0.0.0
    VECTOR Position = {0,0,0,0};
    dcCamera_SetScreenResolution(&GameState->PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, 0, GameState->Player->PlayerPosition.vy, GameState->Player->PlayerPosition.vz);
    dcCamera_LookAt(&GameState->PlayerCamera, &Position);
    //InitPlayer(GameState);
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
    }

    if(padState & PADRdown) // X
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    
    GameState->Player->PlayerPosition.vy += MovementFront;
    GameState->Player->PlayerPosition.vx += MovemementSide;

    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, GameState->Player->PlayerPosition.vz );
    
    VECTOR Position = {GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, 0, 0};
    dcCamera_LookAt(&GameState->PlayerCamera, &Position);    
}

void GLGS_Update(FGameLoopGameState* GameState)
{
    HandlePlayerInput(GameState);

    SVECTOR rotation = {0};
    VECTOR translation = {0, 0, 0, 0};
    MATRIX transform;

    SDC_DrawParams draw_params;
    draw_params.tim = &tim_smile;

    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &transform, &transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &quadMesh, &transform, &draw_params);

    dcMisc_DrawAxis(GEngineInstance.RenderPtr, &GameState->PlayerCamera); 
    dcSprite_Update(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite);
    dcSprite_Render(GEngineInstance.RenderPtr, &GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, &Color);
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}

void InitPlayer(FGameLoopGameState* GameState)
{
    FAnimationTypes MovingAnimation;
    FAnimationTypes IdleAnimation;

    MovingAnimation.Animation = GetHeroRunAnimation();
    IdleAnimation.Animation = GetHeroIdleAnimation();

    GameState->Player->Animations[PLAYER_MOVING] = MovingAnimation;
    GameState->Player->Animations[PLAYER_IDLE] = IdleAnimation;

    GameState->Player->CurrentPlayerAction = PLAYER_IDLE;
    GameState->Player->CurrentPlayerAnimation = GameState->Player->Animations[GameState->Player->CurrentPlayerAction];

    //dcSprite_LoadAnimationTex(&GameState->Player->Animations[PLAYER_MOVING].Animation, _binary_sonic_tim_start);
    //dcSprite_LoadAnimationTex(&GameState->Player->Animations[PLAYER_IDLE].Animation, _binary_sonic_tim_start);
    dcSprite_SetAnimation(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, &GameState->Player->CurrentPlayerAnimation.Animation);
}