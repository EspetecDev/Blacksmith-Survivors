#include "EnemyManager.h"
#include "../engine.h"

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType, Player* ToHunt);

void EM_Init(EnemyManager* EM, SceneMap* Map, Player* ToHunt)
{
     EM->NumberRedEnemy = 0;
     EM->NumberBlueEnemy = 0;
     EM->NumberGreenEnemy = 0;
     EM->NumberYellowEnemy = 0;
}

void EM_CreateEnemy(EnemyManager* EM, Enemy * EnemyToFill, EEnemyType EnemyType, Player* ToHunt)
{
    EnemyToFill->Type = EnemyType;
    switch (EnemyType)
    {
        case ENEMY_RED:
            EnemyToFill->Velocity = ENEMY_RED_VELOCITY;
            EnemyToFill->Color = EnemyRedColor;
        break;
        case ENEMY_BLUE:
            EnemyToFill->Velocity = ENEMY_BLUE_VELOCITY;
            EnemyToFill->Color = EnemyBlueColor;
        break;
        case ENEMY_YELLOW:
            EnemyToFill->Velocity = ENEMY_YELLOW_VELOCITY;
            EnemyToFill->Color = EnemyYellowColor;
        break;
        case ENEMY_GREEN:
            EnemyToFill->Velocity = ENEMY_GREEN_VELOCITY;
            EnemyToFill->Color = EnemyGreenColor;
        break;
    default:
        break;
    }

    EM_GenerateFarFromPlayerLocations(EM, ToHunt, EnemyToFill);
    EnemyInit(EnemyToFill);

}

void EM_SpawnEnemy(EnemyManager* EM, EEnemyType EnemyType, Player* ToHunt)
{
    switch (EnemyType)
    {
        case ENEMY_RED:
            if(EM->NumberRedEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->RedEnemies[EM->NumberRedEnemy], ENEMY_RED, ToHunt);
                EM->NumberRedEnemy++;
            }
        break;
        case ENEMY_BLUE:
            if(EM->NumberBlueEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->BlueEnemies[EM->NumberBlueEnemy], ENEMY_BLUE, ToHunt);
                EM->NumberBlueEnemy++;
            }
        break;
        case ENEMY_YELLOW:
            if(EM->NumberYellowEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->YellowEnemies[EM->NumberYellowEnemy], ENEMY_YELLOW, ToHunt);
                EM->NumberYellowEnemy++;
            }
        break;
        case ENEMY_GREEN:
            if(EM->NumberGreenEnemy < MAX_ENEMIES)
            {
                EM_CreateEnemy(EM, &EM->GreenEnemies[EM->NumberGreenEnemy], ENEMY_GREEN, ToHunt);
                EM->NumberGreenEnemy++;
            }
        break;
    default:
        break;
    }
}

void EM_Update(EnemyManager* EM, Player* ToHunt)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyUpdate(&EM->RedEnemies[i], ToHunt);
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyUpdate(&EM->BlueEnemies[i], ToHunt);
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyUpdate(&EM->YellowEnemies[i], ToHunt);
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyUpdate(&EM->GreenEnemies[i], ToHunt);
    }
}

void EM_Draw(EnemyManager* EM, Player* MainPlayer)
{
    for(int i=0;i<EM->NumberRedEnemy;i++)
    {
        EnemyDraw(&EM->RedEnemies[i], MainPlayer);
    }
    
    for(int i=0;i<EM->NumberBlueEnemy;i++)
    {
        EnemyDraw(&EM->BlueEnemies[i], MainPlayer);
    }

    for(int i=0;i<EM->NumberYellowEnemy;i++)
    {
        EnemyDraw(&EM->YellowEnemies[i], MainPlayer);
    }

    for(int i=0;i<EM->NumberGreenEnemy;i++)
    {
        EnemyDraw(&EM->GreenEnemies[i], MainPlayer);
    }
}

void EM_ClearEnemies(EnemyManager* EM)
{

}

void EM_GenerateFarFromPlayerLocations(EnemyManager* EM, Player* ToHunt, Enemy* ToFill)
{
    VECTOR PlayerPosition = ToHunt->PlayerPosition;
    int IsPositiveX = rand() % 2;
    int IsPositiveY = rand() % 2;
    int ModifyX = rand() % 2;

    if (ModifyX)
    {
        int PosX = rand() % RENDER_WIDTH;

        if (IsPositiveX)
        {
            PlayerPosition.vx += PosX;
        }
        else
        {
            PlayerPosition.vx -= PosX;
        }
    }
    else
    {
        int PosY = rand() % RENDER_HEIGHT;

        if (IsPositiveY)
        {
            PlayerPosition.vy += PosY;
        }
        else
        {
            PlayerPosition.vy -= PosY;
        }
    }
    ToFill->Position = PlayerPosition;
    
}