#ifndef _DC_MAINMENUGAMESTATE_
#define _DC_MAINMENUGAMESTATE_
#include "dcSprite.h"

#define FRAMES_PER_STATE_ANIM 10

typedef struct
{
    char PressStartText[12];
    char TeamName[30];
    char bActivatePressStartEffet;
    char PressAnimationFrames;
    SDC_Sprite TitleScreenSprite;

} MenuGameState; 

void MGS_Init(MenuGameState* MGSPtr);
void MGS_Update(MenuGameState* MGSPtr);
void MGS_Close(MenuGameState* MGSPtr);

#endif
