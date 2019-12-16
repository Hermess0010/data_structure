#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayQueue.h"

#define TRUE 1
#define FALSE 0

//-------------------------------------------배열 큐 만드는 함수---------------------------------------//
ArrayQueue* createArrayQueue(int maxElementCount){

    if(maxElementCount > 0){

        ArrayQueue *pQueue = NULL;

        pQueue = (ArrayQueue*)malloc(sizeof(ArrayQueue));

        if(pQueue != NULL){

            memset(pQueue, 0, sizeof(ArrayQueue));

            pQueue -> maxElementCount = maxElementCount;
            pQueue -> front = -1;
            pQueue -> rear = -1;

            pQueue -> pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);

            if(pQueue -> pElement != NULL){

                memset(pQueue -> pElement, 0, sizeof(ArrayQueueNode) * maxElementCount);

                return pQueue;
            }
            else{

                printf("오류, 메모리할당\n");
                free(pQueue);

                return NULL;
            }

        }
        else{

                printf("오류, 메모리할당\n");
                free(pQueue);

                return NULL;
            }
    }
    else{

                printf("오류, 큐 크기는 0보다 커야합니다.\n");

                return NULL;
            }
}

//------------------------------------------인큐 연산 함수---------------------------------------------------//
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element){

    int ret = FALSE;

    if(pQueue != NULL){

        if(isArrayQueueFull(pQueue) == FALSE){

            pQueue -> rear++;
            pQueue -> pElement[pQueue -> rear] = element;

            pQueue -> currentElementCount++;

            ret = TRUE;

            return ret;
        }
        else{

            printf("오류, 큐가 가득 찼습니다.\n");
            return ret;
        }
    }
    else{

        printf("오류, 유효하지않은 큐입니다.\n");
        return ret;
    }
}

//-----------------------------------------디큐 연산 함수----------------------------------------------------//
//반환된 메모리주소는 쓴다음에 해제시켜주어야한다.
ArrayQueueNode* dequeueAQ(ArrayQueue *pQueue){

    if(pQueue != NULL){

        if(isArrayQueueEmpty(pQueue) == FALSE){

            ArrayQueueNode *pNode = NULL;

            pNode = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));

            if(pNode != NULL){

                pQueue -> front++;
                pNode -> element = pQueue -> pElement[pQueue -> front].element;
                
                pQueue -> currentElementCount--;

                return pNode;

            }
            else{

                printf("오류, 메모리할당\n");
                free(pNode);

                return NULL;
            }

        }
        else{

                printf("오류, 큐가 비어있습니다\n");
                return NULL;
            }
    }
    else{

        printf("오류, 메모리할당\n");
        return NULL;
    }
}

//----------------------------------------피크 연산 함수--------------------------------------------------//
ArrayQueueNode* peekAQ(ArrayQueue *pQueue){

    if(pQueue != NULL){

        if(isArrayQueueEmpty(pQueue) == FALSE){

            return &(pQueue -> pElement[pQueue -> front + 1]);
        }

        return NULL;
    }
}

//----------------------------------------배열 큐를 없애는 함수-----------------------------------------------//
void deleteArrayQueue(ArrayQueue *pQueue){
    if(pQueue != NULL){

        if(pQueue -> pElement != NULL){

            free(pQueue -> pElement);
        }

        free(pQueue);
    }
}

//---------------------------------------배열이 가득 찻는지 확인하는 함수-------------------------------------//
int isArrayQueueFull(ArrayQueue *pQueue){

    int ret = FALSE;

    if(pQueue != NULL){

        if(pQueue -> rear == pQueue -> maxElementCount - 1){

            ret = TRUE;

            return ret;
        }
    }

    return ret;
}

//--------------------------------------배열이 비었는지 확인하는 함수------------------------------------------//
int isArrayQueueEmpty(ArrayQueue *pQueue){

    int ret = FALSE;

    if(pQueue != NULL){

        if(pQueue -> currentElementCount == 0){

            ret = TRUE;

            return ret;
        }

        return ret;
    }
}