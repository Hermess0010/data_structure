#ifndef _GRAPH_TRAVERSAL_
#define _GRAPH_TRAVERSAL_

#include "GraphLinkedList.h"
#include "LinkedGraph.h"

void traversalDFS(LinkedGraph *pGraph, int startVertexID);
void traversalBFS(LinkedGraph *pGraph, int startVertexID);

#endif