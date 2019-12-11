#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cicularList.h"

#ifndef _LIST_DEF_
#define _LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
// 모든 position 값은 인덱스로 받음
//-------------------------------------------원형리스트 원소 추가 함수----------------------------//
int addCLElement(CicularList *pList, int position, CicularListNode element){

    int ret = FALSE;

    CicularListNode *pNewNode = NULL, *pPreNode = NULL, *pLastNode = NULL;

    if(pList =! NULL){

        if(position >= 0 && position <= pList ->currentElementCount){

            pNewNode = (CicularListNode *)malloc(sizeof(CicularListNode));

            if(pNewNode == NULL){
                printf("오류, 메모리할당");
                return ret;
            }
            *pNewNode = element;
            pNewNode -> pLink = NULL;

            if(position == 0 && pList -> currentElementCount == 0){              //공백 리스트에 추가하기    
                
                pList -> pLink = pNewNode;
                pNewNode -> pLink = pNewNode;

                pList -> currentElementCount++;
                ret = TRUE;

                return ret;
            }
            else if(position == 0){                                             //공백이 아닌 리스트에 첫번째값 추가하기

                pLastNode = pList -> pLink;

                while(pLastNode -> pLink != pList -> pLink){                                    //마지막 노드값 찾는 로직
                    
                    pLastNode = pLastNode -> pLink;
                }

                pNewNode = pLastNode -> pLink;
                pLastNode -> pLink = pNewNode;

                pList -> currentElementCount++;
                ret = TRUE;

                return ret;

            }
            else{                                                                 //나머지 로직
                
                    pPreNode = pList -> pLink;

                    for(int i = 0; i < position - 1; i++){                                          //이전 노드값 찾는 로직

                        pPreNode = pPreNode -> pLink;
                    }

                    pNewNode -> pLink = pPreNode -> pLink;
                    pPreNode -> pLink = pNewNode;

                    pList -> currentElementCount++;
                    ret = TRUE;

                    return ret;
            }
        }
        else{

            printf("인덱스값 초과\n");
            return ret;
        }
    }
    else{
        
        printf("리스트 오류\n");
        return ret;
    }
}

//---------------------------------------원형 리스트 노드 제거 함수-------------------------------------------//
int removeCLElement(CicularList *pList, int position){

    if(pList != NULL){

        if(position >= 0 && position <= pList -> currentElementCount){

            int ret = FALSE;
            CicularListNode *pDelNode = NULL, *pLastNode = NULL, *pPreNode = NULL;

            if(position == 0 && pList -> currentElementCount == 1){

                pDelNode = pList -> pLink;
                free(pDelNode);
                pList -> pLink = NULL;

                pList -> currentElementCount--;
                ret = TRUE;

            }
            else if(position == 0){

                pLastNode = pList -> pLink;
                pDelNode = pList -> pLink;

                while(pLastNode -> pLink != pList -> pLink){                    //마지막 노드값 찾는 로직
                
                pLastNode = pLastNode -> pLink;

                }

                pLastNode -> pLink = pDelNode -> pLink;
                pList -> pLink = pDelNode -> pLink;
                free(pDelNode);

                pList -> currentElementCount--;
                ret = TRUE;

            }
            else{
                pPreNode = pList -> pLink;

                for(int i = 0; i < position - 1; i++){                                          //이전 노드값 찾는 로직

                    pPreNode = pPreNode -> pLink;

                }

                pDelNode = pPreNode -> pLink;
                pPreNode -> pLink = pDelNode -> pLink;

                free(pDelNode);
                ret = TRUE;
                
                return ret;
                
            }
        }else{

            printf("오류,인덱스 범위 초과\n");
        }
    }else{

        printf("오류, 유효하지않은 원형 리스트\n");
    }
}

//------------------------------------------원소 출력 함수----------------------------------//
CicularListNode *getCLElement(CicularList *pList, int position)
{

    if (pList != NULL)
    {

        if (position >= 0 && position <= pList->currentElementCount)
        {
            CicularListNode *pNode = NULL;
            pNode = pList->pLink;
                for (int i = 0; i < position; i++)
                {

                    pNode = pNode->pLink;
                }

                return pNode;
            
        }
        else{
            printf("오류, 인덱스 허용 범위 초과\n");
        }
    }
    else{
        printf("오류, 유효하지않는 원형리스트\n");
    }
}

//--------------------------------------원형 리스트 만드는 함수-------------------------------------------------//
CicularList* createCularList(){

    CicularList *pReturn = NULL;

    pReturn = (CicularList *)malloc(sizeof(CicularList));

    if(pReturn != NULL){

        memset(pReturn, 0, sizeof(CicularList));

        return pReturn;
    }
    else{

        printf("오류, 메모리할당");
        
        return NULL;
    }
}

//------------------------------------원형 리스트 출력 함수----------------------------------------------------//
void displayCicularList(CicularList *pList)
{
    if (pList != NULL)
    {

        CicularListNode *pNode = NULL;

        pNode = pList->pLink;
        
        printf("%d\n", pList->currentElementCount);
        for (int i = 0; i < pList->currentElementCount; i++)
        {

            printf("[%d] : %d\n", i, pNode->data);
            pNode = pNode -> pLink;
        }
    }
    else{
        printf("원소가 없습니다\n");
    }
}

//---------------------------------원형 리스트 길이 출력 함수--------------------------------------------------//
int getCicularListLength(CicularList *pList){

    if(pList != NULL){

        int length = pList -> currentElementCount;

        return length;
    }
}

//----------------------------------원형 리스트 삭제 함수-------------------------------------------------------//
int deleteCicularList(CicularList *pList){

    int ret = FALSE;

    if(pList != NULL){

        clearCicularList(pList);
        free(pList);
        ret = TRUE;

        return ret;
    }
}

//---------------------------------------원형 리스트 노드 삭제 함수----------------------------------------------//
int clearCicylarList(CicularList *pList){

    int ret = FALSE;

    if(pList != NULL){

        while(pList -> currentElementCount > 0){

            removeCLElement(pList,0);
        }
    }
}