#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

#define TRUE 1
#define FALSE 0

//----------------------------배열 스텍 만드는 함수------------------------------------//
ArrayStack* createArrayStack(int size){

    if(size > 0){

        ArrayStack *pStack = NULL;
        
        pStack = (ArrayStack *)malloc(sizeof(ArrayStack));

        if(pStack != NULL){

            memset(pStack, 0, sizeof(ArrayStack));

            pStack -> maxElementCount = size;

            ArrayStackNode *pStackNode = NULL;

            pStackNode = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * size);

            if(pStackNode != NULL){

                memset(pStackNode, 0, sizeof(ArrayStackNode) * size);

                pStack -> pElement = pStackNode;

                return pStack;
            }
            else{

                pritnf("오류, 메모리할당 오류\n");
            }
        }
        else{

                pritnf("오류, 메모리할당 오류\n");
            }
    }
    else{

                pritnf("오류, 사이즈는 0 이상이여야합니다\n");
            }
}

//------------------------------------------------배열 리스트 푸시 연산 함수-------------------------------//
int PushAS(ArrayStack *pStack, ArrayStackNode element){

    int ret = FALSE;

    if(pStack != NULL){

        if(isArrayStackFull == FALSE){

            pStack -> pElement[pStack -> currentElementCount] = element;

            ret = TRUE;
            pStack -> currentElementCount++;

            return ret;
        }
        else{

            printf("오류, 스택이 가득 찻습니다.\n");
        }
    }else{

        printf("오류, 요휴하지않는 스택\n");
    }
}

//------------------------------------배열 리스트 팝 연산 함수---------------------------------//
ArrayStackNode* popAS(ArrayStack *pStack){

    if(pStack != NULL){

        if(isARrayStackEmpty == FALSE){

        int count;
        count = pStack -> currentElementCount - 1;

        ArrayStackNode *pNode = NULL;

        pNode = &(pStack -> pElement[count]);
        pStack -> currentElementCount--;

        return pNode;

        }
        else{

            printf("오류, 스택이 비었습니다.\n");
            return NULL;
        }
    }
    else{

            printf("오류, 요휴하지 않는 스택입니다.\n");
            return NULL;
        }
}

//-----------------------------------배열 리스트 피크 연산 함수-----------------------------------------------//

ArrayStackNode* PeekAS(ArrayStack *pStack){

    if(pStack != NULL){

        if(isARrayStackEmpty == FALSE){

        int count;
        count = pStack -> currentElementCount - 1;

        ArrayStackNode *pNode = NULL;

        pNode = &(pStack -> pElement[count]);

        return pNode;

        }
        else{

            printf("오류, 스택이 비었습니다.\n");
            return NULL;
        }
    }
    else{

            printf("오류, 요휴하지 않는 스택입니다.\n");
            return NULL;
        }
}

//------------------------------------배열 스택 삭제 함수---------------------------------------------//
void deleteArrayStack(ArrayStack *pStack){

    if(pStack != NULL){

        if(pStack -> pElement != NULL){

            free(pStack -> pElement);
        }
        free(pStack);

    }
}

//---------------------------------------배열 스택이 가득 찻는지 알려주는 함수---------------------------//
int isArrayStackFull(ArrayStack *pStack){
    
    int ret = FALSE;

    if(pStack != NULL){

        if(pStack -> currentElementCount == pStack -> maxElementCount){

            ret = TRUE;
            return ret;
        }
        else{

            return ret;
        }
    }
    else{

            printf("오류, 요휴하지 않는 스택입니다.\n");
            return NULL;
        }
}

//-----------------------------배열 스택이 비었는지 확인해주는 함수-------------------------------//
int isArrayStackEmpty(ArrayStack *pStack){

    int ret = FALSE;

    if(pStack != NULL){

        if(pStack -> currentElementCount > 0){

            ret = TRUE;

            return ret;
        }
        else{

            return ret;
        }
    }
    else{

            printf("오류, 요휴하지 않는 스택입니다.\n");
            return NULL;
        }
}
