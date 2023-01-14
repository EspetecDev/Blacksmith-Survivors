#include "EnemyManager.h"
#include "../engine.h"

EnemyManager GEenemyManager;

void EM_Init(EnemyManager* EM)
{
    // for(int i=0;i<NUM_TYPE_ENEMIES;i++)
    // {
    //     for(int j=0;j<NUM_TYPE_ENEMIES;j++)
    //     {
    //         EM->EnemyArray[i][j]; 
    //     }
    // }

    for(int i=0;i<NUM_TYPE_ENEMIES;i++)
        EM->NumEnemies[i] = 0;

}

void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType)
{
    Enemy* NewEnemy = (Enemy*)malloc3(sizeof(Enemy));
    NewEnemy->Id = EM->NumEnemies[EnemyType]++;
    NewEnemy->Type = EnemyType;
    switch (EnemyType)
    {
        case ENEMY_RED:
            NewEnemy->Velocity = ENEMY_RED_VELOCITY;
            NewEnemy->Color = EnemyRedColor;
            NewEnemy->Position.vx = 50;
            NewEnemy->Position.vy = 0;
        break;
        case ENEMY_BLUE:
            NewEnemy->Velocity = ENEMY_BLUE_VELOCITY;
            NewEnemy->Color = EnemyBlueColor;
            NewEnemy->Position.vx = 0;
            NewEnemy->Position.vy = -50;
        break;
        case ENEMY_YELLOW:
            NewEnemy->Velocity = ENEMY_YELLOW_VELOCITY;
            NewEnemy->Color = EnemyYellowColor;
            NewEnemy->Position.vx = -50;
            NewEnemy->Position.vy = 0;
        break;
        case ENEMY_GREEN:
            NewEnemy->Velocity = ENEMY_GREEN_VELOCITY;
            NewEnemy->Color = EnemyGreenColor;
            NewEnemy->Position.vx = 0;
            NewEnemy->Position.vy = 50;
        break;
    default:
        break;
    }
    EM->EnemyArray[(int)NewEnemy->Id][EnemyType] = NewEnemy;
}

void EM_Update(EnemyManager* EM)
{
    for(int i=0; i<MAX_ENEMIES; i++)
    {
        for(int j=0; j<NUM_TYPE_ENEMIES; j++)
        {
            EnemyUpdate(EM->EnemyArray[i][j]);
        }
    }
}

void EM_ClearEnemies(EnemyManager* EM)
{
    for(int i=0; i<MAX_ENEMIES; i++)
    {
        for(int j=0; j<NUM_TYPE_ENEMIES; j++)
        {
            free(EM->EnemyArray[i][j]);
        }
    }
}