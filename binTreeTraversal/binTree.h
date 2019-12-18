#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef struct BinTreeNode{

    char data;
    int visited;

    BinTreeNode* pLeftChild;
    BinTreeNode* pRightChild;
}BinTreeNode;

typedef struct BinTree{

    BinTreeNode* pRootNode;
}BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);
BinTreeNode* getRootNodeBT(BinTree* pBinTree);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParenNode, BinTreeNode element);
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void deleteBintree(BinTree* pBinTree);
void deleteBinTreeNode(BinTreeNode* pNode);

#endif