#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

typedef struct ListNode {
    int data; //리스트의 값으로 사용됨
}ListNode;

typedef struct List{
    int maxElementCount; //리스트의 최대 갯수로 사용됨
    int currentElementCount; //리스트의 현재 갯수로 사용됨
    ListNode *pElement; //리스트의 data를 저장하는 배열의 주소
}List;

List* createARList(int maxElemenCount);
void deleteArList(List *pList);
int isARListIsFull(List *pList);
int addElement(List *pList, int position);
int removeElemnt(List *pList, int position);
ListNode* getElement(List *pList, int position);
void displayARList(List *pList);
void clearARList(List *pList);
int getARListLength(List *pList);

#endif

#ifdef _BOOLEAN_DATA_
#define _BOOLEAN_DATA_

#define TRUE    1
#define FLASE   0

#endif