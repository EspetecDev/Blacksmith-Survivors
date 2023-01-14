#include "GameLoopGameState.h"
#include "engine.h"
#include "render.h"
#include "renderMeshes.h"
#include "dcMisc.h"

#define CameraHeightPosition -300

void InitScene(FGameLoopGameState* GameState);
void DrawSceneAssets(FGameLoopGameState* GameState);
void DrawAsset(FGameLoopGameState* GameState, VECTOR * Translation, TIM_IMAGE * AssetTexture);

void GLGS_Init(FGameLoopGameState* GameState)
{
    //  Setup player data.
    InitPlayer(GameState);

    //  Setup scene data.
    InitScene(GameState);

    //  Setup camera start.
    dcCamera_SetScreenResolution(&GameState->PlayerCamera, RENDER_WIDTH, RENDER_HEIGHT);
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, CameraHeightPosition);
    dcCamera_LookAt(&GameState->PlayerCamera, &GameState->Player->PlayerPosition);
}

void HandlePlayerInput(FGameLoopGameState* GameState)
{
    // Constants player speed.
    const int PlayerMovementForward = 100;
    const int PlayerMovementSide = 100;


    u_long padState = PadRead(0);
    long MovementFront = 0;
    long MovemementSide = 0;

    // Y AXIS
    if( _PAD(0,PADLup ) & padState )
    {
        MovementFront = PlayerMovementForward;
    }
    if( _PAD(0,PADLdown ) & padState )
    {
        MovementFront = -PlayerMovementForward;
    }

    // X AXIS
    if( _PAD(0,PADLright ) & padState )
    {
        MovemementSide = -PlayerMovementSide;
    }
    if( _PAD(0,PADLleft ) & padState )
    {
        MovemementSide = PlayerMovementSide;
    }

    /*
    if (MovementFront != 0 || MovemementSide != 0)
    {
        if (GameState->Player->CurrentPlayerAction != PLAYER_MOVING)
        {
            GameState->Player->CurrentPlayerAction = PLAYER_MOVING;
            //dcSprite_SetAnimation(&GameState->Player->Animations[PLAYER_MOVING].CurrentSprite, &GameState->Player->Animations[PLAYER_MOVING].Animation);
        }
    }
    else
    {
        if (GameState->Player->CurrentPlayerAction != PLAYER_IDLE)
        {
            GameState->Player->CurrentPlayerAction = PLAYER_IDLE;
        }
    }*/

    if(padState & PADRdown) // X
    {
        GEngineInstance.DesiredGameState = GS_GAME_OVER;
    }
    
    //  Move player position.
    GameState->Player->PlayerPosition.vy += MovementFront;
    GameState->Player->PlayerPosition.vx += MovemementSide;

    //  Move camera to follow player.
    dcCamera_SetCameraPosition(&GameState->PlayerCamera, GameState->Player->PlayerPosition.vx, GameState->Player->PlayerPosition.vy, CameraHeightPosition );
    dcCamera_LookAt(&GameState->PlayerCamera, &GameState->Player->PlayerPosition);    
}

void GLGS_Update(FGameLoopGameState* GameState)
{
    //  Move player.
    HandlePlayerInput(GameState);
    
    DrawSceneAssets(GameState);

    //dcSprite_Update(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite);
    //dcSprite_Render(GEngineInstance.RenderPtr, &GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, RENDER_WIDTH/2, RENDER_HEIGHT/2, &ColorSprit);
}

void GLGS_Close(FGameLoopGameState* GameState)
{

}

void InitPlayer(FGameLoopGameState* GameState)
{
    VECTOR StartPos =  {0, 0, 0, 0};
    GameState->Player->PlayerPosition = StartPos;

    FAnimationTypes MovingAnimation;
    //FAnimationTypes IdleAnimation;

    MovingAnimation.Animation = HeroRunAnimation;

    GameState->Player->Animations[PLAYER_MOVING] = MovingAnimation;
    //GameState->Player->Animations[PLAYER_IDLE] = IdleAnimation;

    GameState->Player->CurrentPlayerAction = PLAYER_MOVING;
    GameState->Player->CurrentPlayerAnimation = GameState->Player->Animations[GameState->Player->CurrentPlayerAction];
    dcSprite_SetAnimation(&GameState->Player->Animations[GameState->Player->CurrentPlayerAction].CurrentSprite, &GameState->Player->CurrentPlayerAnimation.Animation);
}

void InitScene(FGameLoopGameState* GameState)
{
    SceneMap_Init(&GameState->SceneData);
}

void DrawAsset(FGameLoopGameState* GameState, VECTOR * Translation, TIM_IMAGE * AssetTexture)
{
    // TOOD: Move into GS if possible as optim.
    SDC_DrawParams DrawParams;
    MATRIX Transform;
    SVECTOR Rotation = {0};

    DrawParams.tim = AssetTexture;
    RotMatrix(&Rotation, &Transform);
    TransMatrix(&Transform, Translation);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &Transform, &Transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &QuadAssetMesh, &Transform, &DrawParams);
}

void DrawDebugQuad(FGameLoopGameState* GameState, VECTOR * Translation, CVECTOR * ColorQuad, VECTOR * Scale)
{
    // TOOD: Move into GS if possible as optim.
    SDC_DrawParams DrawParams;
    MATRIX Transform;
    SVECTOR Rotation = {0};

    DrawParams.constantColor = *ColorQuad;
    RotMatrix(&Rotation, &Transform);
    TransMatrix(&Transform, Translation);
    ScaleMatrix(&Transform, Scale);
    dcCamera_ApplyCameraTransform(&GameState->PlayerCamera, &Transform, &Transform);
    dcRender_DrawMesh(GEngineInstance.RenderPtr, &QuadDebugMesh, &Transform, &DrawParams);
}

void DrawSceneAssets(FGameLoopGameState* GameState)
{
    dcMisc_DrawAxis(GEngineInstance.RenderPtr, &GameState->PlayerCamera);

    //  Scene
    //VECTOR SceneTranslation = {GameState->SceneData.MapAssetOriginAndDim.vx, GameState->SceneData.MapAssetOriginAndDim.vy, 20, 0};
    //CVECTOR SceneColorQuad = {0, 0, 0, 255};
    //VECTOR SceneScale = {GameState->SceneData.MapAssetOriginAndDim.vz, GameState->SceneData.MapAssetOriginAndDim.pad, 0, 0};
    //DrawDebugQuad(GameState, &SceneTranslation, &SceneColorQuad, &SceneScale);

    VECTOR Translation = {0, 0, 0, 0};
    VECTOR Scale = {ONE, ONE, 0, 0};
    CVECTOR ColorQuad = {255, 0,0,255};
    DrawDebugQuad(GameState, &Translation, &ColorQuad, &Scale);

    //VECTOR TranslationT = {0, 50, 1, 0};
    //VECTOR ScaleT = {ONE, ONE, 0, 0};
    //CVECTOR ColorQuadT = {0, 255, 0,255};
    //DrawDebugQuad(GameState, &TranslationT, &ColorQuadT, &ScaleT);

    //VECTOR translation = {0, 0, 0, 0};
    //DrawAsset(GameState, &translation, &tim_smile);
}