#include "MenuGameState.h"
#include "engine.h"

void MGS_Init(MenuGameState* MGSPtr)
{
    // strcpy(MGSPtr->PressStartText, "PRESS START");
    // strcpy(MGSPtr->PressStartText, "\n012345678\n\nABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // strcpy(MGSPtr->TeamName, "Demo1 - GameDevChallenge 2023");
    MGSPtr->bActivatePressStartEffet = 0;
    MGSPtr->PressAnimationFrames = 100;

    dcSprite_SetAnimation(&MGSPtr->TitleScreenSprite, &TitleScreenAnimations);
}

void MGS_Update(MenuGameState* MGSPtr)
{
    if(GEngineInstance.CurrentGameState == GS_MAIN_MENU) 
    {
        // Input
        int pad = 0;
        pad = PadRead(0);
        // if(pad & PADstart)
        if(pad & PADRup)  //△
        {
            MGSPtr->bActivatePressStartEffet = 1;
            GEngineInstance.DesiredGameState = GS_CONTRACT;
        }
        FntPrint(MGSPtr->PressStartText);
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
        CVECTOR ColorSprit = {128, 128, 128, 128};
        dcSprite_Render(GEngineInstance.RenderPtr, &MGSPtr->TitleScreenSprite, 0, 0, &ColorSprit);

        // dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE, 
    }
}

void MGS_Close(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit\n");
}