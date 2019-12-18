#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapElement{

    int key;
    char data;
}HeapNode;

typedef struct ArrayHeap{

    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
}ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deletArrayMaxHeap(ArrayMaxHeap* pArrayHeap);
void insertMaxHeapAH(ArrayMaxHeap *pArraHeap, HeapNode element);
HeapNode* delteMAxHeapAH(ArrayMaxHeap* pArrayHeap);

#endif
