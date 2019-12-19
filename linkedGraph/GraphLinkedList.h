#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct GraphVertex{

    int vertexID;
    int weight;
}GraphVertex;

typedef struct ListNode{

    GraphVertex data;
    ListNode *pLink;
}ListNode;

typedef struct LinkedList{

    int currentElementCount;
    ListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode* getElement(LinkedList *pList, int position);
void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);
int isEmpty(LinkedList *pList);

#endif