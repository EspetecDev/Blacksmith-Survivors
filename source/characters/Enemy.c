#include "Enemy.h"

void EnemyInit(Enemy* Self)
{
    // Init quad
    const SDC_Vertex enemy_quad_vertices[] = {
        { -ENEMY_CUBESIZE / 2, 0,  -ENEMY_CUBESIZE / 2, 0 },
        { -ENEMY_CUBESIZE / 2, 0, ENEMY_CUBESIZE / 2, 0  },
        { ENEMY_CUBESIZE / 2, 0, ENEMY_CUBESIZE / 2, 0  },
        { ENEMY_CUBESIZE / 2, 0, -ENEMY_CUBESIZE / 2, 0 }
    };
    const u_short enemy_quad_indices[] = { 0, 1, 3, 3, 1, 2 };

    Self->EnemyMesh.vertexs = enemy_quad_vertices;
    Self->EnemyMesh.indices = enemy_quad_indices;
    Self->EnemyMesh.numVertices = 6;
    Self->EnemyMesh.numIndices = 4;
    Self->EnemyMesh.tim = NULL; //Loadtexture
    Self->EnemyMesh.polygonVertexType = POLIGON_VERTEX;
}

void EnemyUpdate(Enemy* Self)
{
    // Move to player

    // Draw quad
    if(GEngineInstance.CurrentGameState == GS_GAME_LOOP)
    {
        SVECTOR rotation = {0};
        VECTOR translation = {0, 0, 0, 0};
        MATRIX transform;

        RotMatrix(&rotation, &transform);
        TransMatrix(&transform, &translation);
        dcCamera_ApplyCameraTransform(&GEngineInstance.GameLoopGameState->PlayerCamera, &transform, &transform);
        dcRender_DrawMesh(GEngineInstance.RenderPtr, &Self->EnemyMesh, &transform, NULL);
    }
}

void EnemyDie(Enemy* Self)
{

}