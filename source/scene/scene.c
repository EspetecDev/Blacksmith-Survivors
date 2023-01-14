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
            Data.Texture = &TimTile1;
            MapPtr->MapTiles[i][j] = Data;
        }
    }
}

void SceneMap_Draw(SceneMap * MapPtr)
{
    const DVECTOR UV = {SceneTileDim, SceneTileDim};
    const CVECTOR Color = {255, 255, 255, 255};

    for(int i = 0; i <  SceneTileWidth; i++)
    {
        for(int j = 0; j <  SceneTileHeight; j++)
        {
            Tile * Data = &MapPtr->MapTiles[i][j];
            dcRender_DrawSpriteRect(GEngineInstance.RenderPtr, Data->Texture, Data->TopLeft.vx, Data->TopLeft.vy, SceneTileDim, SceneTileDim, &UV, &Color);
        }
    }
}

int GetGridSize(SceneMap * MapPtr)
{
    return MapPtr->TotalCells;
}