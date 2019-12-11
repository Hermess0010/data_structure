#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubleList.h"

#define TRUE 1
#define FALSE 0

//-------------------------------------더블리스트 생성 함수----------------------------------------//
DoubleList* CreateDoubleList(){

    DoubleList *pList = NULL;
    pList = (DoubleList *)malloc(sizeof(DoubleList));

    if(pList != NULL){

        memset(pList,0,sizeof(DoubleList));

        pList -> headerNode.pLList = &(pList -> headerNode);
        pList -> headerNode.pRList = &(pList -> headerNode);

        return pList;
    }
    else{

        printf("오류, 메모리할당\n");
        return NULL;
    }
}

//---------------------------------------더블리스트 노드추가 함수------------------------------------------//
int addDLElement(DoubleList *pList, int position, DoubleListNode element){

    int ret = FALSE;

    if(pList != NULL){

        if(position >= 0 && position <= pList -> currentElementCount){

            DoubleListNode *pPreNode = NULL, *pNewNode = NULL;

            pNewNode = (DoubleListNode *)malloc(sizeof(DoubleListNode));

            if(pNewNode != NULL){

                pNewNode = &element;
                pPreNode = &(pList -> headerNode);

                for(int i = 0; i < position-1; i++){

                    pPreNode = pPreNode -> pRList;
                }

                pNewNode -> pRList = pPreNode -> pRList;
                pNewNode -> pLList = pPreNode;
                pPreNode -> pRList = pNewNode;
                pNewNode -> pRList -> pLList = pNewNode;

                ret = TRUE;
                pList ->currentElementCount++;

                return ret;

            }
            else{

                printf("에러, 유효하지않는 노드값\n");
                return ret;
            }
        }
        else{

            printf("에러, 인덱스범위 초과\n");
            return ret;
        }
    }
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
        return ret;
    }
}

//----------------------------------더블리스트 노드제거 함수--------------------------------------------------------//
int removeDLElement(DoubleList *pList, int position){

    int ret = FALSE;

    if(pList != NULL){

        if(position >= 0 && position <= pList -> currentElementCount){

            DoubleListNode *pPreNode = NULL, *pDelNode = NULL;
            pPreNode = &(pList -> headerNode);

            for(int i = 0; i < position-1; i++){

                pPreNode = pPreNode -> pRList;
            }

            pDelNode = pPreNode ->pRList;

            pPreNode -> pRList = pDelNode -> pRList;
            pDelNode -> pRList -> pLList = pPreNode;
            free(pDelNode);

            ret = TRUE;
            pList -> currentElementCount--;

            return ret;
        }
        else{

            printf("에러, 인덱스범위 초과\n");
            return ret;
        }
    } 
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
        return ret;
    }
}

//--------------------------------더블리스트 노드값 출력 함수----------------------------------------------//
DoubleListNode* getDLElement(DoubleList *pList, int position){

    DoubleListNode *pNode = NULL;
    pNode = &(pList -> headerNode);

    if(pList != NULL){

        if(position >= 0 && position <= pList -> currentElementCount){

            for(int i = 0; i < position; i++){

                pNode = pNode -> pRList;
            }

            return pNode;
        }
        else{

            printf("에러, 인덱스범위 초과\n");
            return NULL;
        }
    }
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
        return NULL;
    }
}

//----------------------------------------더블리스트 출력 함수--------------------------------------------//
void displayDoubleList(DoubleList *pList){

    DoubleListNode *pNode = NULL;
    pNode = &(pList -> headerNode);

    if(pList != NULL){

        for(int i = 0; i < pList -> currentElementCount; i++){

            printf("[%d] : %d", i, pNode -> data);
        }
    }
    else{

        printf("원소가 없습니다\n");
    }
}

//--------------------------------------더블리스트 삭제 함수---------------------------------------------------------//
void deleteDoubleList(DoubleList *pList){

    if(pList != NULL){

        clearDoubleList(pList);
        free(pList);

    }
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
    }
}

//--------------------------------------모든 노드 지우는 함수--------------------------------------------------------//
void clearDoubleList(DoubleList* pList){

    if(pList != NULL){

        while(pList -> currentElementCount > 0){

            removeDLElement(pList, 0);
        }
    }
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
    }
}

//------------------------------------더블리스트 길이 출력 함수--------------------------------------------------//
int getDoubleListLength(DoubleList *pList){

    if(pList != NULL){

        int length = pList -> currentElementCount;

        return length;
    }
    else{

        printf("에러, 유효하지않는 더블리스트값\n");
        return NULL;
    }
}