#ifndef _DC_SCENEMAP_
#define _DC_SCENEMAP_

#include "dcMath.h"
#include "dcSprite.h"

#define SceneTileWidth 20
#define SceneTileHeight 20
#define SceneTileDim 32

typedef struct
{
    VECTOR Coordinates;
    VECTOR TopLeft;
    TIM_IMAGE * Texture;
} Tile;

typedef struct
{
    Tile MapTiles[SceneTileWidth][SceneTileHeight];
    int TotalCells;
} SceneMap;

/* Scena Map Methods  */

void SceneMap_Init(SceneMap * MapPtr);
void SceneMap_Draw(SceneMap * MapPtr, VECTOR * CameraPosition);
VECTOR Scene_GetMapCenter();

int GetGridSize(SceneMap * MapPtr);

#endif