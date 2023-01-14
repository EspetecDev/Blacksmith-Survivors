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
            Data.Texture = &TimTile2;
            MapPtr->MapTiles[i][j] = Data;
        }
    }
}

void SceneMap_Draw(SceneMap * MapPtr, VECTOR * CameraPosition)
{
    const DVECTOR UV = {SceneTileDim, SceneTileDim};
    const CVECTOR Color = {255, 255, 255, 255};
    
    for(int i = 0; i <  SceneTileWidth; i++)
    {
        for(int j = 0; j <  SceneTileHeight; j++)
        {

            Tile * Data = &MapPtr->MapTiles[i][j];
            int TopLeftX = Data->TopLeft.vx - CameraPosition->vx;
            int TopLefty = Data->TopLeft.vy + CameraPosition->vy;
            if(abs(TopLeftX) < RENDER_WIDTH && abs(TopLefty) < RENDER_HEIGHT)
            {
                dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, Data->Texture, TopLeftX, TopLefty, SceneTileDim, SceneTileDim, &UV, &Color);
            }
        }
    }
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