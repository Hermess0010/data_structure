#ifndef _BIN_TREE_OPERATION_
#define _BIN_TREE_OPERATION_

#include "binTree.h"

BinTree* copyBinTree(BinTree *pSource);
BinTreeNode* copyBinTreeNode(BinTreeNode *pSourceNode);
int equalBinTree(BinTree *pFirst, BinTree *pSecond);
int equalBinTreeNode(BinTreeNode *pFirst, BinTreeNode *pSecond);
int getNodeCountBT(BinTree *pSource);
int getNodeCountBTNode(BinTreeNode *pSource);
int getLeafNodeCountBT(BinTree *pSource);
int getLeafNodeCountBTNode(BinTreeNode *pSource);
int getHeightBT(BinTree *pSource);
int getHeightBTNode(BinTreeNode *pSource);
void displayBinTree(BinTree *pBinTree);
void displayBinTreeNode(BinTreeNode *pNode, int level, char type);

#endif
