#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

typedef struct ArrayStackNode{

    char data;
}ArrayStackNode;

typedef struct ArrayStack{

    int maxElementCount;
    int currentElementCount;
    ArrayStackNode *pElement;
}ArrayStack;

ArrayStack* createArrayStack(int maxElementCount);
int pushAS(ArrayStack *pStack, ArrayStackNode element);
ArrayStackNode* popAS(ArrayStack *pStack);
ArrayStackNode* peakAS(ArrayStack *pStack);
void deleteArrayStack(ArrayStack *pStack);
int isArrayStackFull(ArrayStack *pStack);
int isARrayStackEmpty(ArrayStack *pStack);

#endif
