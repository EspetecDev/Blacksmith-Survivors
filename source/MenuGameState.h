#ifndef _DC_MAINMENUGAMESTATE_
#define _DC_MAINMENUGAMESTATE_

typedef struct
{
    char PressStartText[12];
    char TeamName[30];
    char bActivatePressStartEffet;
    char PressAnimationFrames;

} MenuGameState; 

void MGS_Init(MenuGameState* MGSPtr);
void MGS_Update(MenuGameState* MGSPtr);
void MGS_Close(MenuGameState* MGSPtr);

#endif
