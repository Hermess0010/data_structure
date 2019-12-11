#ifndef _CICULARLIST_
#define _CICULARLIST_

typedef struct CicularListNode{

    int data;
    struct CicularListNode *pLink;
}CicularListNode;

typedef struct CicularList{

    int currentElementCount;
    CicularListNode *pLink;
}CicularList;

CicularList createCicularList();
int deleteCicularList(CicularList *pList);
int addCLElement(CicularList *pList, int position, CicularListNode element);
int removeCLElemnt(CicularList *pList, int position);
void clearCicularList(CicularList *pList);
int getCicularListLength(CicularList *pList);
CicularListNode* getCLElement(CicularList *pList, int position);
void displayCicularList(CicularList *pList);

#endif
