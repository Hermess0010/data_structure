#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayHeap.h"

//---------------------------------최대 히프 생성 함수--------------------------------------------------//
ArrayMaxHeap* createArrayMaxHeap(int maxElementCount){

    if(maxElementCount > 0){

        ArrayMaxHeap *pHeap = NULL;
        HeapNode *pNode = NULL;

        pHeap = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));

        if(pHeap != NULL){

            memset(pHeap, 0, sizeof(pHeap));

            pHeap -> maxElementCount = maxElementCount;

            pNode = (HeapNode *)malloc(sizeof(HeapNode) * maxElementCount);

            if(pNode != NULL){

                memset(pNode, 0, sizeof(pNode) * maxElementCount);

                pHeap -> pElement = pNode;

                return pHeap;
            }
            else{

                printf("오류, 메모리할당\n");
                return NULL;
            }   
        }
        else{

            printf("오류, 메모리할당\n");
            return NULL;
        }
    }
    else{

        printf("오류, 유효하지않은 최대 노드 개수\n");
        return NULL;
    }
}

//-----------------------------------------최대 히프 삽입 연산 함수-----------------------------------------//
void insertMaxHeapAH(ArrayMaxHeap *pHeap, HeapNode element){

    if(pHeap != NULL){

        if(pHeap -> currentElementCount < pHeap -> maxElementCount){
            
            pHeap -> currentElementCount++;

            int i = pHeap -> currentElementCount;
            HeapNode temp = {0, };

            pHeap -> pElement[i] = element;

            if(i > 1){

                while(pHeap -> pElement[(int)(i / 2)].key < pHeap -> pElement[i].key){

                    temp = pHeap -> pElement[i / 2];
                    pHeap -> pElement[i / 2] = pHeap -> pElement[i];
                    pHeap -> pElement[i] = temp;

                    i /= 2;

                    if(i < 1){
                        
                        break;
                    }
                }

            }
            
        }
        else{

            printf("최대 히프가 가득 찼습니다\n");
        }
    }
}

//----------------------------------------최대 히프에서 삭제 연산-------------------------------------//
HeapNode* deleteMaxHeapAH(ArrayMaxHeap *pHeap){

    if(pHeap != NULL){

        HeapNode *pNode = NULL;
        HeapNode temp = {0, };
        int i = pHeap -> currentElementCount;
        int child = 0;

        pNode = (HeapNode *)malloc(sizeof(HeapNode));

        if(pNode != NULL){

            *pNode = pHeap -> pElement[1];

            temp = pHeap -> pElement[1];
            pHeap -> currentElementCount--;

            i = 1;
            child = i * 2;

            while(temp.key < pHeap -> pElement[child].key || 
                temp.key < pHeap -> pElement[child + 1].key){

                    if(pHeap -> pElement[child].key > pHeap -> pElement[child + 1].key){

                        pHeap -> pElement[i] = pHeap -> pElement[child];
                        temp = pHeap -> pElement[child];


                        i *= 2;
                        child = i * 2;
                    }
                    else{

                        pHeap -> pElement[i] = pHeap -> pElement[child + 1];
                        temp = pHeap -> pElement[child + 1];

                        i *= 2;
                        child = i * 2;
                    }

            }

            pHeap -> pElement[i] = temp;
            return pNode;
        }
        else{

            printf("오류, 메모리할당\n");
            return NULL;
        }
        
    }
    else{

            printf("오류, 유효하지않은 히프\n");
            return NULL;
        }
}

//------------------------------히프 삭제 함수---------------------------------------------------------//
void deletArrayMaxHeap(ArrayMaxHeap *pHeap){

    if(pHeap != NULL){
        
        if(pHeap -> pElement == NULL){
            free(pHeap -> pElement);
        }

        free(pHeap);
    }
}