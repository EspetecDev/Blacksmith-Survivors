#include "scene.h"
#include "../engine.h"

void SceneMap_Init(SceneMap* MapPtr)
{
    //  Constants scene.
    MapPtr->TotalCells = SceneTileWidth * SceneTileHeight;

    for(int i = 0; i <  SceneTileWidth; i++)
    {
        for(int j = 0; j <  SceneTileHeight; j++)
        {
            // // int RandTile = 0
            // // if(rand() % 75 != 0)
            // int TileType = 0;
            Tile Data;
            Data.Coordinates.vx = i;
            Data.Coordinates.vy = j;
            Data.TopLeft.vx = i * SceneTileDim;
            Data.TopLeft.vy = j * SceneTileDim;

            int randChoose = rand() % 5;
            printf("tile[%d][%d] - type: %d", i, j, randChoose);
            switch (randChoose)
            {
                case 0:
                Data.RealImage = TimTile1;
                break;
                case 1:
                Data.RealImage = TimTile2;
                break;
                case 2:
                Data.RealImage = TimTile3;
                break;
                case 3:
                Data.RealImage = TimTile4;
                break;
                case 4:
                Data.RealImage = TimTile5;
                break;
                case 5:
                Data.RealImage = TimTile6;
                break;
            
            default:
                break;
            }
            MapPtr->MapTiles[i][j] = Data;
        }
    }
}

void SceneMap_Draw(SceneMap * MapPtr, VECTOR * CameraPosition)
{
    const DVECTOR UV = {0, 0};
    const CVECTOR Color = {128, 128, 128};

    for(int i = 0; i <  SceneTileWidth; i++)
    {
        for(int j = 0; j <  SceneTileHeight; j++)
        {

            Tile * Data = &MapPtr->MapTiles[i][j];
            int TopLeftX = Data->TopLeft.vx - CameraPosition->vx;
            int TopLefty = Data->TopLeft.vy - CameraPosition->vy;
            if(abs(TopLeftX) < RENDER_WIDTH && abs(TopLefty) < RENDER_HEIGHT)
            {
                dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &Data->RealImage, TopLeftX, TopLefty, SceneTileDim, SceneTileDim, &UV, &Color);
            }
        }
    }
    // Tile * Data = &MapPtr->MapTiles[0][0];
    // Tile * Data2 = &MapPtr->MapTiles[1][1];
    // Tile * Data3 = &MapPtr->MapTiles[2][2];
    // int TopLeftX = Data->TopLeft.vx - CameraPosition->vx;
    // int TopLefty = Data->TopLeft.vy - CameraPosition->vy;
    // dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTile2, TopLeftX, TopLefty, SceneTileDim, SceneTileDim, &UV, &Color);
    // TopLeftX = Data2->TopLeft.vx - CameraPosition->vx;
    // TopLefty = Data2->TopLeft.vy - CameraPosition->vy;
    // dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTile3, TopLeftX, TopLefty, SceneTileDim, SceneTileDim, &UV, &Color);
    // TopLeftX = Data3->TopLeft.vx - CameraPosition->vx;
    // TopLefty = Data3->TopLeft.vy - CameraPosition->vy;
    // dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, &TimTile4, TopLeftX, TopLefty, SceneTileDim, SceneTileDim, &UV, &Color);
}

VECTOR GetRandomLocation(SceneMap * MapPtr)
{
    int i = rand() % SceneTileWidth;
    int j = rand() % SceneTileHeight;

    return MapPtr->MapTiles[i][j].TopLeft;
}

VECTOR Scene_GetMapCenter()
{
    VECTOR Result = { (SceneTileWidth * SceneTileDim)/2, (SceneTileWidth * SceneTileDim)/2, 0, 0};
    return Result;
}

int GetGridSize(SceneMap * MapPtr)
{
    return MapPtr->TotalCells;
}