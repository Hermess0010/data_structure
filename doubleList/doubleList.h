#ifndef _DOUBLELIST_
#define _DOUBLELIST_

typedef struct DoubleListNode{

    int data;
    DoubleListNode *pLList;
    DoubleListNode *pRList;
}DoubleListNode;

typedef struct DoubleList{

    int currentElementCount;
    DoubleListNode headerNode;
}DoubleList;

DoubleList* CreateDoubleList();
void deleteDoubleList(DoubleList* pList);
int addDLElement(DoubleList *pList, int position, DoubleListNode element);
int removeDLElement(DoubleList *pList, int position);
void clearDoubleList(DoubleList *pList);
int getDoubleListLength(DoubleList *pLIst);
DoubleListNode* getDLElement(DoubleList *pList, int position);
void displayDoubleList(DoubleList *pList);

#endif