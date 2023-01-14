#ifndef _DC_ENEMY_
#define _DC_ENEMY_
#include "../engine.h"

#define ENEMY_RED_VELOCITY      10
#define ENEMY_BLUE_VELOCITY     20
#define ENEMY_YELLOW_VELOCITY   30
#define ENEMY_GREEN_VELOCITY    40

#define ENEMY_CUBESIZE 196

static SDC_Vertex enemy_quad_vertices[] = {
    { -ENEMY_CUBESIZE / 2, 0,  -ENEMY_CUBESIZE / 2, 0 },
    { -ENEMY_CUBESIZE / 2, 0, ENEMY_CUBESIZE / 2, 0  },
    { ENEMY_CUBESIZE / 2, 0, ENEMY_CUBESIZE / 2, 0  },
    { ENEMY_CUBESIZE / 2, 0, -ENEMY_CUBESIZE / 2, 0 }
};
static u_short enemy_quad_indices[] = { 0, 1, 3, 3, 1, 2 };

typedef enum
{
    ENEMY_RED,
    ENEMY_BLUE,
    ENEMY_YELLOW,
    ENEMY_GREEN
} EEnemyType;

typedef struct 
{
    int Velocity;
    EEnemyType Type;
    char Id;
    char Position[2];
    SDC_Mesh3D EnemyMesh;
} Enemy;

void EnemyInit(Enemy* Self);
void EnemyUpdate(Enemy* Self);
void EnemyDie(Enemy* Self);

#endif