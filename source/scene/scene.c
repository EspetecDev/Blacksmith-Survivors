#include "scene.h"

//#define MAXVIEWPORTSIZEUNITS ONE * 7

void SceneMap_Init(SceneMap* MapPtr)
{
    //  Constants scene.
    MapPtr->TotalCells = 100;
    MapPtr->GridWidth = SquareRoot0(MapPtr->TotalCells);
    MapPtr->GridHeight = SquareRoot0(MapPtr->TotalCells);

    //int SceneCellSize = ONE;
    int AccumulatedWidth = 0;
    int AccumulatedHeight = 0;

    for(int Index = 0; Index < MapPtr->TotalCells; Index++)
    {
        VECTOR MapOrigin;
        MapOrigin.vx = AccumulatedWidth;
        MapOrigin.vy = AccumulatedHeight;
        AccumulatedWidth +=  1;
        
        if (AccumulatedWidth >= MapPtr->GridWidth)
        {
            AccumulatedWidth = 0;
            AccumulatedHeight += 1;
        }

        MapPtr->MapCellSizes[Index] = MapOrigin;
    }


    //VECTOR Origin = {0, 0, ONE * 4, ONE * 4};
    //MapPtr->MapAssetOriginAndDim = Origin;
}

int GetGridSize(SceneMap * MapPtr)
{
    return MapPtr->TotalCells;
}

VECTOR GetGridCenter(SceneMap * MapPtr, long QuadSize)
{
    long TotalWidth = MapPtr->GridWidth * QuadSize;
    long TotalHeight = MapPtr->GridHeight * QuadSize;

    VECTOR GridCenter = {TotalWidth / 2, TotalHeight / 2};
    return GridCenter;
}