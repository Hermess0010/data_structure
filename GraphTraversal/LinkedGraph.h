#ifndef _GRAPH_ADJLIST_
#define _GRAPH_ADJLIST_
#include "GraphLinkedList.h"

typedef struct LinkedGraph{

    int maxVertexCount;
    int currentVertexCount;
    int GraphType;
    LinkedList **ppADJEdge;
    int *pVertex;
}LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);
void deleteLinkedGraph(LinkedGraph *pGraph);
int isEmptyLG(LinkedGraph *pGraph);
int addVertexLG(LinkedGraph *pGraph, int vertexID);
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexId, int toVertexID, int weight);
int checkVertexValid(LinkedGraph *pGraph, int vertexID);
int removeVertexLG(LinkedGraph *pGraph, int vertexID);
int reMoveEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
void deleteGraphNode(LinkedList *pList, int delVertexID);
int findGraphNodePosition(LinkedList *pList, int vertexID);
void displayLinkedGraph(LinkedGraph *pGraph);

#endif