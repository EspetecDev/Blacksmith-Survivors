#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

/*  Texture Animations Resources */
extern TIM_IMAGE TimTile1;
extern TIM_IMAGE TimTile2;
extern TIM_IMAGE TimTile3;
extern TIM_IMAGE TimTile4;
extern TIM_IMAGE TimTile5;
extern TIM_IMAGE TimTile6;

void Resources_LoadTextureResources();

/* Sprite Animations Resources */

extern SDC_SpriteAnimation HeroIdleAnimations;
extern SDC_SpriteAnimation HeroWalkAnimations;
extern SDC_SpriteAnimation HeroAttackAnimations;
void Resources_LoadSpriteResources();

void Resources_LoadFont();

#endif