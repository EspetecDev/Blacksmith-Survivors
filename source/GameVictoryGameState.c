#include "GameOverGameState.h"
#include "engine.h"

void GVGS_Init(FGameVictoryGameState* GameState)
{
    strcpy(GameState->VictoryText, "VICT'RY");
    strcpy(GameState->PressStartText, "PRESS START TO RETURN TO MAIN MENU");
    GameState->bActivatePressStartEffet = 0;
    
    dcSprite_SetAnimation(&GameState->PlayerSprite, &HeroWalkAnimations);
}

void GVGS_Update(FGameVictoryGameState* GameState)
{
    int pad = 0;
    if (GEngineInstance.CurrentGameState == GS_GAME_VICTORY)
    {
        dcSprite_Update(&GameState->PlayerSprite);

        // Input
        pad = PadRead(0);
        if(pad & PADRleft)
        {
            GEngineInstance.DesiredGameState = GS_MAIN_MENU;
            GameState->bActivatePressStartEffet = 1;
        }

        CVECTOR ColorSprit = {128, 128, 128, 128};
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->PlayerSprite, RENDER_WIDTH / 2 - 16, RENDER_HEIGHT / 2 - 32, &ColorSprit);


        CVECTOR Color = {255, 255, 255};
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 16 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT / 2 + 10 * RENDER_FONT_CHAR_SIZE, &Color, GameState->PressStartText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE,  7 * RENDER_FONT_CHAR_SIZE, &Color, GameState->VictoryText);
    }
}

void GVGS_Close(FGameVictoryGameState* GameState)
{
    GameState->bActivatePressStartEffet = 0;
}