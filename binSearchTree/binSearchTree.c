#include <stdio.h>
#include <stdlib.h>
#include "binSearchTree.h"

#define TRUE 1
#define FALSE 0

//---------------------------------이진 탐색 트리 만드는 함수--------------------------------------//
BinSearchTree* createBinSearchTree(){

    BinSearchTree *pTree = NULL;

    pTree = (BinSearchTree *)malloc(sizeof(BinSearchTree));

    if(pTree != NULL){

        pTree -> pRootNode = NULL;
    }
    else{

        printf("오류, 메모리할당");
    }
}

//-----------------------------------------이진 탐색 트리에서의 삽입 연산 함수-------------------------------//
int insertElementBST(BinSearchTree* pBinSearchTree, BinSearchTreeNode element){

    int ret = FALSE;

    if(pBinSearchTree != NULL){

        BinSearchTreeNode *pNewNode = NULL, *pNode = NULL, *pParentNode = NULL;
        pNode = pBinSearchTree -> pRootNode;
        
        pNewNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));

        if(pNewNode != NULL){

            pNewNode -> key = element.key;
            pNewNode -> value = element.value;
            pNewNode -> pLeftChild = NULL;
            pNewNode -> pRightChild = NULL;

            while(pNode != NULL){

                if(element.key > pNode -> key){

                    pParentNode = pNode;
                    pNode = pNode -> pRightChild;
                }
                else if(element.key < pNode -> key){

                    pParentNode = pNode;
                    pNode = pNode -> pLeftChild;
                }
                else{

                    printf("오류, 중복된 노드값이 있습니다.\n");
                    return ret;
                }
            }

            if(element.key > pParentNode -> key){

                pParentNode -> pRightChild = pNewNode;
                
                ret = TRUE;
                return ret;
            }
            else{

                pParentNode -> pLeftChild = pNewNode;

                ret = TRUE;
                return ret;
            }
        }
        else{

        printf("오류, 메모리할당");
        return ret;
        }
    }
    else{

        printf("오류, 메모리할당");
        return ret;
    }
}

//-------------------------------------------이진 탐색 트리 삭제 연산-------------------------------------------//
int deleteElementBST(BinSearchTree *pBinSearchTree, int key){

    int ret = FALSE;

    if(pBinSearchTree != NULL){

        BinSearchTreeNode *pNode = NULL , *pParentNode = NULL, *pMiddleNode = NULL;
        BinSearchTreeNode *pMiddleParentNode = NULL;

        pNode = pBinSearchTree -> pRootNode;

        while(pNode -> key != key){

            if(key > pNode -> key){

                pParentNode = pNode;
                pNode = pNode -> pRightChild;
            }
            else if(key < pNode -> key){

                pParentNode = pNode;
                pNode = pNode -> pLeftChild;
            }
            else if(pNode == NULL){

                printf("찾는 키에대한 노드가 없습니다\n");
                return ret;
            }
        }

        if(pNode -> pLeftChild == NULL && pNode -> pRightChild == NULL){        //자식노드가 없을때

            if(key > pParentNode -> key){

                pParentNode -> pRightChild = NULL;
                free(pNode);
            }
            else{

                pParentNode -> pLeftChild = NULL;
                free(pNode);
            }

            ret = TRUE;
            return ret;
        }
        else if((pNode -> pLeftChild != NULL && pNode -> pRightChild == NULL) ||
            (pNode -> pLeftChild == NULL && pNode -> pRightChild != NULL)){         //자식노드가  1개 있을때

                if(pNode -> pLeftChild != NULL && pNode -> pRightChild == NULL){

                    if(key > pParentNode -> key){

                        pParentNode -> pRightChild = pNode -> pLeftChild;
                        free(pNode);
                    }
                    else if(key < pParentNode -> key){

                        pParentNode -> pLeftChild = pNode -> pLeftChild;
                        free(pNode);
                    }
                }
                else{

                    if(key > pParentNode -> key){

                        pParentNode -> pRightChild = pNode -> pRightChild;
                        free(pNode);
                    }
                    else if(key < pParentNode -> key){

                        pParentNode -> pLeftChild = pNode -> pRightChild;
                        free(pNode);
                    }
                }

                ret = TRUE;
                return ret;
                
        }
        else{                                                                           //자식노드가 2개있을떄

            pMiddleNode = pNode;

            while(pMiddleNode -> pRightChild != NULL){

                pMiddleParentNode = pMiddleNode;
                pMiddleNode = pMiddleNode -> pRightChild;
            }

            pMiddleParentNode -> pRightChild = NULL;
            pMiddleNode -> pLeftChild = pNode -> pLeftChild;
            pMiddleNode -> pRightChild = pNode -> pRightChild;
            
            if(key < pParentNode -> key){

                pParentNode -> pLeftChild = pMiddleNode;
                free(pNode);
            }
            else if(key > pParentNode -> key){

                pParentNode -> pRightChild = pMiddleNode;
                free(pNode);
            }

            ret = TRUE;
            return ret;

        }


    }
}

//--------------------------------------이진 탐색 트리 검색 연산 함수-----------------------------------------------//
BinSearchTreeNode* searchBTS(BinSearchTree *pTree, int key){

    if(pTree != NULL){

        BinSearchTreeNode *pNode = NULL;

        pNode = pTree -> pRootNode;

        while(key != pNode -> key){

            if(key > pNode -> key){

                pNode = pNode -> pRightChild;
                continue;
            }
            else if(key < pNode -> key){

                pNode = pNode -> pLeftChild;
                continue;
            }
            else if(pNode == NULL){

                printf("찾는 노드값이 없습니다");
                return NULL;
            }
        }

        return pNode;
    }
}

//------------------------------------이진 탐색 트리 삭제 함수------------------------------------//
void deleteBinSearchTree(BinSearchTree* pBinSearchTree){

    if(pBinSearchTree != NULL){

        deleteBinSearchTreeInternal(pBinSearchTree -> pRootNode);
        free(pBinSearchTree);
    }
}

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode){

    if(pTreeNode != NULL){

        deleteBinSearchTreeInternal(pTreeNode -> pLeftChild);
        deleteBinSearchTreeInternal(pTreeNode -> pRightChild);
        free(pTreeNode);
    }
}