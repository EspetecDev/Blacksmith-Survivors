#include "engine.h"

/*  Texture Animations Resources */
extern unsigned long _binary_textures_Enemy_Blue_tim_start[];
extern unsigned long _binary_textures_Hero_tim_start[];

TIM_IMAGE tim_enemy_blue;

void Resources_LoadTextureResources()
{
    dcRender_LoadTexture(&tim_enemy_blue, _binary_textures_Enemy_Blue_tim_start);
}

// Hero Run Animation.
SDC_SpriteFrame HeroRunFrames[] =
    {
        {0, 0, 64, 32}};
SDC_SpriteAnimation HeroRunAnimation = {HeroRunFrames, NULL, 1, 1, 0, 0};

void Resources_LoadSpriteResources()
{
    dcSprite_LoadAnimationTex(&HeroRunAnimation, _binary_textures_Hero_tim_start);
}

extern unsigned long _binary_textures_fnt_tim_start[];
void Resources_LoadFont()
{
    dcFont_Load(_binary_textures_fnt_tim_start);
}