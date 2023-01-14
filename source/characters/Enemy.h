#ifndef _DC_ENEMY_
#define _DC_ENEMY_
#include "../engine.h"

#define ENEMY_RED_VELOCITY      10
#define ENEMY_BLUE_VELOCITY     20
#define ENEMY_YELLOW_VELOCITY   30
#define ENEMY_GREEN_VELOCITY    40

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
    VECTOR Position;
    // debug
    CVECTOR Color;
} Enemy;

static const CVECTOR EnemyRedColor = {255, 0, 0, 255};
static const CVECTOR EnemyBlueColor = {0, 0, 255, 255};
static const CVECTOR EnemyYellowColor = {0, 255, 255, 255};
static const CVECTOR EnemyGreenColor = {0, 255, 0, 255};

void EnemyInit(Enemy* Self);
void EnemyUpdate(Enemy* Self);
void EnemyDraw(Enemy* Self);
void EnemyDie(Enemy* Self);

#endif