#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "stackCalc.h"
#include "exprLinkedStack.h"

//----------------------------중위표기법에서 후위표기법으로 바꿔서 출력하는 함수-------------------------------//
void convertInfixToOutfix(ExprToken *pExprTokens, int tokenCount){

    if(pExprTokens != NULL){

        if(tokenCount > 0){

            LinkedStack *pStack = NULL;
            StackNode *pNode = NULL;
            precedence tokenType = operand;
            precedence inStackTokenType = operand;

            pStack = createLinkedStack();

            if(pStack != NULL){

                for(int i = 0; i < tokenCount; i++){

                 tokenType = pExprTokens[i].type;
                 inStackTokenType = PeekLS(pStack) -> data.type;

                 switch(tokenType){

                     case operand:
                        printf("%f\n", pExprTokens -> value);
                        break;

                    case lparen:
                        PushLSExprToken(pStack, pExprTokens[i]);
                        break;

                    case times:
                    case divide:
                        PushLSExprToken(pStack, pExprTokens[i]);
                        break;

                    case plus:
                    case minus:
                            if(tokenType <= inStackTokenType){

                            pNode = PopLS(pStack);
                            PushLSExpreToken(pStack, pExprTokens[i]);
                            printf("%f\n", pNode -> data.value);

                            free(pNode);
                            break;

                            }else if(inStackTokenType == lparen){

                            PushLSExprToken(pStack,pExprTokens[i]);
                            break;
                            }

                    case rparen:
                        
                        while(pStack -> pTopElement -> data.type != rparen){

                            pNode = PopLS(pStack);
                            printf("%f\n", pNode -> data.value);
                            free(pNode);
                        }

                        popLS(pStack);
                        break;
                    }  
                 
                }

                while(pStack -> currentElementCount > 0){

                    pNode = popLS(pStack);
                    printf("%f\n", pNode -> data.value);

                    free(pNode);
                }
            }
            DeleteLinkedStack(pStack);

        }
    }
}

//------------------------------------------expreToken을 스택에 푸쉬하는 함수--------------------------------//
int pushLSExprToken(LinkedStack *pStack, ExprToken data){

    if(pStack != NULL){

        StackNode Node ={0, };

        Node.data = data;

        return pushLS(pStack, Node);
    }

}

//------------------------------------------수식을 계산하는 함수-------------------------------------------------//
void calcExpr(ExprToken *pExprTokens, int tokenCount){

    LinkedStack *pStack = NULL;
    StackNode *pNodeA = NULL, *pNodeB = NULL;
    precedence TokenType;
    ExprToken NewToken = {operand, };
    float op1 = 0;
    float op2 = 0;

    if(pStack != NULL){

        for(int i = 0; i < tokenCount; i++){

            TokenType = pExprTokens[i].type;

            if(TokenType >= 2 && TokenType <= 5){

                pNodeA = popLS(pStack);
                pNodeB = popLS(pStack);

                op1 = pNodeA -> data.value;
                op2 = pNodeB -> data.value;

                free(pNodeA);
                free(pNodeB);
            }

            switch(TokenType){

                case operand:
                    PushLSExprToken(pStack, pExprTokens[i]);
                    break;

                case lparen:
                    pushLSExprToken(pStack, pExprTokens[i]);
                    break;

                case minus:
                    NewToken.value = op1 - op2;
                case plus:
                    NewToken.value = op1 + op2;
                case times:
                    NewToken.value = op1 * op2;
                case divide:
                    NewToken.value = op1 / op2;

                    pushLSExprToken(pStack, NewToken);

                    break;
            }
        }

        pNodeA = popLs(pStack);

        if(pNodeA != NULL && pStack -> currentElementCount == 0){

            printf("수식 결과 계산 [%f]\n", pNodeA ->data.value);
            free(pNodeA);
        }
        else{

            printf("오류, 수식에 오류가 있습니다.\n");
        }
        

        DeleteLinkedStack(pStack);

    }
}
//----------------------------------스택 안에 있는 데이터의 우선순위(먼저나가야함)를 출력해주는 함수----------------------//
int inStackPrecedence(precedence oper){

    switch(oper){
        case lparen:
            return 0;
        case rparen:
            return 4;
        case times:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }

    return -1;
}
//-------------------------------------스택 밖에 있는 데이터의 우선순위(먼저 들어가야함)를 출력해주는 함수-------------------//
int outStackPrecedence(precedence oper){

    switch(oper){
        case lparen:
            return 5;
        case rparen:
            return 4;
        case times:
        case divide:
            return 2;
        case plus:
        case minus:
            return 1;
    }

    return -1;
}

//--------------------------------------토큰을 출력해주는 함수 -------------------------------------------//
void printToken(ExprToken element){

    switch(element.type){

        case lparen:
            printf("(\n");
            break;

        case rparen:
            printf(")\n");
            break;

        case plus:
            printf("+\n");
            break;
        
        case minus:
            printf("-\n");
            break;

        case times:
            printf("*\n");
            break;

        case divide:
            printf("/\n");
            break;

        case operand:
            printf("%f",element.value);
            break;
    }
}









