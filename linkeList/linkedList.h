#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNode{

    int data;
    struct ListNode *pLink;
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