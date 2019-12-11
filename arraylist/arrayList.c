#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
#define True 1
#define False 0

//---------------------------------------------리스트 만드는 함수-----------------------------------------//
List *creatARList(int maxElementCount)
{
    List *pList = NULL;

    if (maxElementCount >= 0)
    {
        pList = (List *)malloc(sizeof(List));

        if (pList != NULL)
        { //메모리할당이 잘되었는지 검사
            pList->maxElementCount = maxElementCount;
            pList->currentElementCount = 0;
            pList->pElement = NULL;
        }
        else
        {
            printf("오류, List메모리할당 createList.\n");
            return 0;
        }
    }
    else
    {
        printf("오류, 최대 원소개수는 0개 이상이여야합니다.\n");
    }

    pList->pElement = (ListNode *)malloc(sizeof(ListNode) * pList->maxElementCount);

    if (pList->pElement == NULL)
    { //메모리할당이 잘되었는지 검사

        printf("오류, ListNode 메모리할당 createList.\n");
        free(pList);
        return 0;
    }

    memset(pList->pElement, 0, sizeof(pList->pElement) * maxElementCount);

    return pList;
}

//--------------------------------------리스트에 원소 추가하는 함수---------------------------------------//
int addElement(List *pList, int position, ListNode element)                         //position값을 인덱스값이 아닌 순서로 받음
{

    int ret = False; 
    int i = 0;

    if (pList != NULL)
    {
        if (isListFull(pList) != True )
        {

            if (position >= 0 && position <= pList->currentElementCount)
            {
                for (i = pList->currentElementCount; i >= position; i--)
                {
                    pList->pElement[i] = pList->pElement[i - 1];
                }

                pList -> pElement[position-1] = element;

                pList->currentElementCount++;
                ret = True;
            }
            else if (position == pList->currentElementCount)
            {

                pList->pElement[pList->currentElementCount] = element;

                pList->currentElementCount++;
                ret = True;
            }
            else
            {
                printf("오류, 리스트 범위 초과 - %d", position);
            }
        }
        else{
            printf("오류, 리스트 용량 초과");
        }
    }

    return ret;
}

//----------------------------------------리스트 원소 제거 함수---------------------------------------------------------//
int removeElement(List *pList, int position){                                       //position을 인덱스값이 아닌 순서값으로 받음
    
    int ret = False;
    int i = 0;

    if(pList != NULL){
        
        if(position >= 0 && position <= pList -> currentElementCount){

            for(i = position; i <= pList -> currentElementCount; i++){

                pList -> pElement[i-1] = pList -> pElement[i];
            }

            pList -> currentElementCount--;
            ret = True;

        }
        else{
            printf("오류, 리스트 범위를 초과함.");
            return 0;
        }
    }
    else{
        printf("오류, 리스트값이 없음.");
        return 0;
    }

    return ret;
}

//------------------------------------------------리스트 원소 반환 함수-----------------------------------------------//
ListNode* getELement(List *pList,int position){

    ListNode *ret = NULL;

    if(pList != NULL){
        
        if(position > 0 && position <= pList -> currentElementCount){

            ret = &(pList -> pElement[position-1]);
            return ret;
        }
        else{

            printf("리스트 범위 초과");
        }
    }
}

//---------------------------------------------리스트 출력 함수---------------------------------------------------------//
void displayARList(List *pList){

    if(pList != NULL){

        int i = 0;
        
        printf("최대 원소 개수 : %d\n", pList -> maxElementCount);
        printf("현재 원소 개수 : %d\n", pList -> currentElementCount);

        for(; i < pList -> currentElementCount; i++){
            
            printf("[%d] : %d\n", i, getElement(pList, i) -> data);
        }

        for(; i < pList -> maxElementCount; i++){

            printf("[%d] : empty\n", i);
        }
    }
    else{

        printf("list is NULL \n");
    }
}

//-------------------------------------------리스트 용량 검사 함수------------------------------------------------------//
int isArListFull(List *pList){

    if(pList != NULL){

        if(pList -> currentElementCount == pList -> maxElementCount){

            return True;
        }
        else{
            
            return False;
        }
    }
}

//-----------------------------------------리스트 길이 출력 함수------------------------------------------------------------//
int getARListLength(List *pList){

    int length = 0;

    if(pList != NULL){

        length = pList -> currentElementCount;

        return length;
    }
    else{
        return 0;
    }
}

//------------------------------------------리스트 삭제 함수----------------------------------------------------------------//
void deleteARList(List *pList){

    if(pList != NULL){

        free(pList -> pElement);
        free(pList);
    }
}

//-----------------------------------------첫번째에 원소 추가하는 함수------------------------------------------------------//
int addARListFirst(List *pList, ListNode element){

    return addElement(pList, 0, element);
}

//-----------------------------------------마지막에 원소 추가하는 함수--------------------------------------------------------//
int addARListLast(List *pList, ListNode element){

    return addElement(pList, pList -> currentElementCount+1, element);
    
}

