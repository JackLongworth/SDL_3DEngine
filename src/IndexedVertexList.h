#ifndef INDEXED_TRIANGLE_LIST_H
#define INDEXED_TRIANGLE_LIST_H

#include "Vec3.h"

typedef struct VertexNode
{
    Vec3 *vertex;
    struct VertexNode *next;
} VertexNode;

typedef struct IndexNode
{
    int index;
    struct IndexNode *next;
} IndexNode;

typedef struct IndexedVertexList
{
    VertexNode *headVertexNode;
    IndexNode *headIndexNode;

} IndexedVertexList;

IndexedVertexList *IVL_Create();
void IVL_AppendVertex(VertexNode *head, Vec3 *vertex);
void IVL_AppendVertexf(VertexNode *head, float x, float y, float z);
void IVL_AppendIndex(IndexNode *head, int index);
void IVL_AppendTriangleIndices(IndexNode *head, int i0, int i1, int i2);
void IVL_InsertVertexAtStart(VertexNode **head, Vec3 *vertex);
void IVL_InsertIndexAtStart(IndexNode **head, int index);
int IVL_PopVertexFromStart(VertexNode **head, Vec3 *vertex);
int IVL_PopIndexFromStart(IndexNode **head);
int IVL_PopVertexFromEnd(VertexNode *head, Vec3 *vertex);
int IVL_PopIndexFromEnd(IndexNode *head);
void IVL_Destroy(IndexedVertexList *list);

#endif