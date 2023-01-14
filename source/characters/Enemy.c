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
        VECTOR Translation = {Self->Position.vx, Self->Position.vy, 0, 0};
        VECTOR Scale = {ONE, ONE, 0, 0};
        DrawDebugQuad(GEngineInstance.GameLoopGameState, &Translation,&Self->Color, &Scale);
    }
}

void EnemyDie(Enemy* Self)
{

}