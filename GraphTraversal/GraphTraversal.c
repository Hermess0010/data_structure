#include <stdio.h>
#include <stdlib.h>

#include "GraphLinkedList.h"
#include "LinkedGraph.h"
#include "LinkedStack.h"
#include "GraphTraversal.h"
#include "LinkedQueue.h"

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define VISITED 1
#define NOT_VISITED 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif

//-----------------------------------스택에 노드id값을 푸쉬하는 함수---------------------------------------//
int pushLSForDFS(LinkedStack *pStack, int nodeID){

    StackNode node = {0, };
    node.data = nodeID;

    PushLS(pStack, node);
}

//-----------------------------------그래프 깊이 우선 탐색 함수-------------------------------------------------//
void traversalDFS(LinkedGraph *pGraph, int startVertexID){

    if(pGraph != NULL){

        if(checkVertexValid(pGraph, startVertexID) == SUCCESS){

            LinkedStack *pStack = NULL;
            StackNode *pNode = NULL;
            ListNode *pListNode = NULL;
            int *visit = NULL;

            visit = (int *)malloc(sizeof(int) * pGraph -> maxVertexCount);

            if(visit != NULL){

                memset(visit ,NOT_VISITED, sizeof(int) * pGraph -> maxVertexCount);

                pStack = createLinkedStack();

                pushLSForDFS(pStack, startVertexID);

                while(pStack -> currentElementCount != 0){

                    pNode = PopLS(pStack);
                    printf("방문 - [%d]", pNode -> data);
                    visit[pNode -> data] = VISITED;

                    for(int i = 0; i < getLinkedListLength(pGraph -> ppADJEdge[pNode -> data]); i++){

                        pListNode = getElement(pGraph -> ppADJEdge[pNode -> data], i);

                        if(visit[pListNode -> data.vertexID] == NOT_VISITED){

                            pushLSForDFS(pStack, pListNode);
                        }


                    }
                }

                free(visit);
                DeleteLinkedStack(pStack);
            }
            else{

                printf("오류, 메모리할당\n");
            }
        }
        else{

            printf("오류, 해당 노드[%d]값이 없습니다.\n", startVertexID);
        }
    }
    else{

        printf("오류, 그래프가 유효아지않습니다.\n");
    }
}

//--------------------------------------큐에 노드 id값을 인큐 하는 함수--------------------------------------//
int enqueueLQForBFS(LinkedQueue *pQueue, int nodeID){

    QueueNode node = {0, };

    node.data = nodeID;

    return enqueueLQ(pQueue, node);
}

//---------------------------------------넓이 우선 탐색 함수---------------------------------------------//
void traversalBFS(LinkedGraph *pGraph, int startVertexID){

    if(pGraph != NULL){

        if(checkVertexValid(pGraph, startVertexID) == SUCCESS){

            LinkedQueue *pQueue = NULL;
            QueueNode *pQueueNode = NULL;
            ListNode *pListNode = NULL;
            int *visit = NULL;

            visit = (int)malloc(sizeof(int) * pGraph -> maxVertexCount);

            if(visit != NULL){

                memset(visit, NOT_VISITED, sizeof(int) * pGraph -> maxVertexCount);

                pQueue = createLinkedQueue();

                if(pQueue != NULL){

                    enqueueLQForBFS(pQueue, startVertexID);

                    while(pQueue -> currentElementCount > 0){

                        pQueueNode = dequeueLQ(pQueue);
                    
                        printf("방문 - [%d]", pQueueNode -> data);
                        visit[pQueueNode -> data] = VISITED;

                        for(int i = 0; i < getLinkedListLength(pGraph -> ppADJEdge[pQueueNode -> data]); i++){

                            pListNode = getElement(pGraph -> ppADJEdge[pQueueNode -> data], i);

                            if(visit[pListNode -> data.vertexID] == NOT_VISITED){

                                enqueueLQForBFS(pQueue, pListNode);
                            }
                        }
                    }

                    free(visit);
                    deleteLinkedQueue(pQueue);
                }
                else{

                printf("오류, 메모리할당\n");
                }
            }
            else{

                printf("오류, 메모리할당\n");
            }
        }
        else{

            printf("오류, 해당 노드[%d]값이 없습니다.\n", startVertexID);
        }
    }
    else{

        printf("오류, 그래프가 유효아지않습니다.\n");
    }
}