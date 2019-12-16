#ifndef _LINKED_DEQUE_
#define _LINKED_DEQUE_

typedef struct DequeNode{

    char data;
    DequeNode *pRLink;
    DequeNode *pLLink;
}DequeNode;

typedef struct LinkedDeque{

    int currentElementCount;
    DequeNode *pFrontNode;
    DequeNode *pRearNode;
}LinkedDeque;

LinkedDeque* createLinkedDeque();
int endequetFrontLD(LinkedDeque *pDeque, DequeNode element);
int endequeRearLD(LinkedDeque *pDeque, DequeNode elemenet);
DequeNode* dedequeFrontLD(LinkedDeque *pDeque);
DequeNode* dedequeRearLD(LinkedDeque *pDeque);
DequeNode* peekFrontLD(LinkedDeque *pDeque);
DequeNode* PeekRearLD(LinkedDeque *pDeque);
void deleteLinkedDeque(LinkedDeque *pDeque);
int isLinkedDequeFull(LinkedDeque *pDeque);
int isLinkedDequeEmpty(LinkedDeque *pDeque);

#endif