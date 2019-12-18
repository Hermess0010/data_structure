#include <stdio.h>
#include <stdlib.h>
#include "binTree.h"
#include "binTreeOp.h"

#define TRUE 1
#define FALSE 0

//--------------------------------------------이진트리 복사 함수----------------------------------------------//
BinTree* copyBinTree(BinTree* pSource){

    if(pSource != NULL){

        BinTree *pBinTree = NULL;

        pBinTree = (BinTree *)malloc(pBinTree);

        if(pBinTree != NULL){

            pBinTree -> pRootNode = copyBinTreeNode(pSource -> pRootNode);

            return pBinTree;
        }
        else{

            printf("오류, 메모리할당\n");
            return NULL;
        }
    }
}

BinTreeNode* copyBinTreeNode(BinTreeNode *pSourceNode){

    if(pSourceNode != NULL){

        BinTreeNode *pNode = NULL;

        pNode = (BinTreeNode *)malloc(sizeof(BinTreeNode));

        if(pNode != NULL){

            *pNode = *pSourceNode;

            pNode -> pRightChild = copyBinTreeNode(getRightChildNodeBT(pSourceNode));
            pNode -> pLeftChild = copyBinTreeNode(getLeftChildNodeBT(pSourceNode));
        }
        else{

            printf("오류, 메몸리할당\n");
        }
    }
    else{

        return NULL;
    }
}

//--------------------------------------------이진 트리 동일성 검사---------------------------------------------//
int equalBinTree(BinTree *pFirst, BinTree *pSecond){

    int ret = FALSE;

    if(pFirst == NULL && pSecond == NULL){

        ret = TRUE;
    }
    else if(pFirst != NULL && pSecond != NULL && 
        (equalBinTreeNode(pFirst -> pRootNode, pSecond -> pRootNode) == TRUE)){

            ret = TRUE;
        }

        return ret;
}

int equalBinTreeNode(BinTreeNode *pFirstNode, BinTreeNode *pSecondNode){

    int ret = FALSE;

    if(pFirstNode == NULL && pSecondNode == NULL){

        ret = TRUE;
        
        return ret;
    }
    
    if(equalBinTreeNode(pFirstNode -> pLeftChild, pSecondNode -> pLeftChild) == TRUE){

        if(equalBinTreeNode(pFirstNode -> pRightChild, pSecondNode -> pRightChild) == TRUE){

            if(pFirstNode -> data == pSecondNode -> data){

            ret = TRUE;

            return ret;
            }
        }

    }
}

//------------------------------------이진 트리 노드 개수 구하는 함수------------------------------------//
int getNodeCountBT(BinTree* pSource){

    int ret = 0;
    if(pSource != NULL){

        ret = getNodeCountBTNode(pSource -> pRootNode);

    }
        return ret;
}

int getNodeCountBTNode(BinTreeNode *pSourceNode){

    int ret = 0;
    if(pSourceNode != NULL){

        ret = getNodeCountBTNode(pSourceNode -> pRightChild) +
            getNodeCountBTNode(pSourceNode -> pLeftChild) + 1;

    }
    
    return ret;
}

//--------------------------------------------이진 트리 단말 노드 개수 구하기-------------------------------------//
int getLeafNodeCountBT(BinTree* pSource){

    int ret = 0;

    if(pSource != NULL){

        ret = getLeafNodeCountBTNode(pSource -> pRootNode);

    }
    
    return ret;
}

int getLeafNodeCountBTNode(BinTreeNode* pSourceNode){

    int ret = 0;

    if(pSourceNode != NULL){

        if(pSourceNode -> pLeftChild == NULL && pSourceNode -> pRightChild == NULL){

        return 1;
        }
    }
    else{

        ret = getLeafNodeCountBTNode(pSourceNode -> pLeftChild) +
            getLeafNodeCountBTNode(pSourceNode -> pRightChild);
    }

    return ret;
}

//---------------------------------------이진 트리 높이 구하는 함수------------------------------------------//
int getHeightBT(BinTree *pSource){

    int ret = 0;

    if(pSource != NULL){

        ret = getHeightNode(pSource -> pRootNode);
    }

    return ret;
}

int getHeightBTNode(BinTreeNode *pSourceNode){

    int ret = 0;
    int leftChildHeight = 0;
    int rightChildHeight = 0;

    leftChildHeight = getHeightBTNode(pSourceNode -> pLeftChild);
    rightChildHeight = getHeightBTNode(pSourceNode -> pRightChild);

    if(pSourceNode -> pLeftChild == NULL & pSourceNode -> pRightChild == NULL){

        return 1;
    }
    else if(leftChildHeight > rightChildHeight){

        ret = leftChildHeight + 1;

    }
    else if(leftChildHeight < rightChildHeight){

        ret = rightChildHeight + 1; 
    }
    else{

        ret = leftChildHeight + 1;
    }
    return ret;
}

//---------------------------------이진 트리 구조 및 내용 출력하기-------------------------------------------//
void displayBinTree(BinTree *pTree){

    if(pTree != NULL){

        displayBinTreeNode(pTree -> pRootNode, 0, 'O');
    }
    else{

        printf("트리가 NULL입니다.\n");
    }
}

void displayBinTreeNode(BinTreeNode *pNode, int level, char type){

    if(pNode != NULL){

        for(int i = 0; i < level; i++){
            printf("    ");
        }

        printf("-[%i, %c]%c\n", level, type, pNode -> data);

        displayBinTreeNode(pNode -> pLeftChild, level + 1, "L");
        displayBinTreeNode(pNode -> pRightChild, level + 1, "R");
    }
    else{

        printf("NULL\n");
    }
}