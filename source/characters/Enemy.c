#include "Enemy.h"
#include "../Resources.h"
#include "../engine.h"

void EnemyInit(Enemy* Self)
{
    Self->SpriteAnimation.frames = HeroWalkAnimations.frames;
    Self->SpriteAnimation.nframes = HeroWalkAnimations.nframes;
    Self->SpriteAnimation.speed = HeroWalkAnimations.speed;
    Self->SpriteAnimation.timImage = HeroWalkAnimations.timImage;
    dcSprite_SetAnimation(&Self->CurrentSprite, &Self->SpriteAnimation);   
}

void EnemyUpdate(Enemy* Self, Player* ToHunt)
{
    // Move to player
    const int EnemySpeed = 1;

    int MovementXDirection = 0;
    int MovementYDirection = 0;

    if (Self->Position.vy < ToHunt->PlayerPosition.vy)
    {
        MovementYDirection = EnemySpeed;
    }
    else if (Self->Position.vy > ToHunt->PlayerPosition.vy)
    {
        MovementYDirection = -EnemySpeed;
    }

    if (Self->Position.vx < ToHunt->PlayerPosition.vx)
    {
        MovementXDirection = EnemySpeed;
    }
    else if (Self->Position.vx > ToHunt->PlayerPosition.vx)
    {
        MovementXDirection = -EnemySpeed;
    }

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