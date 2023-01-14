#include "dcSprite.h"
#include "dcRender.h"
#include <malloc.h>
#include <libetc.h>
#include <stdio.h>
#include <assert.h>

void dcSprite_LoadAnimationTex(SDC_SpriteAnimation* animation, u_long *image_data) {
    animation->timImage = (TIM_IMAGE*)malloc3(sizeof(TIM_IMAGE));
    dcRender_LoadTexture(animation->timImage, image_data);  
}

void dcSprite_SetAnimation(SDC_Sprite* sprite, SDC_SpriteAnimation* animation) {
    sprite->currAnimation = animation;
    sprite->currAnimFrame = 0;
    sprite->currCounter = 0;
}

void dcSprite_Update(SDC_Sprite* sprite) {
    if(sprite->currCounter > sprite->currAnimation->speed) 
    {
        sprite->currCounter = 0;
        ++sprite->currAnimFrame;
        if(sprite->currAnimFrame >= sprite->currAnimation->nframes)
            sprite->currAnimFrame = 0;
    } else
    {
        ++sprite->currCounter;
    }
}

void dcSprite_Render(SDC_Render* render, SDC_Sprite* sprite, u_short x, u_short y, CVECTOR* Color) {
    assert(sprite && sprite->currAnimation && sprite->currAnimation->timImage);
    assert(render);
    assert(sprite->currAnimFrame < sprite->currAnimation->nframes);
    SDC_SpriteFrame* currFrame = &sprite->currAnimation->frames[sprite->currAnimFrame];
    assert(currFrame);
    DVECTOR UVs = {currFrame->x,currFrame->y};
    dcRender_DrawSpriteRectNotReal(render, sprite->currAnimation->timImage, x, y, currFrame->w, currFrame->h, &UVs, Color);
}

void dcSprite_RenderUI(SDC_Render* render, TIM_IMAGE * timImage, u_short x, u_short y, u_short Width, u_short Height)
{
    CVECTOR Color = {255,255,255,255};
    DVECTOR UVs = {x,y};
    dcRender_DrawSpriteRectNotReal(render, timImage, x, y, Width, Height, &UVs, &Color);
}
