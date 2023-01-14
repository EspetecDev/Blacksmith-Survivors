#ifndef _DC_ENEMY_MANAGER_
#define _DC_ENEMY_MANAGER_
#include "Enemy.h"

#define MAX_ENEMIES 20
#define NUM_TYPE_ENEMIES 4

typedef struct 
{
    // Order assumed is:  ENEMY_RED, ENEMY_BLUE, ENEMY_YELLOW, ENEMY_GREEN
    // 20 enemies cap, 4 enemy types
    Enemy* EnemyArray[MAX_ENEMIES][NUM_TYPE_ENEMIES];
    // Here we will store how many enemies per type
    char NumEnemies[4];

} EnemyManager;

// Global var.
extern EnemyManager GEenemyManager;

void EM_Init(EnemyManager* EM);
void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType);
void EM_Update(EnemyManager* EM);
void EM_ClearEnemies(EnemyManager* EM);

#endif