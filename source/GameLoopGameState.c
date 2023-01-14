#include "GameLoopGameState.h"
#include "engine.h"

#include "engine.h"
#include "render.h"


#include "dcMisc.h"

#define CUBESIZE 196

static SDC_Vertex quad_vertices[] = {
    { -CUBESIZE / 2, 0,  -CUBESIZE / 2, 0 },
    { -CUBESIZE / 2, 0, CUBESIZE / 2, 0  },
    { CUBESIZE / 2, 0, CUBESIZE / 2, 0  },
    { CUBESIZE / 2, 0, -CUBESIZE / 2, 0 }
};
static u_short quad_indices[] = { 0, 1, 3, 3, 1, 2 };
static SDC_Mesh3D cubeMesh = { quad_vertices, quad_indices, NULL, 6, 4, POLIGON_VERTEX };

void GLGS_Init(FGameLoopGameState* GameState)
{
    VECTOR StartPos =  {0, 0, 300, 0};
    GameState->PlayerPosition = StartPos;

    //  Prepare camera in 0.0.0
    VECTOR Position = {0,0,0,0};
    dcCamera_SetScreenResolution(&GameState->PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, 0, GameState->PlayerPosition.vy, GameState->PlayerPosition.vz);
    dcCamera_LookAt(&GameState->PlayerCamera, &Position);
}

void HandlePlayerInput(FGameLoopGameState* GameState)
{
    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;


    // Y AXIS
    if( _PAD(0,PADLup ) & padState )
    {
        MovementFront = 32;
    }
    if( _PAD(0,PADLdown ) & padState )
    {
        MovementFront = -32;
    }

    // X AXIS
    if( _PAD(0,PADLright ) & padState )
    {
        MovemementSide = -32;
    }
    if( _PAD(0,PADLleft ) & padState )
    {
        MovemementSide = 32;
    }

    if(padState & PADRdown) // X
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    
    GameState->PlayerPosition.vy += MovementFront;
    GameState->PlayerPosition.vx += MovemementSide;

    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->PlayerPosition.vx, GameState->PlayerPosition.vy, GameState->PlayerPosition.vz );
    
    VECTOR Position = {GameState->PlayerPosition.vx, GameState->PlayerPosition.vy, GameState->PlayerPosition.vz - 300,0};
    dcCamera_LookAt(&GameState->PlayerCamera, &Position);    
}

void GLGS_Update(FGameLoopGameState* GameState)
{
    HandlePlayerInput(GameState);

    SVECTOR rotation = {0};
    VECTOR translation = {0, 0, 0, 0};
    MATRIX transform;

    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &transform, &transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &cubeMesh, &transform, NULL);

    dcMisc_DrawAxis(GEngineInstance.RenderPtr, &GameState->PlayerCamera); 
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}