#include "Enemy.h"

void DrawDebugQuad(FGameLoopGameState* GameState, VECTOR * Translation, CVECTOR * ColorQuad, VECTOR * Scale);

void EnemyInit(Enemy* Self)
{
    
}

void EnemyUpdate(Enemy* Self)
{
    // Move to player

    // Draw quad
    if(GEngineInstance.CurrentGameState == GS_GAME_LOOP)
    {
        // VECTOR Translation = {Self->Position.vx, Self->Position.vy, 0, 0};
        // VECTOR Scale = {ONE/2, ONE/2, 0, 0};
        // CVECTOR test = {255,255,0,0};
        // // DrawDebugQuad(GEngineInstance.GameLoopGameState, &Translation,&Self->Color, &Scale);
        // DrawDebugQuad(GEngineInstance.GameLoopGameState, &Translation,&test, &Scale);
    }
}

void EnemyDie(Enemy* Self)
{

}