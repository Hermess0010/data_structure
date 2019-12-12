#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct StackNode{

    char data;
    struct stackNode *pLink;
}StackNode;

typedef struct LinkedStack{

    int currentElementCount;
    stackNode *pTopElement;
}LinkedStack;

LinkedStack* createLinkedStack();
int PushLS(LinkedStack *pStack, StackNode element);
stackNode* PopLS(LinkedStack *pStack);
stackNode* PeekLS(LinkedStack *pStack);
void DeleteLinkedStack(LinkedStack *pStack);
int isLinkedStackFull(LinkedStack *pStack);
int isLinkedStackEmpty(LinkedStack *pStack);

#endif