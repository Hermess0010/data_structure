#include <stdio.h>
#include <stdlib.h>

#include "GraphLinkedList.h"
#include "GraphPrimeAlgorithm.h"
#include "LinkedGraph.h"
#include "LinkedStack.h"

#define TRUE 1
#define FALSE 0

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0


//--------------------------------------그래프에 순환이 있는지 없는지 확인 하는 함수---------------------------------//
int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID){

    int check = FALSE;

    if(pGraph != NULL){

        ListNode *Node = NULL;

        for(int i = 0; i < pGraph -> currentVertexCount; i++){

            for(int j = 0; j > pGraph -> ppADJEdge[i] -> currentElementCount; j++){

                Node = getLLElement(pGraph -> ppADJEdge[i], j);

                if(Node -> data.vertexID == toVertexID){

                    return check;
                }
            }
        }

        return check;
    }
    else{

        printf("오류, 그래프가 유효하지않습니다.\n");
        return check;

    }
}

//------------------------------------특정 간선이 있는지 없는지 확인하는 함수--------------------------------//
int checkEdge(LinkedGraph *pGraph, int fromVertexID, int toVertexID){

    int ret = FAIL;
    if(pGraph != NULL){

        if(pGraph -> pVertex[fromVertexID] == USED){

            if(pGraph -> pVertex[toVertexID] == USED){

                if(findGraphNodePosition(pGraph -> ppADJEdge[fromVertexID], toVertexID) != -1){

                    ret = SUCCESS;
                    return ret;
                }
            }
        }
    }

    return ret;
}

//------------------------------------간선을 선택하는 함수---------------------------------------------------//
GraphEdge getMinWeightEdge(LinkedGraph *pGraph, LinkedGraph* pMST, int mstVertexID){

    GraphEdge Edge = {-1, mstVertexID, 999 };

    if(pGraph != NULL){

        if(pMST != NULL){

            int position = -1;

            for(int i = 0; i < pGraph -> maxVertexCount; i++){

                if(checkEdge(pGraph, pGraph -> ppADJEdge[i], mstVertexID) != -1){

                    position = findGraphNodePosition(pGraph -> ppADJEdge[i], mstVertexID);

                    if(getLLElement(pGraph -> ppADJEdge[i], position) -> data.weight < Edge.weight){

                        Edge.vertexIDFrom = i;
                        Edge.weight = getLLElement(pGraph -> ppADJEdge[i], position) -> data.weight;
                    }
                }
            }

            return Edge;
        }
        else{

            printf("오류, 그래프오류\n");
            return Edge;
        }
    }
    else{

        printf("오류, 그래프오류\n");
        return Edge;
    }
}

//------------------------------------prim알고리즘-------------------------------------------------------//
LinkedGraph* mstPrime(LinkedGraph *pGraph){

    if(pGraph != NULL){

        LinkedGraph *pMST = NULL;
        GraphEdge Edge = {0, };

        pMST = createLinkedGraph(pGraph -> maxVertexCount);

        if(pMST != NULL){

            int maxKey = -1;                   //key 값인데 최소비용신장트리가 사용하는것중 가장 큰 key값
            int unKey = -1;                     //key값인데 최소비용신장트리가 사용하지않는 키값
            ListNode *pListNode = NULL;

            unKey = searchUnKey(pGraph, pMST);
            while(pGraph -> currentVertexCount != pMST -> currentVertexCount){

                if(unKey != -1){

                    Edge = getMinWeightEdge(pGraph, pMST, unKey);

                    addEdgewithWeightLG(pMST, Edge.vertexIDFrom, Edge.vertexIDTo, Edge.weight);

                    unKey = searchUnKey(pGraph, pMST);
                }
                else{

                    for(int i = 0; i < pGraph -> maxVertexCount; i++){

                        if(pGraph -> pVertex[i] == USED){

                            if(pMST -> pVertex[i] == NOT_USED){

                                unKey = i;
                            }
                        }
                    }
                }
            }

            return pMST;
            
        }   
    }
}

//---------------------------------------사용하지않는 키 찾는 함수-----------------------------------//
int searchUnKey(LinkedGraph *pGraph, LinkedGraph *pMST){

    int maxKey = -1;
    int unKey = -1;
    ListNode *pListNode = NULL;

    for(int i = 0; i < pMST -> maxVertexCount; i++){

        if(pMST -> pVertex[i] == USED){

            maxKey = pMST -> pVertex[i];
        }
            }

    for(int i = 0; i < pGraph -> ppADJEdge[maxKey] -> currentElementCount; i++){

        pListNode = getLLElement(pGraph -> ppADJEdge[maxKey], i);

        if(pMST -> pVertex[pListNode -> data.vertexID] == NOT_USED &&
            checkEdge(pGraph, maxKey, pListNode != -1)){

                unKey = i;
                return unKey;
        }

        unKey = -1;
        return unKey;
    }
}