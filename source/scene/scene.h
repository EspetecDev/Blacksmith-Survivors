#ifndef _DC_SCENEMAP_
#define _DC_SCENEMAP_

#include "dcMath.h"

typedef struct
{
    //  X, y, top corner, z, w, width height
    VECTOR MapCellSizes[25];

} SceneMap;

/* Scena Map Methods  */

void SceneMap_Init(SceneMap * MapPtr);

#endif