#ifndef _GRAPH_MST_
#define _GRAPH_MST_

#include "LinkedGraph.h"

typedef struct GraphEdge
{
    int vertexIDFrom;
    int vertexIDTo;
    int weight;
}GraphEdge;

int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
LinkedGraph *mstPrime(LinkedGraph *pGraph);
GraphEdge getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph* pMST, int mstVertexID);
int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

#endif