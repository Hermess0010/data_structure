#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

#define TRUE 1
#define FALSE 0
// position값은 인덱스로 받는다
//---------------------------------------------연결 리스트 생성 함수-----------------------------------//
LinkedList* createLinkedList(){

    LinkedList *pList = NULL;

    pList = (LinkedList *)malloc(sizeof(LinkedList));

    if(pList != NULL){

        memset(pList, 0, sizeof(LinkedList));

        return pList;
    }
    else{

        printf("오류, 메모리 할당\n");

        return NULL;
    }
}

//--------------------------------------------연결 리스트 노드 추가 함수-------------------------------//
int addLLElement(LinkedList *pList, int position, ListNode element){

    int ret = FALSE;

    if(pList != NULL){


        if(position >= 0 && position <= pList -> currentElementCount){


            ListNode *pNewNode = NULL, *pPreNode = NULL;
            pNewNode = (ListNode *)malloc(sizeof(ListNode));
            pNewNode = &element;

            pPreNode = &(pList -> headerNode);

            for(int i = 0; i < position; i++){
                
                pPreNode = pPreNode -> pLink;
            }

            pNewNode -> pLink = pPreNode -> pLink;
            pPreNode -> pLink = pNewNode;

            ret = TRUE;
            pList -> currentElementCount++;
            
            return ret;

        }
        else{

            printf("오류, 인덱스 허용범위 초과\n");  
            return ret;      
        }
    }
    else{


            printf("오류, 유효하지않는 리스트\n");  
            return ret; 
    }
}

//-------------------------------------연결 리스트 원소 제거 함수----------------------------------------//
int removeLLElement(LinkedList *pList, int position){

    int ret = FALSE;

    if(pList != NULL){

        if(position >= 0 && position <= pList -> currentElementCount){

            ListNode *DelNode = NULL, *pPreNode = NULL;
            pPreNode = &(pList -> headerNode);

            for(int i = 0; i < position-1; i++){

                pPreNode = pPreNode -> pLink;
            }

            DelNode = pPreNode -> pLink;

            pPreNode -> pLink = DelNode -> pLink;

            free(DelNode);
            ret = TRUE;

            pList -> currentElementCount--;
            
            return ret;
        }
        else{
            
            printf("오류, 인덱스 허용범위 초과\n");  
            return ret; 

        }
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
        return ret; 
    }
}

//------------------------------------연결 리스트 원소 출력 함수-------------------------------------------//
ListNode *getLLElement(LinkedList *pList, int position)
{

    ListNode *pNode = NULL;

    if (pList != NULL)
    {

        if (position >= 0 && position <= pList->currentElementCount)
        {

            pNode = &(pList->headerNode);

            for (int i = 0; i < position; i++)
            {

                pNode = pNode->pLink;
            }

            return pNode;
        }
        else{
            
            printf("오류, 인덱스 허용범위 초과\n");  
            return NULL; 

        }
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
        return NULL; 
    }
}
//---------------------------------------------연결 리스트 삭제 함수----------------------------------//
void deleteLinkeList(LinkedList *pList){

    if(pList != NULL){

        clearLinkedList(pList);
        free(pList);
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
    }
}

//-------------------------------------------연결 리스트 값 삭제함수-----------------------------------//
void clearLinkedList(LinkedList *pList){

    if(pList != NULL){

        while(pList -> currentElementCount > 0){

            removeLLElement(pList,0);
        }
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
    }
}

//------------------------------------------연결 리스트 길이 출력 함수-------------------------------------//
int getLinkedListLength(LinkedList *pList){

    if(pList != NULL){

        int length = NULL;
        length = pList -> currentElementCount;

        return length;
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
        return 0;
    }
}

//------------------------------------연결리스트 출력 함수----------------------------------------------------//
void displayLinkedList(LinkedList *pList){

    if(pList != NULL){

        for(int i = 0; i < pList -> currentElementCount; i++){

            printf("[%d] : %d", i, getElement(pList,i));
        }
    }
}

//-----------------------------------------연결 리스트가 비었는지 확인하는 함수-------------------------------//
int isEmpty(LinkedList *pList){

    int ret = FALSE;

    if(pList != NULL){

        if(pList -> currentElementCount == 0){

            ret = TRUE;

            return ret;
        }

        return ret;
    }
    else{
            
        printf("오류, 유효하지않는 리스트\n");  
        return ret;
    }
    
}