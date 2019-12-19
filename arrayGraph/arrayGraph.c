#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayGraph.h"

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

//------------------------------------배열 그래프 생성 함수------------------------------------------------//
ArrayGraph* createArrayGraph(int maxVertexCount){

    if(maxVertexCount > 0){

        ArrayGraph *pGraph = NULL;

        pGraph = (ArrayGraph *)malloc(sizeof(ArrayGraph));

        if(pGraph != NULL){

            pGraph -> maxVertexCount = maxVertexCount;
            pGraph -> currentVertexCount = 0;
            pGraph -> graphType = 1;
            pGraph -> ppAdjEdge = NULL;
            pGraph -> pVertex = NULL;

            int *pVertex = NULL;

            pVertex = (int *)malloc(sizeof(int) * maxVertexCount);

            if(pVertex != NULL){

                memset(pVertex, NOT_USED, sizeof(int) * maxVertexCount);

                pGraph -> pVertex = pVertex;

                int **ppAdjEdge = NULL;

                ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);

                if(ppAdjEdge != NULL){

                    for(int i = 0; i < maxVertexCount; i++){

                        ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);

                        if(ppAdjEdge[i] == NULL){
                            
                            printf("오류, 메모리할당\n");
                            
                            for(int j = 0; j < maxVertexCount; j++){

                                if(ppAdjEdge[j] != NULL){

                                    free(ppAdjEdge[j]);
                                }
                            }

                            free(pVertex);
                            free(pGraph);

                            return NULL;
                        }


                        memset(pVertex[i], 0, sizeof(int) * maxVertexCount);
                    }

                    pGraph -> ppAdjEdge = ppAdjEdge;
                    
                    return pGraph;

                }
                else{

                    printf("오류, 메모리할당\n");
                    free(pGraph);
                    free(ppAdjEdge);
                    free(pVertex);

                    return NULL;
                }
            }
            else{

                    printf("오류, 메모리할당\n");
                    free(pGraph);
                    free(pVertex);

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

        printf("오류,최대 노드값이 유효하지않습니다.\n");

        return NULL;
    }
}

//-----------------------------------------------노드 추가 함수--------------------------------------------------//
int addVertexAG(ArrayGraph *pGraph, int vertexID){

    int ret =FALSE;

    if(pGraph != NULL){

        if(0 <= vertexID && vertexID < pGraph -> maxVertexCount){

            if(pGraph -> pVertex[vertexID] != NOT_USED){

                pGraph -> pVertex[vertexID] = USED;
                pGraph -> currentVertexCount++;

                ret =TRUE;
                
            }
            else{

                printf("오류, 이미존재하는 노드\n");

            }

        }
        else{

            printf("오류, 유효하지않은 노드 id값\n");
        }
    }
    else{

        printf("오류, 유효하지않은 그래프");
    }

    return ret;
}

//--------------------------------------가중치 그래프 간선 추가 함수----------------------------------------------//
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight){

    int ret = FAIL;

    if(pGraph != NULL){

        if(checkVertexValid(pGraph, fromVertexID) == SUCCESS){

            if(checkVertexValid(pGraph, toVertexID) == SUCCESS){

                if(weight >= 0){

                    pGraph -> ppAdjEdge[fromVertexID][toVertexID] = weight;

                    if(pGraph -> graphType == GRAPH_UNDIRECTED){

                        pGraph -> ppAdjEdge[toVertexID][fromVertexID] = weight;
                    }

                    ret = SUCCESS;
                }
            }
        }
    }
    return ret;
}

//--------------------------------------------유효 노드인지 확인하는 함수---------------------------------------//
int checkVertexValid(ArrayGraph *pGraph, int vertexID){

    int ret = FAIL;

    if(pGraph == NULL){

        return ret;
    }

    if(pGraph -> pVertex[vertexID] == USED && vertexID < pGraph -> maxVertexCount){

        ret = SUCCESS;
    }
    else{

        printf("오류노드 정보 -[%d]\n", vertexID);
    }

    return ret;
}

//----------------------------------------무가중치 그래프 간선 추가 함수-----------------------------------//
int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID){

    return addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

//-----------------------------------------노드와 간선 제거 함수-----------------------------------------------//
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID){

    int ret = FAIL;

    if(checkVertexValid(pGraph, fromVertexID) == SUCCESS){

        if(checkVertexValid(pGraph, toVertexID) == SUCCESS){

            pGraph -> ppAdjEdge[fromVertexID][toVertexID] = 0;

            if(pGraph -> graphType == GRAPH_UNDIRECTED){

                pGraph -> ppAdjEdge[toVertexID][fromVertexID] = 0;
            }

            ret = SUCCESS;
        }
    }

    return ret;
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID){

    int ret = FAIL;

    if(checkVertexValid(pGraph, vertexID) == SUCCESS){

        for(int i = 0; i < pGraph -> maxVertexCount; i++){

            removeEdgeAG(pGraph, vertexID, i);
            removeEdgeAG(pGraph, i, vertexID);
        }

        pGraph -> pVertex[vertexID] = NOT_USED;

        ret = SUCCESS;
    }

    return ret;
}

//--------------------------------현재 내용을 출력하는 함수-------------------------------------------//
void displayArrayGraph(ArrayGraph *pGraph){

    if(pGraph != NULL){

        printf("현재 노드 상태: \n");

        for(int i = 0; i < pGraph -> maxVertexCount; i++){

            printf("ID : %d , USED : %d\n", i, pGraph -> pVertex[i]);
        }

        printf("현재 간선 상태\n");

        for(int i = 0; i < pGraph -> maxVertexCount; i++){

            if(pGraph -> graphType == GRAPH_DIRECTED){

                for(int j = 0; j < pGraph -> maxVertexCount; j++){

                    printf("<%d, %d>\n",pGraph -> ppAdjEdge[i][j]);
                }
            }
            else{

                for(int j = 0; j <= i; j++){

                    printf("(%d, %d)\n", pGraph -> ppAdjEdge[i][j]);
                }
            }
        }
    }
}

//---------------------------------------그래프를 삭제하는 함수-----------------------------------------------//
void deleteArrayGraph(ArrayGraph *pGraph){

    if (pGraph != NULL){

        for (int j = 0; j < pGraph -> maxVertexCount; j++){

            if (pGraph -> ppAdjEdge[j] != NULL){

                free(pGraph -> ppAdjEdge[j]);
            }
        }

        free(pGraph -> ppAdjEdge);
        free(pGraph -> pVertex);
        free(pGraph);
    }
}

//---------------------------------------공백 그래프인지 확인하는 함수--------------------------------------//
int isEmptyAG(ArrayGraph *pGraph){

    int ret = TRUE;

    for(int i = 0; i < pGraph -> maxVertexCount; i++){

        for(int j = 0; j < pGraph ->maxVertexCount; j++){

            if(pGraph -> ppAdjEdge[i][j] == USED){

                ret = FALSE;
            }
        }
    }

    return ret;
}