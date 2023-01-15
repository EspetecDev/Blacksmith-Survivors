#include "GameOverGameState.h"
#include "engine.h"

void GOGS_Init(FGameOverGameState* GameState)
{
    strcpy(GameState->GameOverText, "GAME OVER");
    strcpy(GameState->PressStartText, "PRESS START TO RETURN TO MAIN MENU");
    GameState->bActivatePressStartEffet = 0;
    
    dcSprite_SetAnimation(&GameState->EnemyRedSprite, &EnemyRedAnimations);
}

void GOGS_Update(FGameOverGameState* GameState)
{
    int pad = 0;
    if (GEngineInstance.CurrentGameState == GS_GAME_OVER)
    {
        dcSprite_Update(&GameState->EnemyRedSprite);

        // Input
        pad = PadRead(0);
        if(pad & PADRleft)
        {
            GEngineInstance.DesiredGameState = GS_MAIN_MENU;
            GameState->bActivatePressStartEffet = 1;
        }

        CVECTOR ColorSprit = {128, 128, 128, 128};
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyRedSprite, RENDER_WIDTH / 2 - 32 * 2, RENDER_HEIGHT / 2 - 32, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyRedSprite, RENDER_WIDTH / 2 - 32 * 1, RENDER_HEIGHT / 2 - 32, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyRedSprite, RENDER_WIDTH / 2 + 32 * 1, RENDER_HEIGHT / 2 - 32, &ColorSprit);
        dcSprite_Render(GEngineInstance.RenderPtr, &GameState->EnemyRedSprite, RENDER_WIDTH / 2 + 32 * 2, RENDER_HEIGHT / 2 - 32, &ColorSprit);


        //DVECTOR UV = {0, 0};
        CVECTOR Color = {255, 255, 255};
        //dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTitleScreen, 0, 0, 256, 256, &UV, &Color);
        //dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT / 2 + 5 * RENDER_FONT_CHAR_SIZE, &Color, GameState->PressStartText);
        dcFont_Print(GEngineInstance.RenderPtr, RENDER_WIDTH / 2 - 5 * RENDER_FONT_CHAR_SIZE, RENDER_HEIGHT - 10 * RENDER_FONT_CHAR_SIZE, &Color, GameState->GameOverText);
    }
}

void GOGS_Close(FGameOverGameState* GameState)
{
    GameState->bActivatePressStartEffet = 0;
}