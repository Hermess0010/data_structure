#ifndef _LINKED_QUEUE_
#define _LINKED_QUEUE_

typedef struct QueueNode
{
    char data;
    QueueNode *pLink;
}QueueNode;

typedef struct LinkedQueue{

    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
}LinkedQueue;

LinkedQueue* createLinkedQueue();
int enqueueLQ(LinkedQueue *pQueue, QueueNode element);
QueueNode* dequeueLQ(LinkedQueue *pQueue);
QueueNode* peekLQ(LinkedQueue *pQueue);
void deleteLinkedQueue(LinkedQueue *pQueue);
int isLinkedQueueFull(LinkedQueue *pQueue);
int isLinkedQueueEmpty(LinkedQueue *pQueue);
void displayLinkedQueue(LinkedQueue *pQueue);

#endif
