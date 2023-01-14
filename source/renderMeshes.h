#ifndef _DC_RENDER_MESHES_DEMOONE_
#define _DC_RENDER_MESHES_DEMOONE_

#include "render.h"

/* Quad for scene asset */

#define ASSET_SIZE 80
#define ASSET_UV_SIZE 63
static SDC_VertexTextured QuadAssetVertices[] = {
    {{ -ASSET_SIZE / 2, -ASSET_SIZE / 2, 0, 0}, 0, ASSET_UV_SIZE},
    {{ -ASSET_SIZE / 2, ASSET_SIZE / 2, 0, 0}, 0, 0},
    {{ ASSET_SIZE / 2, ASSET_SIZE / 2, 0, 0}, ASSET_UV_SIZE, 0},
    {{ ASSET_SIZE / 2, -ASSET_SIZE / 2, 0, 0}, ASSET_UV_SIZE, ASSET_UV_SIZE}
};
static u_short QuadAssetIndices[] = { 0, 3, 1, 3, 2, 1 };
static SDC_Mesh3D QuadAssetMesh = { QuadAssetVertices, QuadAssetIndices, NULL, 6, 4, POLIGON_VERTEX_TEXTURED };

#endif