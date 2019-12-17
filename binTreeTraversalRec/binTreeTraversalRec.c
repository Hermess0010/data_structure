#include <stdio.h>
#include <stdlib.h>

#include "binTree.h"
#include "binTreeTraversalRec.h"

//-----------------------------------------------이진 탐색 전위 순회 함수-----------------------------------------//
void preorederTraversalRecrusiveBinTree(Bintree* pBinTree){

    if(pBinTree != NULL){

        preorederTraversalRecrusiveBinTreeNode(pBinTree -> pRootNode);
    }
}

void preorederTraversalRecrusiveBinTree(BinTreeNode* pNode){

    if(pNode != NULL){

        printf("%c", pNode -> data);
        preorederTraversalRecrusiveBinTreeNode(pNode -> pLeftChild);
        preorederTraversalRecrusiveBinTreeNode(pNode -> pRightChild);
    }
}

//---------------------------------------------이진 탐색 중위 순회 함수------------------------------------------------//
void inorederTraversalRecrusiveBinTree(BinTree* pBinTree){

    if(pBinTree != NULL){

        inorederTraversalRecrusiveBinTreeNode(pBinTree -> pRootNode);
    }
}

void inorederTraversalRecrusiveBinTreeNode(binTreeNode* pNode){

    if(pNode != NULL){

        inorederTraversalRecrusiveBinTreeNode(pNode -> pLeftChild);
        printf("%c", pNode -> data);
        inorederTraversalRecrusiveBinTreeNode(pNode -> pRightChild);
        
    }
}

//--------------------------------------------이진 탐색 후위 순회 함수------------------------------------------------//
void postorederTraversalRecrusiveBinTree(BinTree* pBinTree){

    if(pBinTree != NULL){

        postorederTraversalRecrusiveBinTreeNode(pBinTree -> pRootNode);
    }
}

void postorederTraversalRecrusiveBinTreeNode(BinTreeNode* pNode){

    if(pNode != NULL){

        postorederTraversalRecrusiveBinTreeNode(pNode -> pLeftChild);
        postorederTraversalRecrusiveBinTreeNode(pNode -> pRightChild);
        printf("%c", pNode -> data);

    }
}