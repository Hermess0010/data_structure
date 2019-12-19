#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct StackNode{

    char data;
    struct stackNode *pLink;
}StackNode;

typedef struct LinkedStack{

    int currentElementCount;
    StackNode *pTopElement;
}LinkedStack;

LinkedStack* createLinkedStack();
int PushLS(LinkedStack *pStack, StackNode element);
StackNode* PopLS(LinkedStack *pStack);
StackNode* PeekLS(LinkedStack *pStack);
void DeleteLinkedStack(LinkedStack *pStack);
int isLinkedStackFull(LinkedStack *pStack);
int isLinkedStackEmpty(LinkedStack *pStack);

#endif