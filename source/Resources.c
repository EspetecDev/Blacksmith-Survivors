#include "engine.h"

/*  Texture Animations Resources */

extern unsigned long _binary_textures_tile1_tim_start[];
extern unsigned long _binary_textures_tile2_tim_start[];
extern unsigned long _binary_textures_tile3_tim_start[];
extern unsigned long _binary_textures_tile4_tim_start[];
extern unsigned long _binary_textures_tile5_tim_start[];
extern unsigned long _binary_textures_tile6_tim_start[];
extern unsigned long _binary_textures_titlescreen_tim_start[];

RealTIMImage TimTile1;
RealTIMImage TimTile2;
RealTIMImage TimTile3;
RealTIMImage TimTile4;
RealTIMImage TimTile5;
RealTIMImage TimTile6;
RealTIMImage TimTitleScreen;

extern unsigned long _binary_textures_HeroIdle_tim_start[];
extern unsigned long _binary_textures_HeroWalk_tim_start[];
extern unsigned long _binary_textures_HeroAttack_tim_start[];

#pragma GCC push_options
#pragma GCC optimize ("O0")

void Resources_LoadTextureResources()
{
    TIM_IMAGE Image;
    dcRender_LoadTexture(&Image, _binary_textures_tile1_tim_start);
    TimTile1.crect = *Image.crect;
    TimTile1.mode = Image.mode;
    TimTile1.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile2_tim_start);
    TimTile2.crect = *Image.crect;
    TimTile2.mode = Image.mode;
    TimTile2.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile3_tim_start);
    TimTile3.crect = *Image.crect;
    TimTile3.mode = Image.mode;
    TimTile3.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile4_tim_start);
    TimTile4.crect = *Image.crect;
    TimTile4.mode = Image.mode;
    TimTile4.prect = *Image.prect;

    dcRender_LoadTexture(&Image, _binary_textures_tile5_tim_start);
    TimTile5.crect = *Image.crect;
    TimTile5.mode = Image.mode;
    TimTile5.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_tile6_tim_start);
   TimTile6.crect = *Image.crect;
   TimTile6.mode = Image.mode;
   TimTile6.prect = *Image.prect;

   dcRender_LoadTexture(&Image, _binary_textures_titlescreen_tim_start);
   TimTitleScreen.crect = *Image.crect;
   TimTitleScreen.mode = Image.mode;
   TimTitleScreen.prect = *Image.prect;
}

#pragma GCC pop_options


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

SDC_SpriteFrame TitleScreenFrames[] =
{
    {0,0,256,256}
};

SDC_SpriteAnimation HeroIdleAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroWalkAnimations = {HeroIdleWalkFrames, NULL, 3, 6, 0, 0};
SDC_SpriteAnimation HeroAttackAnimations = {HeroAttackFrames, NULL, 3, 5, 0, 0};
// SDC_SpriteAnimation TitleScreenAnimations = {TitleScreenFrames, NULL, 1, 1, 0, 0};

void Resources_LoadSpriteResources()
{
    dcSprite_LoadAnimationTex(&HeroIdleAnimations, _binary_textures_HeroIdle_tim_start);
    dcSprite_LoadAnimationTex(&HeroWalkAnimations, _binary_textures_HeroWalk_tim_start);
    dcSprite_LoadAnimationTex(&HeroAttackAnimations, _binary_textures_HeroAttack_tim_start);
    // dcSprite_LoadAnimationTex(&TitleScreenAnimations, _binary_textures_TitleScreen_tim_start);
}

extern unsigned long _binary_textures_fnt_tim_start[];
void Resources_LoadFont()
{
    dcFont_Load(_binary_textures_fnt_tim_start);
}