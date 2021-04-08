#ifndef CUBE_H
#define CUBE_H


typedef struct Cube {
    struct IndexedVertexList *vertexList;
} Cube;

Cube *Cube_Create(float size);
void Cube_GetIndexedVertices(Cube *cube);
void Cube_Destroy(Cube *cube);

#endif