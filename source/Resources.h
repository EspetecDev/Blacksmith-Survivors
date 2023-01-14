#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

/*  Texture Animations Resources */
void Resources_LoadTextureResources();

/* Sprite Animations Resources */

extern SDC_SpriteAnimation HeroIdleAnimations;
extern SDC_SpriteAnimation HeroWalkAnimations;
extern SDC_SpriteAnimation HeroAttackAnimations;
void Resources_LoadSpriteResources();

void Resources_LoadFont();

#endif