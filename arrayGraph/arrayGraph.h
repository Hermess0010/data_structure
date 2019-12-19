#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraph{

    int maxVertexCount;         //최대노드개수
    int currentVertexCount;     //현재 사용되는 노드 개수
    int graphType;              //그래프의 종류 1-undirected, 2-directed
    int **ppAdjEdge;            //간선 저장을 위한 2차원 array
    int *pVertex;               //노드 저장을 위한 1차원 array
}ArrayGraph;

ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);
void deleteArrayGraph(ArrayGraph *pGraph);
int isEmptyAG(ArrayGraph *pGraph);
int addVertexAG(ArrayGraph *pGraph, int VertexID);
int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVerTexID, int weight);
int removeVertexAG(ArrayGraph *pGraph, int vertexID);
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);
void displayArrayGraph(ArrayGraph *pGraph);
int checkVertexValid(ArrayGraph *pGraph, int vertexID);

#endif