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
        CVECTOR Color = {128, 128, 128};
        CVECTOR PermColor = {128, 128, 128};
        // Input
        int pad = 0;
        pad = PadRead(0);
        // if(pad & PADRup)  //△
        if(pad & PADstart)
        {
            MGSPtr->bActivatePressStartEffet = 1;
            // GEngineInstance.DesiredGameState = GS_GAME_LOOP;
        }
        if(MGSPtr->bActivatePressStartEffet && MGSPtr->PressAnimationFrames > 0)
        {
            // Set text
            if(MGSPtr->PressAnimationFrames >= FRAMES_PER_STATE_ANIM)
            {
                if(Color.r == 128)
                {
                    Color.r = 128;
                    Color.g = 128;
                    Color.b = 128;
                }
                else
                {
                    Color.r = 0;
                    Color.g = 0;
                    Color.b = 0;
                }
                MGSPtr->PressAnimationFrames = 0;
            }
            
            if(--MGSPtr->PressAnimationFrames <= 0)
            {
                MGSPtr->bActivatePressStartEffet = 0;
                GEngineInstance.DesiredGameState = GS_GAME_LOOP;
            }    

        }
        // Draw texts
        DVECTOR UV = {0, 0};
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT / 2 + 5 * RENDER_FONT_CHAR_SIZE, &Color, MGSPtr->PressStartText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH - 15 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT - 5 * RENDER_FONT_CHAR_SIZE, &PermColor, MGSPtr->TeamName);            
        dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTitleScreen, 0, 0, 256, 256, &UV, &PermColor);
    }
}

void MGS_Close(MenuGameState* MGSPtr)
{
   printf("MenuGameState::OnExit\n");
}