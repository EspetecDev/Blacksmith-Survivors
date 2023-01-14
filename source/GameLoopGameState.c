#include "GameLoopGameState.h"

#include "engine.h"
#include "render.h"

#define CUBESIZE 196

static SDC_Vertex quad_vertices[] = {
    { -CUBESIZE / 2, -CUBESIZE / 2, -CUBESIZE / 2, 0 },
    { CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0  },
    {-CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0  },
    {-CUBESIZE / 2, -CUBESIZE / 2, CUBESIZE / 2, 0 }
};

static SDC_Vertex cube_vertices[] = {
    { {-CUBESIZE / 2, -CUBESIZE / 2, -CUBESIZE / 2, 0} }, { {CUBESIZE / 2, -CUBESIZE / 2, -CUBESIZE / 2, 0} },
    { {CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0  } }, { {-CUBESIZE / 2, CUBESIZE / 2, -CUBESIZE / 2, 0  } },
    { {-CUBESIZE / 2, -CUBESIZE / 2, CUBESIZE / 2, 0 } }, { {CUBESIZE / 2, -CUBESIZE / 2, CUBESIZE / 2, 0   } },
    { {CUBESIZE / 2, CUBESIZE / 2, CUBESIZE / 2, 0   } }, { {-CUBESIZE / 2, CUBESIZE / 2, CUBESIZE / 2, 0   } },
};

static u_short cube_indices[] = {
    0, 2, 1, 2, 0, 3,  1, 6, 5, 6, 1, 2,  5, 7, 4, 7, 5, 6,  4, 3, 0, 3, 4, 7,  4, 1, 5, 1, 4, 0,  6, 3, 7, 3, 6, 2,
};

static SDC_Mesh3D cubeMesh = { cube_vertices, cube_indices, NULL, 36, 8, POLIGON_VERTEX };

SVECTOR rotation = {0};
VECTOR translation = {0, 0, 0, 0};
MATRIX transform;

void GLGS_Init(FGameLoopGameState* GameState)
{
    //  Prepare camera in 0.0.0
    VECTOR Position = {0,0,0,0};
    dcCamera_SetScreenResolution(&GameState->PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, 0, -300, 300);
    dcCamera_LookAt(&GameState->PlayerCamera, &Position);
}

void GLGS_Update(FGameLoopGameState* GameState)
{
    RotMatrix(&rotation, &transform);
    TransMatrix(&transform, &translation);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &transform, &transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &cubeMesh, &transform, NULL);  
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}