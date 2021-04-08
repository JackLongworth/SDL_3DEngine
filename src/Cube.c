#include <stdlib.h>
#include "Cube.h"
#include "IndexedVertexList.h"

Cube *Cube_Create(float size)
{
    float sideLength = size / 2.0f;
    Cube *cube = (Cube *) malloc(sizeof(Cube));

    IndexedVertexList *ivl = IVL_Create();
    VertexNode *head = ivl->headVertexNode;

    // IVL_AppendVertexf(head, -sideLength, -sideLength, -sideLength);
    // IVL_AppendVertexf(head, sideLength, -sideLength, -sideLength);
    // IVL_AppendVertexf(head, -sideLength, sideLength, -sideLength);
    // IVL_AppendVertexf(head, sideLength, sideLength, -sideLength);
    // IVL_AppendVertexf(head, -sideLength, -sideLength, sideLength);
    // IVL_AppendVertexf(head, sideLength, -sideLength, sideLength);
    // IVL_AppendVertexf(head, -sideLength, sideLength, sideLength);
    // IVL_AppendVertexf(head, sideLength, sideLength, sideLength);
    
    cube->vertexList = ivl;
    return cube;
}

void Cube_GetIndexedVertices(Cube *cube)
{
    IndexNode *head = cube->vertexList->headIndexNode;
    IVL_AppendTriangleIndices(head, 0, 2, 1);
    IVL_AppendTriangleIndices(head, 2, 3, 1);
    IVL_AppendTriangleIndices(head, 1, 3, 5);
    IVL_AppendTriangleIndices(head, 3, 7, 5);
    IVL_AppendTriangleIndices(head, 2, 6, 3);
    IVL_AppendTriangleIndices(head, 3, 6, 7);

    IVL_AppendTriangleIndices(head, 4, 5, 7);
    IVL_AppendTriangleIndices(head, 4, 7, 6);
    IVL_AppendTriangleIndices(head, 0, 4, 2);
    IVL_AppendTriangleIndices(head, 2, 4, 6);
    IVL_AppendTriangleIndices(head, 0, 1, 4);
    IVL_AppendTriangleIndices(head, 1, 5, 4);
}

void Cube_Destroy(Cube *cube)
{
    IVL_Destroy(cube->vertexList);
    free(cube);
}