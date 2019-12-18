#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinTreeLinkedQueue.h"

#define TRUE 1
#define FALSE 0

//-------------------------------------------연결 큐 만드는 함수-------------------------------------------//
LinkedQueue* createLinkedQueue(){

    LinkedQueue* pQueue = NULL;

    pQueue = (LinkedQueue *)malloc(sizeof(LinkedQueue));

    if(pQueue != NULL){

        memset(pQueue, 0, sizeof(LinkedQueue));
        
        return pQueue;
    }
    else{

        printf("오류, 메모리할당\n");
        return NULL;
    }


}

//-------------------------------------------인큐 연산 함수-------------------------------------------------//
int enqueueLQ(LinkedQueue *pQueue, QueueNode element){

    int ret = FALSE;

    if(pQueue != NULL){

        QueueNode *pNode = NULL;

        pNode = (QueueNode *)malloc(sizeof(QueueNode));

        if(pNode != NULL){

            memset(pNode, 0 , sizeof(QueueNode));
            pNode -> data = element.data;

            if(isLinkedQueueEmpty(pQueue) == TRUE){

                pQueue -> pFrontNode = pNode;
                pQueue -> pRearNode = pNode;

                pQueue -> currentElementCount++;

                ret = TRUE;

                return ret;
            }
            else{

                pQueue -> pRearNode -> pLink = pNode;
                pQueue -> pRearNode = pNode;

                pQueue -> currentElementCount++;

                ret = TRUE;

                return ret;
            }
        }
        else{

            printf("오류, 메모리할당\n");
            return ret;
        }
    }
    else{

        printf("오류, 유효하지않은 큐\n");
        return ret;
    }
}

//---------------------------------------디큐 연산 함수---------------------------------------------------//
QueueNode* dequeueLQ(LinkedQueue *pQueue){

    if(pQueue != NULL){

        if(isLinkedQueueEmpty(pQueue) == FALSE){

            QueueNode *pNode = NULL;

            pNode = pQueue -> pFrontNode;
            pQueue -> pFrontNode = pQueue -> pFrontNode -> pLink;
            pNode -> pLink = NULL;
        
            pQueue -> currentElementCount--;

            if(isLinkedQueueEmpty == TRUE){

                pQueue -> pRearNode = NULL;
            }

            return pNode;
        }
        else{

            printf("오류, 큐가 비어있습니다.\n");
            return NULL;
        }
    }
    else{

        printf("오류, 유효하지않은 큐");
    }
}

//-----------------------------------피크 연산 함수------------------------------------------//
QueueNode *peekLQ(LinkedQueue *pQueue)
{

    if (pQueue != NULL)
    {

        if (isLinkedQueueEmpty(pQueue) == FALSE)
        {

            QueueNode *pNode = NULL;

            pNode = pQueue->pFrontNode;

            return pNode;
        }
        else
        {

            printf("오류, 큐가 비어있습니다\n");
            return NULL;
        }
    }
    else{

        printf("오류, 유효하지않은 큐\n");
        return NULL;
    }
}

//-----------------------------------------연결 큐 삭제 함수-------------------------------------------//
void deleteLinkedQueue(LinkedQueue *pQueue){

    if(pQueue != NULL){

        if(isLinkedQueueEmpty(pQueue) == FALSE){

            QueueNode *pDelNode = NULL;

            while(isLinkedQueueEmpty(pQueue) == TRUE){

                pDelNode = dequeueLQ(pQueue);
                free(pDelNode);
            }
        }

        free(pQueue);
    }
}

//-------------------------------------------큐가 가득 찼는지 확인하는 함수----------------------------//
int isLinkedQueueFull(LinkedQueue *pQueue){

    int ret = FALSE;

    return ret;
}

//------------------------------------------큐가 비었는지 확인하는 함수--------------------------------//
int isLinkedQueueEmpty(LinkedQueue *pQueue){

    int ret = FALSE;

    if(pQueue != NULL){

        if(pQueue -> currentElementCount == 0){

            ret = TRUE;
        }

        return ret;
    }
}

//------------------------------------------큐를 출력해주는 함수----------------------------------------//
void displayLinkedQueue(LinkedQueue *pQueue){

    if(pQueue != NULL){

        int i = 1;

        QueueNode *pNode = NULL;

        pNode = pQueue -> pFrontNode;
        printf("현재 노드 개수 [%d]", pQueue -> currentElementCount);

        while(pNode != NULL){

            printf("[%d] - [%c]", i, pNode -> data);
            i++;
            pNode = pNode -> pLink;
        }
    }
}