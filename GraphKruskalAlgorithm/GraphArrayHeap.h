#ifndef _ARRAY_HEAP_
#define _ARRAY_HEAP_

typedef struct HeapNode{

    int key;
    int fromVertexID;
    int toVertexID;
}HeapNode;

typedef struct ArrayHeap{

    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
}ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);
void deletArrayMaxHeap(ArrayMaxHeap* pArrayHeap);
void insertMaxHeapAH(ArrayMaxHeap *pArraHeap, HeapNode element);
HeapNode* delteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

ArrayMinHeap* createArrayMinHeap(int minElementCount);
void deletArrayMinHeap(ArrayMinHeap* pArrayHeap);
void insertMinHeapAH(ArrayMinHeap *pArraHeap, HeapNode element);
HeapNode* delteMinHeapAH(ArrayMinHeap* pArrayHeap);

#endif
