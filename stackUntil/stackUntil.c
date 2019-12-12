#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackUntil.h"
#include "linkedStack.h"

#define TRUE 1
#define FALSE 0

char* reverseString(char *pSource){

    if(pSource != NULL){

        int size = strlen(pSource);
        LinkedStack *pStack = NULL;
        char *pReverseStr = NULL;
        StackNode node = {0, };

        pReverseStr = (char *)malloc(sizeof(char) * size + 1);
        pStack = (LinkedStack *)malloc(sizeof(LinkedStack));

        if(pStack != NULL){

            memset(pReverseStr, 0, sizeof(char) * size + 1);
            memset(pStack, 0, sizeof(LinkedStack));

            pStack = createLinkedStack();

            for(int i = 0; i < size; i++){

                node.data = pSource[i];

                PushLS(pStack, node);
            }
            
            for(int i = 0; i < size; i++){

                pReverseStr[i] = PopLS(pStack);
            }

            pReverseStr[size + 1] = NULL;

            return pReverseStr;
        }
    }
    else{

        printf("오류, 배열이 비었습니다\n");
    }
}

//----------------------------------------수식 괄호 검사 함수-----------------------------------//
int checkBracketMatching(char *pSource){                //마지막에 free(pNode)와 deleteLinkedStack을 하기위해서 ret을 계속 끌고간다.
                                                        //return 하지않고.
                                                        //근데 왜 free(pNode)를 하는거지?

    int ret = TRUE;

    if(pSource != NULL){

        int size = NULL;
        size = strlen(pSource);

        LinkedStack *pStack = NULL;
        pStack = createLinkedStack();
        StackNode *pNode = NULL;
        StackNode node = {0, };

        if(size == 0){

            ret = TRUE;
        }

        for(int i = 0; i < size; i++){

            char symbol = pSource[i];

            switch(symbol){

                case '[':
                case '{':
                case '(':

                node.data = symbol;
                PushLS(pStack, node);
                break;

                case ']':
                case '}':
                case ')':

                pNode = PopLS(pStack);

                if(pNode == NULL){
                    
                    ret = FALSE;
                    break;
                }
                else if(symbol == '[' && pNode->data == ']' || symbol == '{' && pNode->data == '}' ||
                symbol == '(' && pNode->data == ')'){

                    if(ret == TRUE){

                        ret = TRUE;
                        break;
                    }
                    else{

                        ret = FALSE;
                        break;
                    }
                }
                else{

                    ret = FALSE;
                    break;
                }
                
            }
        }

        if(isLinkedStackEmpty(pStack) == TRUE && ret == TRUE){

            ret = TRUE;
        }
        else{

            ret = FALSE;
        }

        free(pNode);
        DeleteLinkedStack(pStack);
    }
    else{

        printf("오류, 주어진 문자열이 NULL입니다\n");
    }

    return ret;
}
