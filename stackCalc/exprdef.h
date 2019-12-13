#ifndef _EXPR_DEF_
#define _EXPR_DEF_

typedef enum precedenceType {lparen, rparen, times, divide, plus, minus, operand} precedence; //우선순위

typedef struct ExprTokenType{                                                               //연산 토큰

    float value;
    precedence type;
}ExprToken;

#endif
