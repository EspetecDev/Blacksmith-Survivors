#include "Enemy.h"
#include "../Resources.h"
#include "../engine.h"
#include <assert.h>

char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius);
char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long OtherRadius);
long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition);

void EnemyInit(Enemy* Self)
{
    Self->Radius = 32;
    switch (Self->Type)
    {
        case ENEMY_RED:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyRedAnimations);
        }
        break;
        case ENEMY_BLUE:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyRedAnimations);
        }
        break;
        case ENEMY_YELLOW:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyRedAnimations);
        }
        break;
        case ENEMY_GREEN:
        {
            dcSprite_SetAnimation(&Self->CurrentSprite, &EnemyRedAnimations);
        }
        break;
    }
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

char EnemyCheckCollision(Enemy* Self, Player* ToHunt)
{
    char Collide = CharactersCollide(ToHunt->PlayerPosition, Self->Position, Self->Radius);
    return Collide;
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
    // Quitar el enemigo de la lista en el enemy manager.

}

/**
 *     long DistX = PlayerPosition.vx - OtherPosition.vx;
    long DistY = PlayerPosition.vy - OtherPosition.vy;
    return DistX < OtherRadius || DistY < OtherRadius;
 * 
*/

char PositionIsInRadius(VECTOR FirstPosition, VECTOR SecondPosition, long Radius)
{
    // Calculate the distance^2 between FirstPosition and SecondPosition
    long Distance = GetDistanceBetweenTwoPoints(FirstPosition, SecondPosition);
    long FinalRadius = DC_MUL(Radius, Radius);
    // Position is in radius if Distance^2 < Radius^2
    return (Distance < FinalRadius);
}

char CharactersCollide(VECTOR PlayerPosition, VECTOR OtherPosition, long OtherRadius)
{
    long DistX = abs(PlayerPosition.vx - OtherPosition.vx);
    long DistY = abs(PlayerPosition.vy - OtherPosition.vy);
    
    long Distance = SquareRoot0(DistX * DistX + DistY * DistY);
    return Distance < OtherRadius;
}

long GetDistanceBetweenTwoPoints(VECTOR FirstPosition, VECTOR SecondPosition)
{
    long XDistance = (FirstPosition.vx - SecondPosition.vx);
    long YDistance = (FirstPosition.vy - SecondPosition.vy);

    long Distance = DC_MUL(XDistance, XDistance) + DC_MUL(YDistance, YDistance);
    return Distance;
}