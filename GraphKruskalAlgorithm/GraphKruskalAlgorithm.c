#include <stdio.h>
#include <stdlib.h>

#include "GraphArrayHeap.h"
#include "GraphLinkedList.h"
#include "GraphKruskalAlgorithm.h"
#include "LinkedGraph.h"
#include "LinkedStack.h"

#define TRUE 1
#define FALSE 0

#define USED 1
#define NOT_USED 0

//--------------------------------------------최소 히프에 그래프의 간선의 키값들을 넣는 함수-------------------------------//
ArrayMinHeap* orderEdge(LinkedGraph *pGraph){

    if(pGraph != NULL){

        ArrayMinHeap *pMinHeap = NULL;
        HeapNode Node = {0, };


        pMinHeap = createArrayMinHeap(pGraph -> maxVertexCount);

        if(pMinHeap != NULL){

            for(int i = 0; i < pGraph -> currentVertexCount; i++){

                for(int j = 0; j < pGraph -> ppADJEdge[i] -> currentElementCount; j++){

                    Node.key = getLLElement(pGraph -> ppADJEdge[i], j) -> data.weight;
                    Node.fromVertexID = i;
                    Node.toVertexID = getLLElement(pGraph -> ppADJEdge[i], j) -> data.vertexID;
                }
            }
        }
    }
}

//--------------------------------------------그래프에 순환이 있는지 체크하는 함수---------------------------------------//
int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID){

    int check = FALSE;

    if(pGraph != NULL){

        ListNode *Node = NULL;

        for(int i = 0; i < pGraph -> currentVertexCount; i++){

            for(int j = 0; j > pGraph -> ppADJEdge[i] -> currentElementCount; j++){

                Node = getLLElement(pGraph -> ppADJEdge[i], j);

                if(Node -> data.vertexID == toVertexID){

                    for(int i = 0; i < pGraph -> ppADJEdge[toVertexID] ->currentElementCount; i++){

                        Node = getLLElement(pGraph -> ppADJEdge[toVertexID], i);

                        if(Node -> data.vertexID == fromVertexID){

                            check = FALSE;

                            return check;
                        }
                    }

                    check = TRUE;

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

//------------------------------------KRUSKAL 알고리즘--------------------------------------------------------//
LinkedGraph* mstKruskal(LinkedGraph *pGraph){

    if(pGraph != NULL){

        ArrayMinHeap *pMinHeap = NULL;
        LinkedGraph *pMCST = NULL;
        HeapNode *pHeapNode = NULL;

        pMinHeap = orderEdge(pGraph);

        pMCST = createLinkedGraph(pGraph -> maxVertexCount);

        if(pMCST != NULL){

            for(int i = 0; i < pGraph -> maxVertexCount; i++){                      //최소신장트리에 모든 노드 추가

                if(pGraph -> pVertex[i] == USED){

                    addVertexLG(pMCST, i);
                }
            }   

            while(pMinHeap -> currentElementCount > 0){                         //최소신장트리에 최소 간선만 추가

                pHeapNode = delteMinHeapAH(pMinHeap);

                if(checkCycle(pMCST, pHeapNode -> fromVertexID, pHeapNode -> toVertexID) == FALSE){      //순환인지 확인

                    addEdgewithWeightLG(pMCST, pHeapNode -> fromVertexID, pHeapNode -> toVertexID, pHeapNode -> key);
                }
            }
        }
    }
}

