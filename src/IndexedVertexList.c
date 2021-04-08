#include "IndexedVertexList.h"
#include <stdlib.h>

IndexedVertexList *IVL_Create()
{
   IndexedVertexList *list = (IndexedVertexList *) malloc(sizeof(IndexedVertexList));

   return list; 
}

void IVL_AppendVertex(VertexNode *head, Vec3 *vertex) 
{
    VertexNode *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = (VertexNode *) malloc(sizeof(VertexNode));
    current->next->vertex = vertex;
    current->next->next = NULL;
}

void IVL_AppendVertex(VertexNode *head, float x, float y, float z) 
{
    Vec3 vertex;
    vertex.x = x;
    vertex.y = y;
    vertex.z = z;

    IVL_AppendVertex(head, &vertex);
}

void IVL_AppendIndex(IndexNode *head, int index) 
{
    IndexNode *current = head;
    while (current->next != NULL) 
    {
        current = current->next;
    } 

    current->next = (IndexNode *) malloc(sizeof(IndexNode));
    current->next->index = index;
    current->next->next = NULL;
}

void IVL_AppendTriangleIndices(IndexNode *head, int i0, int i1, int i2) {
    IVL_AppendIndex(head, i0);
    IVL_AppendIndex(head, i1);
    IVL_AppendIndex(head, i2);
}

void IVL_InsertVertexAtStart(VertexNode **head, Vec3 *vertex)
{
    VertexNode *newVertexNode;
    newVertexNode = (VertexNode *) malloc(sizeof(VertexNode));

    newVertexNode->vertex = vertex;
    newVertexNode->next = *head;
    *head = newVertexNode;
}

void IVL_InsertIndexAtStart(IndexNode **head, int index) 
{
    IndexNode *newIndexNode;
    newIndexNode = (IndexNode *) malloc(sizeof(IndexNode));

    newIndexNode->index = index;
    newIndexNode->next = *head;
    *head = newIndexNode;
}

int IVL_PopVertexFromStart(VertexNode **head, Vec3 *vertex)
{
    VertexNode *nextNode = NULL;

    if (*head == NULL) 
    {
        return 0;
    }

    nextNode = (*head)->next;
    vertex = (*head)->vertex;
    free(*head);
    *head = nextNode;

    return 1;
}

int IVL_PopIndexFromStart(IndexNode **head)
{
    int returnIndex = -1;
    IndexNode *nextNode = NULL;

    if (*head == NULL) 
    {
        return returnIndex;
    }

    nextNode = (*head)->next;
    returnIndex = (*head)->index;
    free(*head);
    *head = nextNode;
    
    return returnIndex;
}

int IVL_PopVertexFromEnd(VertexNode *head, Vec3 *vertex)
{
    Vec3 *returnVertex;

    if (head->next == NULL)
    {
        free(head);
        return 0;
    }

    VertexNode *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    returnVertex = current->next->vertex;
    free(current->next);
    current->next = NULL;
    return 1;
}

int IVL_PopIndexFromEnd(IndexNode *head) 
{
    int returnIndex = -1;

    if (head->next == NULL) 
    {
        free(head);
        return returnIndex;
    }

    IndexNode *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    returnIndex = current->next->index;
    free(current->next);
    current->next = NULL;
    return returnIndex;
}

void IVL_Destroy(IndexedVertexList *list) {
    VertexNode *currentVertexNode = list->headVertexNode;
    IndexNode *currentIndexNode = list->headIndexNode;

    while (currentVertexNode != NULL) {

        VertexNode *temp = currentVertexNode;
        currentVertexNode = currentVertexNode->next;
        free(temp);
    }

    while (currentIndexNode != NULL) {

        IndexNode *temp = currentIndexNode;
        currentIndexNode = currentIndexNode->next;
        free(temp);
    }

    free(list);
}
