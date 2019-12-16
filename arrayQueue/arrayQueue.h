#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNode{
    
    char element;
}ArrayQueueNode;

typedef struct  ArryaQueue
{
    int maxElementCount;
    int currentElementCount;
    int front;
    int rear;
    ArrayQueueNode *pElement;
}ArrayQueue;

ArrayQueue* createArrayQueue(int maxELementCount);
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element);
ArrayQueueNode* dequeueAQ(ArrayQueue *pQueue);
ArrayQueueNode* peekAQ(ArrayQueue *pQueue);
void deleteArrayQueue(ArrayQueue *pQueue);
int isArrayQueueFull(ArrayQueue *pQueue);
int isArrayQueueEmpty(ArrayQueue *pQueue);

#endif
