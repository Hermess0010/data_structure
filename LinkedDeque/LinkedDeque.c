#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedDeque.h"

#define TRUE 1
#define FALSE 0

//------------------------------------------포인터 덱 만드는 함수---------------------------------//
LinkedDeque* createLinkedDeque(){

    LinkedDeque *pDeque = NULL;

    pDeque = (LinkedDeque *)malloc(sizeof(LinkedDeque));

    if(pDeque != NULL){

        memset(pDeque, 0, sizeof(LinkedDeque));

        return pDeque;
    }
    else{

        printf("오류, 메모리오류\n");
        return NULL;
    }
}

//----------------------------------------앞쪽에 노드를 추가하는 함수-------------------------------//
int endequeFrontLD(LinkedDeque *pDeque, DequeNode element){

    int ret = FALSE;

    if(pDeque != NULL){

        DequeNode *pNode = NULL;

        pNode = (DequeNode *)malloc(sizeof(DequeNode));

        if(pNode != NULL){

            memset(pNode, 0, sizeof(DequeNode));

            pNode -> data = element.data;

            if(isLinkedDequeEmpty(pDeque) == TRUE){

                pDeque -> pFrontNode = pNode;
                pDeque -> pRearNode = pNode;

                pDeque -> currentElementCount++;

                ret = TRUE;
            }
            else{

                pDeque -> pFrontNode -> pLLink = pNode;
                pNode -> pRLink = pDeque -> pFrontNode;
                pDeque -> pFrontNode = pNode;

                pDeque -> currentElementCount++;

                ret = TRUE;
            }
        }
        else{

        printf("오류, 메모리오류\n");
        free(pNode);

        return ret;
        }
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return ret;
    }
}

//---------------------------------------뒤쪽에 노드를 추가하는 함수-----------------------------------//
int endequeRearLD(LinkedDeque *pDeque, DequeNode element){

    int ret = FALSE;

    if(pDeque != NULL){

        DequeNode *pNode = NULL;

        pNode = (DequeNode *)malloc(sizeof(DequeNode));

        if(pNode != NULL){

            memset(pNode, 0, sizeof(DequeNode));

            pNode -> data = element.data;

            if(isLinkedDequeEmpty(pDeque) == TRUE){

                pDeque -> pFrontNode = pNode;
                pDeque -> pRearNode = pNode;

                pDeque -> currentElementCount++;

                ret = TRUE;
            }
            else{

                pDeque -> pRearNode -> pRLink = pNode;
                pNode -> pLLink = pDeque -> pRearNode;
                pDeque -> pRearNode = pNode;

                pDeque -> currentElementCount++;

                ret = TRUE;
            }
        }
        else{

        printf("오류, 메모리오류\n");
        free(pNode);

        return ret;
        }
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return ret;
    }
    
}

//-------------------------------앞쪽 노드를 디덱하는 함수---------------------------------------------//
DequeNode* dedequeFrontLD(LinkedDeque *pDeque){

    if(pDeque != NULL){

        DequeNode *pNode = NULL;

        pNode = pDeque -> pFrontNode;
        pDeque -> pFrontNode -> pRLink -> pLLink = NULL;
        pDeque -> pFrontNode = pDeque -> pFrontNode -> pRLink;
        pNode -> pRLink = NULL;

        pDeque -> currentElementCount--;

        if(isLinkedDequeEmpty(pDeque) == TRUE){

            pDeque -> pRearNode = NULL;
        }

        return pNode;
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return NULL;
    }
    
}

//----------------------------------------뒤쪽에 디덱하는 함수------------------------------------------------//
DequeNode* dedequeRearLD(LinkedDeque *pDeque){

    if(pDeque != NULL){

        DequeNode *pNode = NULL;

        pNode = pDeque -> pRearNode;
        pDeque -> pRearNode -> pLLink -> pRLink = NULL;
        pDeque -> pRearNode = pDeque -> pRearNode -> pLLink;
        pNode -> pLLink = NULL;

        pDeque -> currentElementCount--;

        if(isLinkedDequeEmpty(pDeque) == TRUE){

            pDeque -> pFrontNode = NULL;
        }

        return pNode;
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return NULL;
    }
    
}

//------------------------------------앞쪽을 피크 하는 함수-------------------------------------------//
DequeNode* peekFrontLD(LinkedDeque *pDeque){

    if(pDeque != NULL){

        if(isLinkedDequeEmpty(pDeque) == FALSE){

            DequeNode *pNode = NULL;

            pNode = pDeque->pFrontNode;

            return pNode;
        }
        else{

            printf("오류, 덱이 비었습니다.\n");

            return NULL;
        }
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return NULL;
    }
}

//-----------------------------------------뒤쪽을 피크하는 함수-------------------------------------------------//
DequeNode* peekRearLD(LinkedDeque *pDeque){

    if(pDeque != NULL){

        if(isLinkedDequeEmpty(pDeque) == FALSE){

            DequeNode *pNode = NULL;

            pNode = pDeque->pRearNode;

            return pNode;
        }
        else{

            printf("오류, 덱이 비었습니다.\n");

            return NULL;
        }
    }
    else{

        printf("오류, 유효하지않은 덱\n");

        return NULL;
    }
}

//---------------------------------------덱을 삭제하는 함수-------------------------------------------------------//
void deleteLinkedDeque(LinkedDeque *pDeque){

    if(pDeque != NULL){

        if(isLinkedDequeEmpty(pDeque) == FALSE){

            DequeNode *pNode = NULL;

            while(isLinkedDequeEmpty(pDeque) != TRUE){

                pNode = dequeFrontLD(pDeque);
                free(pNode);
            }

            free(pDeque);
        }
    }
}

//---------------------------------------------덱이 가득 찼는지 확인하는 함수--------------------------------------//
int isLinkedDequeFull(LinkedDeque *pDeque){

    int ret = FALSE;

    return ret;
}

//--------------------------------------------덱이 비었는지 확인 하는 함수--------------------------------------------//
int isLinkedDequeEmpty(LinkedDeque *pDeque){

    int ret = FALSE;

    if(pDeque -> currentElementCount == 0){

        ret = TRUE;
    }

    return ret;
}