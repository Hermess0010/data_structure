#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedStack.h"

#define TRUE 1
#define FALSE 0

//----------------------------------------연결 스택 만드는 함수-----------------------------//
LinkedStack* createLinkedStack(){

    LinkedStack *pStack = NULL;

    pStack = (LinkedStack *)malloc(sizeof(LinkedStack));

    if(pStack != NULL){

        memset(pStack, 0, sizeof(LinkedStack));

        return pStack;
    }
    else{

        printf("오류, 메모리할당 오류\n");
        return pStack;
    }
}

//-----------------------------------------연결 스택 푸시 함수----------------------------------//
int PushLS(LinkedStack *pStack, StackNode element){

    int ret = FALSE;

    if(pStack != NULL){

        StackNode *pNode = NULL;

        pNode = (StackNode *)malloc(sizeof(StackNode));

        if(pNode != NULL){

            memset(pNode, 0, sizeof(StackNode));

            pNode = &element;

            pNode -> pLink = pStack -> pTopElement;
            pStack -> pTopElement = pNode;

            ret = TRUE;
            pStack -> currentElementCount++;

            return ret;
        }
        else{

        printf("오류, 메모리할당 오류\n");
        return ret;
        }
    }
    else{

        printf("오류, 메모리할당 오류\n");
        return ret;
    }
}

//--------------------------------------연결 리스트 팝 연산 함수---------------------------------//
StackNode* PopLS(LinkedStack *pStack){

    if(pStack != NULL){

        if(isLinkedStackEmpty == FALSE){

            StackNode *pNode = NULL;
            pNode = pStack -> pTopElement;
            pStack -> pTopElement = pNode -> pLink;

            pStack -> currentElementCount--;

            return pNode;
            
        }
        else{

        printf("오류, 스택이 비었습니다\n");
        return NULL;
        }
    }
    else{

        printf("오류, 유효하지않는 스택\n");
        return NULL;
    }
}

//-----------------------------------------연결리스트 피크 함수--------------------------------------------//
StackNode* PeekLS(LinkedStack *pStack){

    if(pStack != NULL){

        if(isLinkedStackEmpty == FALSE){

            StackNode *pNode = NULL;
            pNode = pStack -> pTopElement;

            pStack -> currentElementCount--;

            return pNode;
            
        }
        else{

        printf("오류, 스택이 비었습니다\n");
        return NULL;
        }
    }
    else{

        printf("오류, 유효하지않는 스택\n");
        return NULL;
    }
}

//--------------------------------------------연결 스택 삭제 함수---------------------------------------//
void deleteLinkedStack(LinkedStack *pStack){

    if(pStack != NULL){

        if(isLinkedStackEmpty(pStack) == FALSE){

            StackNode *pNode = NULL, *pDelNode = NULL;
            pNode = pStack -> pTopElement;

            for(int i = 0; i < pStack -> currentElementCount; i++){

                pDelNode = pNode;
                pNode = pNode -> pLink;

                free(pDelNode);
            }

            free(pStack);
        }
        else{

        printf("오류, 스택이 비었습니다\n");
        return NULL;
        }
    }
    else{

        printf("오류, 유효하지않는 스택\n");
        return NULL;
    }
}

//--------------------------------------연결 스택이 꽉찻는지 확인하는 함수------------------------------------//
int isLinkedStackFull(LinkedStack *pStack){

    int ret = FALSE;
    return ret;
}

//---------------------------------------연결 스택이 비었는지 확인하는 함수----------------------------------//
int isLinkedStackEmpty(LinkedStack *pStack){

    int ret = FALSE;

    if(pStack -> currentElementCount == 0){

        ret = TRUE;
        return ret;
    }

    return ret;
}