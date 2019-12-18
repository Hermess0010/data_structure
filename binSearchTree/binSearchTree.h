#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

typedef struct BinSearchTreeNode{

    int key;
    char value;

    BinSearchTreeNode *pLeftChild;
    BinSearchTreeNode *pRightChild;

}BinSearchTreeNode;

typedef struct BinSearchTree{

    BinSearchTreeNode *pRootNode;
}BinSearchTree;

BinSearchTree* createBinsearchTree();
int isertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element);
int deleteElementBST(BinSearchTree *pBinSearchTree, int key);
BinSearchTreeNode* searchRecuriveBST(BinSearchTree *pBinSearchTree, int key);
BinSearchTreeNode* searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key);
BinSearchTreeNode* searchBST(BinSearchTree* pBinsearchTree, int key);
void deleteBinSearchTree(BinSearchTree* pBinSearchTree);
void deleteBinSearchTreeInternal(BinSearchTreeNode* pTreeNode);

#endif
