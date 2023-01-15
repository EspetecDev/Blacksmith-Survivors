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
            Tile Data;
            Data.Coordinates.vx = i;
            Data.Coordinates.vy = j;
            Data.TopLeft.vx = i * SceneTileDim;
            Data.TopLeft.vy = j * SceneTileDim;

            int randChoose = rand() % 1000;
            if(randChoose > 0 && randChoose < 900 )
            {
                randChoose = rand() % 100;
                if(randChoose >= 0 && randChoose < 25)
                    Data.RealImage = TimTile1;
                else if(randChoose >= 25 && randChoose < 50)
                    Data.RealImage = TimTile3;
                else if(randChoose >= 50 && randChoose < 75)
                    Data.RealImage = TimTile4;
                else if(randChoose >= 75 && randChoose <= 100)
                    Data.RealImage = TimTile5;
            }
            else
            {
                if(rand() % 2 == 0)
                    Data.RealImage = TimTile2;
                else
                    Data.RealImage = TimTile6;
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

char Scene_IsInsidedBounds(VECTOR * PointToCheck)
{
    return (PointToCheck->vx > 0) && (PointToCheck->vx < (SceneTileWidth * SceneTileDim - 32)) && (PointToCheck->vy > -SceneTileDim) && (PointToCheck->vy < (SceneTileHeight * SceneTileDim - SceneTileDim));
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