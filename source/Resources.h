#ifndef _DC_SPRITETEST_GAMESTATE
#define _DC_SPRITETEST_GAMESTATE

/*  Render Memory Texture Mapping   */

//  Render display: 0, 0, 640, 240.
//  Second Render display: 0, 240, 640, 240. 


/*  Texture Animations Resources */

extern TIM_IMAGE tim_smile;
void Resources_LoadTextureResources();

/* Sprite Animations Resources */
// extern unsigned long _binary_sonic_tim_start[];

void Resources_LoadSpriteResources();

SDC_SpriteAnimation GetHeroRunAnimation();
SDC_SpriteAnimation GetHeroIdleAnimation();
#endif