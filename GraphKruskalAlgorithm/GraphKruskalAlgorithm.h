#ifndef _GRAPH_MST_KRUSKAL_
#define _GRAPH_MST_KRUSKAL_

#include "LinkedGraph.h"
#include "GraphArrayHeap.h"

LinkedGraph* mstKruskal(LinkedGraph *pGraph);
ArrayMinHeap* orderEdge(LinkedGraph *pGraph);
int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

#endif