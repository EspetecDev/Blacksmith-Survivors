#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "characters/EnemyManager.h"


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

    // Init enemy manager
    EM_Init(&GEenemyManager);
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

    if(padState & PADselect)
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    if(padState & PADRdown) // X
    {
        EM_SpawnEnemy(&GEenemyManager, ENEMY_BLUE);
    }
    if(padState & PADRright) // O
    {
        EM_SpawnEnemy(&GEenemyManager, ENEMY_RED);
    }
    if(padState & PADRup) // triangle
    {
        EM_SpawnEnemy(&GEenemyManager, ENEMY_GREEN);
    }
    if(padState & PADRleft) // |_|
    {
        EM_SpawnEnemy(&GEenemyManager, ENEMY_YELLOW);
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
    EM_Update(&GEenemyManager);

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