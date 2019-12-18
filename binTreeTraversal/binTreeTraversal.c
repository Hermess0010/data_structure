#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"
#include "binTreeLinkedQueue.h"
#include "binTreeLinkedStack.h"
#include "binTreeTraversal.h"

//-----------------------------------------이진 트리 노드를 스택에 푸쉬하는 함수----------------------------------//
int pushLSBinTreeNode(LinkedStack *pStack, BinTreeNode *pNode){

    StackNode node = {0, };

    node.data = pNode;
    node.pLink = NULL;

    return PushLS(pStack, node);

}

//-------------------------------------이진 트리 노드를 큐에 인큐 하는 함수--------------------------------------//
int enqueueLQBinTreeNode(LinkedQueue *pQueue, BinTreeNode *pNode){

    QueueNode node = {0, };

    node.data = pNode;
    node.pLink = NULL;

    return enqueueLQ(pQueue, node);
}

//-----------------------------------이 트리를 전위 순회 하는 함수----------------------------------------------//
void preorderTraversalBinTree(BinTree *pBinTree){

    if (pBinTree != NULL)
    {

        LinkedStack *pStack = NULL;

        pStack = createLinkedStack();

        if (pStack != NULL)
        {

            BinTreeNode *pLeftChild = NULL;
            BinTreeNode *pRightChild = NULL;
            BinTreeNode *pNode = NULL;

            pushLSBinTreeNode(pStack, pBinTree->pRootNode);

            while (pStack->currentElementCount > 0)
            {

                pLeftChild = pStack -> pTopElement -> data -> pRootNode -> pLeftChild;
                pRightChild = pStack -> pTopElement -> data -> pRootNode -> pRightChild;

                if (pLeftChild != NULL && pLeftChild->visited != 1)
                {

                    printf("%c", pBinTree -> pRootNode -> data);
                    pLeftChild->visited = 1;
                    pushLSBinTreeNode(pStack, pLeftChild);
                    continue;
                }
                else if (pRightChild != NULL && pRightChild -> visited != 1)
                {

                    printf("%c", pRightChild->data);
                    pushLSBinTreeNode(pStack, pRightChild);
                    continue;
                }
                else
                {

                    pNode = popLs(pStack);
                    continue;
                }
            }
        DeleteLinkedStack(pStack);
        free(pLeftChild);
        free(pRightChild);
        free(pNode);
        }
    }
    else
    {

        printf("오류, 유효하지않은 이진트리\n");
    }
}

//--------------------------------------------이진 트리 반복 중위 순회-----------------------------------------//
void inorderTraversalBinTree(BinTree *pBinTree){

    if(pBinTree != NULL){

        LinkedStack *pStack = NULL;
        
        pStack = createLinkedStack();

        if(pStack != NULL){

            BinTreeNode *pNode = NULL;
            BinTreeNode *pLeftChild = NULL;
            BinTreeNode *pRightChild = NULL;

            pushLSBinTreeNode(pStack, pBinTree -> pRootNode);

            while(pStack -> currentElementCount > 0){

                pLeftChild = pStack -> pTopElement -> data -> pRootNode -> pLeftChild;
                pRightChild = pStack -> pTopElement -> data -> pRootNode -> pRightChild;

                pNode = pStack -> pTopElement -> data -> pRootNode;

                if(pLeftChild != NULL && pLeftChild -> visited != 1){

                    pushLSBinTreeNode(pStack, pLeftChild);
                    continue;
                }
                else if(pRightChild != NULL && pRightChild -> visited != 1){

                    printf("%c", pNode -> data);
                    pNode -> visited = 1;

                    pushLSBinTreeNode(pStack, pRightChild);
                    continue;

                }
                else if(pNode -> visited == 1){

                    pNode = popLs(pStack);
                    continue;
                }
                else{

                    pNode = popLS(pStack);
                    printf("%c", pNode -> data);
                    pNode -> visited = 1;
                    continue;
                }
            }
        DeleteLinkedStack(pStack);
        free(pLeftChild);
        free(pRightChild);
        free(pNode);
            
        }
    }
}

//------------------------------------------이진 트리 반복 후위 순회 함수--------------------------------------//
void postorderTraversalBinTree(BinTree *pBinTree){

    if(pBinTree != NULL){

        LinkedStack *pStack = NULL;
        BinTreeNode *pLeftChild = NULL;
        BinTreeNode *pRightChild = NULL;
        BinTreeNode *pNode = NULL;

        pStack = createLinkedStack();

        if(pStack != NULL){

            pushLSBinTreeNode(pStack, pBinTree -> pRootNode);

            while(pStack -> currentElementCount > 0){

                pLeftChild = getLeftChildNodeBT(pStack -> pTopElement -> data -> pRootNode);
                pRightChild = getRightChildNodeBT(pStack -> pTopElement -> data -> pRootNode);

                if(pLeftChild != NULL && pLeftChild -> visited != 1){

                    pushLSBinTreeNode(pStack, pLeftChild);
                    continue;
                }
                else if(pRightChild != NULL && pRightChild -> visited != 1){

                    pushLSBinTreeNode(pStack, pRightChild);
                    continue;
                    
                }
                else {
                    pNode = popLs(pStack);
                    printf("%c", pNode -> data);
                    pNode -> visited = 1;
                    continue;

                }

                
            }
            DeleteLinkedStack(pStack);
            free(pLeftChild);
            free(pRightChild);
            free(pNode);
        }
    }
}

//------------------------------------------이진 트리 반복 레벨 순회 함수-----------------------------------------//
void levelOrederTraversalBinTree(BinTree *pBinTree){

    if(pBinTree != NULL){

        LinkedQueue *pQueue = NULL;

        pQueue = createLinkedQueue();

        if(pQueue != NULL){

            BinTreeNode *pNode = NULL;

            if(pBinTree -> pRootNode == NULL){

                return;
            }

            enqueueLQBinTreeNode(pQueue, pBinTree -> pRootNode);

            while(pQueue -> currentElementCount > 0){

                pNode = dequeueLQ(pQueue);

                if(pNode -> pLeftChild != NULL){

                    enqueueLQBinTreeNode(pQueue, pNode -> pLeftChild);
                }
                if(pNode -> pRightChild != NULL){

                    enqueueLQBinTreeNode(pQueue, pNode -> pRightChild);
                }

                printf("%c", pNode -> data);
                pNode -> visited = 1;

            }

            deleteLinkedQueue(pQueue);
            free(pNode);
        }
    }
}