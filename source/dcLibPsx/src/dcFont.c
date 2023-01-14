#include "dcFont.h"
#include <types.h>

typedef struct {
    TIM_IMAGE tim;
    u_short firstChar;
    u_short charsPerLine;
    u_short charWidth;
    u_short charHeight;
    u_short lineWidth;
} SFont;

SFont gFont;

void dcFont_Load(unsigned long *texture) {
    gFont.firstChar = 32;
    gFont.charsPerLine = 16;
    gFont.charWidth = 8;
    gFont.charHeight = 8;
    gFont.lineWidth = gFont.charsPerLine*gFont.charWidth;
    dcRender_LoadTexture(&gFont.tim, texture);
}

#pragma GCC push_options
#pragma GCC optimize ("O0")

void dcFont_Print(SDC_Render* render, int x, int y, CVECTOR *color, const char *text) {
    int idx = 0;
    DVECTOR uv;
    while(text[idx] != 0) {
        int idxFont = text[idx] - gFont.firstChar;
        uv.vx = (idxFont * gFont.charWidth) % (gFont.lineWidth);
        uv.vy = (idxFont/gFont.charsPerLine) * gFont.charHeight;
        dcRender_DrawSpriteRect(render, &gFont.tim, x, y, gFont.charWidth, gFont.charHeight, &uv, color);
        ++idx;
        x += gFont.charWidth;
    }
}

#pragma GCC pop_options
