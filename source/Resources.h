#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

/*  Texture Animations Resources */
extern RealTIMImage TimTile1;
extern RealTIMImage TimTile2;
extern RealTIMImage TimTile3;
extern RealTIMImage TimTile4;
extern RealTIMImage TimTile5;
extern RealTIMImage TimTile6;

void Resources_LoadTextureResources();

/* Sprite Animations Resources */

extern SDC_SpriteAnimation HeroIdleAnimations;
extern SDC_SpriteAnimation HeroWalkAnimations;
extern SDC_SpriteAnimation HeroAttackAnimations;
void Resources_LoadSpriteResources();

void Resources_LoadFont();

#endif