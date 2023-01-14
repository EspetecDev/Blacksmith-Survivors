#ifndef _DC_ENEMY_
#define _DC_ENEMY_

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
} Enemy;

void Spawn(Enemy* Self);
void RunToEnemy(Enemy* Self);
void Die(Enemy* Self);

#endif