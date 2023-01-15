#include "Enemy.h"
#include "../Resources.h"
#include "../engine.h"
#include <assert.h>

void EnemyInit(Enemy* Self)
{
    dcSprite_SetAnimation(&Self->CurrentSprite, &HeroWalkAnimations);   
}

void EnemyUpdate(Enemy* Self, Player* ToHunt)
{
    // Move to player
    const int EnemySpeed = 1;

    int MovementXDirection = 0;
    int MovementYDirection = 0;


    const int CheckUpSide = rand() % 200;
    if(CheckUpSide > 120)
    {
        if (Self->Position.vy < ToHunt->PlayerPosition.vy)
        {
            MovementYDirection = EnemySpeed;
        }
        else if (Self->Position.vy > ToHunt->PlayerPosition.vy)
        {
            MovementYDirection = -EnemySpeed;
        }    
    }
    else{
        
        if (Self->Position.vx < ToHunt->PlayerPosition.vx)
        {
            MovementXDirection = EnemySpeed;
        }
        else if (Self->Position.vx > ToHunt->PlayerPosition.vx)
        {
            MovementXDirection = -EnemySpeed;
        }
    }
    
    /*
    VECTOR ExpectedPos = {Self->PlayerPosition.vx + MovemementSide, Self->PlayerPosition.vy + MovementFront, 0, 0};
    if (Scene_IsInsidedBounds(&ExpectedPos))
    {
        Self->Position.vx += MovementXDirection;
        Self->Position.vy += MovementYDirection;
    }
    */

    Self->Position.vx += MovementXDirection;
    Self->Position.vy += MovementYDirection;

    dcSprite_Update(&Self->CurrentSprite);
}

void EnemyDraw(Enemy* Self, Player* MainPlayer)
{
    CVECTOR ColorSprit = {128, 128, 128, 128};

    int TopLeftX = Self->Position.vx - MainPlayer->CameraPosition.vx;
    int TopLefty = Self->Position.vy - MainPlayer->CameraPosition.vy;
    dcSprite_Render(GEngineInstance.RenderPtr, &Self->CurrentSprite, TopLeftX, TopLefty, &ColorSprit);
}

void EnemyDie(Enemy* Self)
{

}