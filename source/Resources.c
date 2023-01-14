#include "engine.h"

/*  Texture Animations Resources */

extern unsigned long _binary_textures_Enemy_Blue_tim_start[];
TIM_IMAGE tim_smile;

void Resources_LoadTextureResources()
{
    dcRender_LoadTexture(&tim_smile, _binary_textures_Enemy_Blue_tim_start);
}

/* Sprite Animations Header. */

extern unsigned long _binary_textures_hero_tim_start[];

// Hero Run Animation.
SDC_SpriteFrame HeroRunFrames[] =
{
    {0,0,32,32}
};
SDC_SpriteAnimation HeroRunAnimation = {HeroRunFrames, NULL, 1, 1, 0, 0};

void Resources_LoadSpriteResources()
{
    dcSprite_LoadAnimationTex(&HeroRunAnimation, _binary_textures_hero_tim_start);
}