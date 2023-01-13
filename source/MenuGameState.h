#ifndef _DC_MAINMENUGAMESTATE_
#define _DC_MAINMENUGAMESTATE_

typedef struct
{
    char PressStartText[12];
    char TeamName[30];

} MenuGameState; 

void MGS_Init(MenuGameState* MGSPtr);
void MGS_OnEnter(MenuGameState* MGSPtr);
void MGS_Update(MenuGameState* MGSPtr);
void MGS_OnExit(MenuGameState* MGSPtr);

#endif
