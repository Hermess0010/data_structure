#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "GraphLinkedList.h"
#include "LinkedGraph.h"

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif

//--------------------------------------그래프 생성함수-----------------------------------------------------//
LinkedGraph* createLinkedGraph(int maxVertexCount){

    if(maxVertexCount > 0){

        LinkedGraph *pGraph = NULL;
        int *pVertex = NULL;
        LinkedList **ppADJEdge = NULL;

        pGraph = (LinkedGraph *)malloc(sizeof(LinkedGraph));

        if(pGraph != NULL){

            pGraph -> maxVertexCount = maxVertexCount;
            pGraph -> currentVertexCount = 0;
            pGraph -> GraphType = GRAPH_UNDIRECTED;
            

            pVertex = (int *)malloc(sizeof(int) * maxVertexCount);

            if(pVertex != NULL){

                memset(pVertex, NOT_USED, sizeof(int) * maxVertexCount);

                pGraph -> pVertex = pVertex;

                ppADJEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);

                if(ppADJEdge != NULL){

                    for(int i = 0; i < maxVertexCount; i++){

                        ppADJEdge[i] = createLinkedList();

                        if(ppADJEdge[i] == NULL){

                            printf("오류, 메모리할당\n");

                            for(int j = 0; j < maxVertexCount; j++){

                                if(ppADJEdge[j] != NULL){

                                    free(ppADJEdge[j]);
                                }
                            }
                            free(pVertex);
                            free(pGraph);
                            return NULL;
                        }
                    }

                    pGraph -> ppADJEdge = ppADJEdge;

                    return pGraph;
                }
                else{

                    printf("오류, 메모리할당\n");
                    free(ppADJEdge);
                    free(pVertex);
                    free(pGraph);
                    return NULL;
                }
            }
            else{

                printf("오류, 메모리할당\n");
                free(pVertex);
                free(pGraph);
                return NULL;
            }
        }
        else{

            printf("오류, 메모리할당\n");
            free(pGraph);
            return NULL;
        }
    }
    else{

        printf("오류, 최대 노드 갯수가 유효하지않습니다.\n");
        return NULL;
    }
}

//----------------------------------------------노드 추가 함수-----------------------------------------------------//
int addVertexLG(LinkedGraph *pGraph, int vertexID){

    int ret = FAIL;

    if(pGraph != NULL){

        if(vertexID >= 0){

            if(pGraph -> pVertex[vertexID] == NOT_USED){

            pGraph -> pVertex[vertexID] = USED;
            pGraph -> currentVertexCount++;

            ret = SUCCESS;
            }
            else{

                printf("오류, 노드 ID[%d]\n", pGraph -> pVertex[vertexID]);
            }
        }
        else{

            printf("오류, 노드 최대값 [%d]\n", vertexID);
        }
    }
    else{

        printf("오류, 유효하지않은 그래프\n");
    }

    return ret;
}

//-------------------------------------간선 추가 함수-----------------------------------------------------------//
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID){

    return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList *pList, int position, GraphVertex vertex){

    ListNode pNode ={0, };

    pNode.data = vertex;
    return addLLElement(pList, position, pNode);
}

int addEdgewithWeightLG(LinkedGraph *pGrapg, int fromVertexID, int toVertexID, int weight){

    int ret = FAIL;

    if(pGrapg != NULL){

        if(checkVertexValid(pGrapg, fromVertexID) == SUCCESS){

            if(checkVertexValid(pGrapg, toVertexID) == SUCCESS){

                GraphVertex vertex = {0, }, reverseVertex = {0, };

                vertex.vertexID = toVertexID;
                vertex.weight = weight;

                addLLElementForVertex(pGrapg -> ppADJEdge[fromVertexID], 0, vertex);

                if(pGrapg -> GraphType == GRAPH_UNDIRECTED){

                    reverseVertex.vertexID = fromVertexID;
                    reverseVertex.weight = weight;

                    addLLElementForVertex(pGrapg ->ppADJEdge[toVertexID], 0, reverseVertex);
                }

                ret = SUCCESS;

            }
            else{

                printf("오류, 종료노드가 유효하지않습니다 [%d]\n", toVertexID);
            }
        }
        else{

            printf("오류, 종료노드가 유효하지않습니다 [%d]\n", fromVertexID);
        }
    }
    else{

        printf("오류, 그래프가 유효하지않습니다\n");
    }

    return ret;
}

//-------------------------------------노드가 유효한지 확인하는 함수---------------------------------------------//
int checkVertexValid(LinkedGraph *pGraph, int vertexID){

    int ret = FAIL;

    if(pGraph != NULL){

        if(vertexID >= 0 && vertexID < pGraph -> maxVertexCount){

            if(pGraph -> pVertex[vertexID] == USED){

                ret = SUCCESS;
            }
        }
    }

    return ret;
}

//-----------------------------------그래프 리스트 노드 제거함수------------------------------------------------------------//
void deleteGraphNode(LinkedList *pList, int delVertexID){

    if(pList != NULL){

        for(int i = 0; i < getLinkedListLength(pList); i++){

            if(getLLElement(pList, i) -> data.vertexID == delVertexID){

                removeLLElement(pList, i);
            }
        }
    }
}

//--------------------------------------간선 제거 함수--------------------------------------------------//
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID){

    int ret = FAIL;

    if(pGraph != NULL){

        deleteGraphNode(pGraph -> ppADJEdge[fromVertexID], toVertexID);

        if(pGraph -> GraphType == GRAPH_UNDIRECTED){

            deleteGraphNode(pGraph -> ppADJEdge[toVertexID], fromVertexID);
        }

        ret= SUCCESS;
    }

    return ret;
}

//------------------------------------------그래프 노드 제거 함수-----------------------------------/
int removeVertexLG(LinkedGraph *pGraph, int vertexID){

    int ret = FAIL;

    if(pGraph != NULL){

        pGraph -> pVertex[vertexID] = NOT_USED;

        clearLinkedList(pGraph -> ppADJEdge[vertexID]);

        for(int i = 0; i < pGraph -> maxVertexCount; i++){

            deleteGraphNode(pGraph -> ppADJEdge[i], vertexID);
        }

        ret = SUCCESS;
    }

    return ret;
}

