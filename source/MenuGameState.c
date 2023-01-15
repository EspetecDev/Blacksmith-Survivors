#include "MenuGameState.h"
#include "engine.h"

void MGS_Init(MenuGameState* MGSPtr)
{
    strcpy(MGSPtr->PressStartText, "PRESS START");
    strcpy(MGSPtr->TeamName, "DEMO1 - GAMEDEVCHALLENGE 2023");
    MGSPtr->bActivatePressStartEffet = 0;
    MGSPtr->PressAnimationFrames = 100;
}

extern RealTIMImage Tim;

void MGS_Update(MenuGameState* MGSPtr)
{
    if(GEngineInstance.CurrentGameState == GS_MAIN_MENU) 
    {
        // Input
        int pad = 0;
        pad = PadRead(0);
        // if(pad & PADRup)  //△
        if(pad & PADstart)
        {
            MGSPtr->bActivatePressStartEffet = 1;
            GEngineInstance.DesiredGameState = GS_CONTRACT;
        }
        // if(MGSPtr->bActivatePressStartEffet && MGSPtr->PressAnimationFrames > 0)
        // {
        //     // Set text
        //     if(MGSPtr->PressAnimationFrames % 15 == 0)
        //         strcpy(MGSPtr->PressStartText, "PRESS START");
        //     else
        //         strcpy(MGSPtr->PressStartText, "");
        //     // Draw texts
        //     FntLoad(960, 256);                // Load font to vram at FONTX,FONTY
        //     FntOpen(RENDER_WIDTH/2 - RENDER_WIDTH/4, RENDER_HEIGHT/2 - RENDER_HEIGHT/4, RENDER_WIDTH, RENDER_HEIGHT, 0, 512 );    // FntOpen(x, y, width, height,  black_bg, max. nbr. chars)
        //     FntPrint(MGSPtr->PressStartText);
        //     if(--MGSPtr->PressAnimationFrames <= 0)
        //     {
        //         MGSPtr->bActivatePressStartEffet = 0;
        //         GEngineInstance.DesiredGameState = GS_CONTRACT;
        //     }    

        // }
        DVECTOR UV = {0, 0};
        CVECTOR Color = {128, 128, 128};
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTitleScreen, 0, 0, 256, 256, &UV, &Color);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT / 2 + 5 * RENDER_FONT_CHAR_SIZE, &Color, MGSPtr->PressStartText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH - 15 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT - 5 * RENDER_FONT_CHAR_SIZE, &Color, MGSPtr->TeamName);
    }
}

void MGS_Close(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit\n");
}