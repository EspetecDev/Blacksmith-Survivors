#ifndef _DC_ENEMY_MANAGER_
#define _DC_ENEMY_MANAGER_
#include "Enemy.h"

#define MAX_ENEMIES 20
#define NUM_TYPE_ENEMIES 4

typedef struct 
{
    Enemy RedEnemies[MAX_ENEMIES];
    u_short NumberRedEnemy;

    Enemy BlueEnemies[MAX_ENEMIES];
    u_short NumberBlueEnemy;

    Enemy YellowEnemies[MAX_ENEMIES];
    u_short NumberYellowEnemy;

    Enemy GreenEnemies[MAX_ENEMIES];
    u_short NumberGreenEnemy;

} EnemyManager;

// Global var.
extern EnemyManager GEnemyManager;

void EM_Init(EnemyManager* EM);
void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType);
void EM_Update(EnemyManager* EM);
void EM_Draw(EnemyManager* EM);
void EM_ClearEnemies(EnemyManager* EM);

#endif