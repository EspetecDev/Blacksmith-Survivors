#ifndef _DC_SCENEMAP_
#define _DC_SCENEMAP_

#include "dcMath.h"

typedef struct
{
    //  X, y, top corner, z, w, width height
    VECTOR MapCellSizes[100];
    int GridWidth;
    int GridHeight;
    int TotalCells;

} SceneMap;

/* Scena Map Methods  */

void SceneMap_Init(SceneMap * MapPtr);
int GetGridSize(SceneMap * MapPtr);
VECTOR GetGridCenter(SceneMap * MapPtr, long QuadSize);

#endif