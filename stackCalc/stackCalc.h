#ifndef _STACK_CALC_
#define _STACK_CALC_

#include "exprdef.h"
#include "exprLinkedStack.h"

void clacExpr(ExprToken *pExprTokens, int tokenCount);
int PushLSExprToken(LinkedStack *pStack, ExprToken data);
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount);
int inStackPrecedence(precedence oper);
int outStackPrecedence(precedence oper);
void printToken(ExprToken element);

#endif