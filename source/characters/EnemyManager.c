#include "EnemyManager.h"
#include "../engine.h"

EnemyManager GEnemyManager;

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType);

void EM_Init(EnemyManager* EM)
{
    for(int i=0;i<NUM_TYPE_ENEMIES;i++)
    {
        EM_CreateEnemy(EM, &EM->RedEnemies[i], ENEMY_RED);
    }
    
    for(int i=0;i<NUM_TYPE_ENEMIES;i++)
    {
        EM_CreateEnemy(EM, &EM->BlueEnemies[i], ENEMY_BLUE);
    }

    for(int i=0;i<NUM_TYPE_ENEMIES;i++)
    {
        EM_CreateEnemy(EM, &EM->YellowEnemies[i], ENEMY_YELLOW);
    }

    for(int i=0;i<NUM_TYPE_ENEMIES;i++)
    {
        EM_CreateEnemy(EM, &EM->GreenEnemies[i], ENEMY_GREEN);
    }

     EM->NumberRedEnemy = 0;
     EM->NumberBlueEnemy = 0;
     EM->NumberGreenEnemy = 0;
     EM->NumberYellowEnemy = 0;
}

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType)
{
    EnemyToFill->Type = EnemyType;
    switch (EnemyType)
    {
        case ENEMY_RED:
            EnemyToFill->Velocity = ENEMY_RED_VELOCITY;
            EnemyToFill->Color = EnemyRedColor;
            EnemyToFill->Position.vx = 50;
            EnemyToFill->Position.vy = 0;
            EnemyToFill->Position.vz = -10;
        break;
        case ENEMY_BLUE:
            EnemyToFill->Velocity = ENEMY_BLUE_VELOCITY;
            EnemyToFill->Color = EnemyBlueColor;
            EnemyToFill->Position.vx = 0;
            EnemyToFill->Position.vy = 50;
            EnemyToFill->Position.vz = -12;
        break;
        case ENEMY_YELLOW:
            EnemyToFill->Velocity = ENEMY_YELLOW_VELOCITY;
            EnemyToFill->Color = EnemyYellowColor;
            EnemyToFill->Position.vx = 50;
            EnemyToFill->Position.vy = 0;
            EnemyToFill->Position.vz = -14;
        break;
        case ENEMY_GREEN:
            EnemyToFill->Velocity = ENEMY_GREEN_VELOCITY;
            EnemyToFill->Color = EnemyGreenColor;
            EnemyToFill->Position.vx = 0;
            EnemyToFill->Position.vy = 150;
            EnemyToFill->Position.vz = -16;
        break;
    default:
        break;
    }
}

void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType)
{
    switch (EnemyType)
    {
        case ENEMY_RED:
            if(EM->NumberRedEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberRedEnemy], ENEMY_RED);
                EM->NumberRedEnemy++;
            }
        break;
        case ENEMY_BLUE:
            if(EM->NumberBlueEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberBlueEnemy], ENEMY_RED);
                EM->NumberBlueEnemy++;
            }
        break;
        case ENEMY_YELLOW:
            if(EM->NumberYellowEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberYellowEnemy], ENEMY_RED);
                EM->NumberYellowEnemy++;
            }
        break;
        case ENEMY_GREEN:
            if(EM->NumberGreenEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberGreenEnemy], ENEMY_RED);
                EM->NumberGreenEnemy++;
            }
        break;
    default:
        break;
    }
}

void EM_Update(EnemyManager* EM)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyUpdate(&EM->RedEnemies[i]);
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyUpdate(&EM->BlueEnemies[i]);
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyUpdate(&EM->YellowEnemies[i]);
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyUpdate(&EM->GreenEnemies[i]);
    }
}

void EM_Draw(EnemyManager* EM)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyDraw(&EM->RedEnemies[i]);
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyDraw(&EM->BlueEnemies[i]);
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyDraw(&EM->YellowEnemies[i]);
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyDraw(&EM->GreenEnemies[i]);
    }
}

void EM_ClearEnemies(EnemyManager* EM)
{

}