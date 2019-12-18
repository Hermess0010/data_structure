#include <stdio.h>
#include <stdlib.h>

#include "binTree.h"

#define TRUE 1
#define FALSE 0

//-----------------------------------------------이진 트리 만드는 함수--------------------------------------//
BinTree* makeBinTree(BinTreeNode rootNode){

    BinTree* pBinTree = NULL;
    BinTreeNode* pNode = NULL;

    pBinTree = (BinTree*)malloc(sizeof(BinTree));

    if(pBinTree != NULL){

        pNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));

        if(pNode != NULL){

            pNode -> data = rootNode.data;

            pNode -> pRightChild = NULL;
            pNode -> pLeftChild = NULL;

            pBinTree -> pRootNode = pNode;

            return pBinTree;

        }
        else{

            printf("오류, 메모리 할당\n");
            return NULL;
        }
    }
    else{

            printf("오류, 메모리 할당\n");
            return NULL;
        }
}

//--------------------------------------------왼쪽 자식노드 추가하는 함수-----------------------------------------//
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){

    if(pParentNode != NULL){

        if(pParentNode -> pLeftChild == NULL){

            BinTreeNode* pNode = NULL;

            pNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));

            if(pNode != NULL){

                pNode -> data = element.data;

                pNode -> pLeftChild = NULL;
                pNode -> pRightChild = NULL;

                pParentNode -> pLeftChild = pNode;

                return pNode;
            }
            else{

            printf("오류, 메모리 할당\n");
            return NULL;
            }
        }
        else{

            printf("오류, 이미 노드가 존재합니다\n");
            return NULL;
        }
    }
    else{

            printf("오류, 유효하지않은 부모 노드\n");
            return NULL;
        }
}

//-------------------------------------------오른쪽 자식 노드 추가하는 함수---------------------------------//
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element){

    if(pParentNode != NULL){

        if(pParentNode -> pRightChild == NULL){

            BinTreeNode* pNode = NULL;

            pNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));

            if(pNode != NULL){

                pNode -> data = element.data;

                pNode -> pLeftChild = NULL;
                pNode -> pRightChild = NULL;

                pParentNode -> pRightChild = pNode;

                return pNode;
            }
            else{

            printf("오류, 메모리 할당\n");
            return NULL;
            }
        }
        else{

            printf("오류, 이미 노드가 존재합니다\n");
            return NULL;
        }
    }
    else{

            printf("오류, 유효하지않은 부모 노드\n");
            return NULL;
        }
}

//--------------------------------------------------루트 노드 반환 함수---------------------------------------------//
BinTreeNode* getRootNodeBT(BinTree* pBinTree){

    if(pBinTree != NULL){

        BinTreeNode* pRootNode = NULL;

        pRootNode = pBinTree -> pRootNode;

        return pRootNode; 
    }
}

//----------------------------------------------왼쪽 자식 노드 반환 함수-----------------------------------------//
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode){

    if(pNode != NULL){

        return pNode -> pLeftChild;
    }
    else{

            printf("오류, 유효하지않은 부모 노드\n");
            return NULL;
        }
}

//------------------------------------------------오른쪽 자식 노드 반환 함수-----------------------------------//
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode){

    if(pNode != NULL){

        return pNode -> pRightChild;
    }
    else{

            printf("오류, 유효하지않은 부모 노드\n");
            return NULL;
        }
}

//------------------------------------------------이진 트리 삭제 함수--------------------------------------------//
void deleteBinTree(BinTree* pBinTree){

    if(pBinTree != NULL){

        deleteBinTreeNode(pBinTree -> pRootNode);
        free(pBinTree);
    }
}

//----------------------------------------------이진 트리 노드 삭제 함수-----------------------------------------//
void deleteBinTreeNode(BinTreeNode* pNode){

    if(pNode != NULL){

        deleteBintreeNode(pNode -> pLeftChild);
        deleteBintreeNode(pNode -> pRightChild);
        free(pNode);
    }
}

