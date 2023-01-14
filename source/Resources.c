#include "engine.h"

/*  Texture Animations Resources */

extern unsigned long _binary_textures_tile1_tim_start[];
extern unsigned long _binary_textures_tile2_tim_start[];
extern unsigned long _binary_textures_tile3_tim_start[];
extern unsigned long _binary_textures_tile4_tim_start[];
extern unsigned long _binary_textures_tile5_tim_start[];
extern unsigned long _binary_textures_tile6_tim_start[];

TIM_IMAGE TimTile1;
TIM_IMAGE TimTile2;
TIM_IMAGE TimTile3;
TIM_IMAGE TimTile4;
TIM_IMAGE TimTile5;
TIM_IMAGE TimTile6;
extern unsigned long _binary_textures_HeroIdle_tim_start[];
extern unsigned long _binary_textures_HeroWalk_tim_start[];
extern unsigned long _binary_textures_HeroAttack_tim_start[];

void Resources_LoadTextureResources()
{
   dcRender_LoadTexture(&TimTile1, _binary_textures_tile1_tim_start);
   dcRender_LoadTexture(&TimTile2, _binary_textures_tile2_tim_start);
   dcRender_LoadTexture(&TimTile3, _binary_textures_tile3_tim_start);
   dcRender_LoadTexture(&TimTile4, _binary_textures_tile4_tim_start);
   dcRender_LoadTexture(&TimTile5, _binary_textures_tile5_tim_start);
   dcRender_LoadTexture(&TimTile6, _binary_textures_tile6_tim_start);
}

/* Sprite Animations Header. */



// Hero Run Animation.
SDC_SpriteFrame HeroIdleWalkFrames[] =
{
    {5,0,18,64}, {26,0,18,64}, {47,0,18,64}, {67,0,18,64}, {87,0,18,64}, {107, 0, 18, 64}
};

SDC_SpriteFrame HeroAttackFrames[] =
{
    {5,0,19,64}, {26,0,20,64},  {48,0,29,64}, {79,0,27,64}, {107,0,18,64}
};

SDC_SpriteAnimation HeroIdleAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroWalkAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroAttackAnimations = {HeroAttackFrames, NULL, 3, 5, 0, 0};

void Resources_LoadSpriteResources()
{
    dcSprite_LoadAnimationTex(&HeroIdleAnimations, _binary_textures_HeroIdle_tim_start);
    dcSprite_LoadAnimationTex(&HeroWalkAnimations, _binary_textures_HeroWalk_tim_start);
    dcSprite_LoadAnimationTex(&HeroAttackAnimations, _binary_textures_HeroAttack_tim_start);
}

extern unsigned long _binary_textures_fnt_tim_start[];
void Resources_LoadFont()
{
    dcFont_Load(_binary_textures_fnt_tim_start);
}