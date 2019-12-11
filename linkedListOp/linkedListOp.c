#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../linkeList/linkedList.h"
#include "linkedListOp.h"

void iterateLinkedList (LinkedList *pList){

    if(pList != NULL){

        ListNode * pNode = NULL;
        pNode = &(pList -> headerNode);
        int count = 0;

        for(int i = 0; i < pList -> currentElementCount; i++){

            pritnf("[%d] : %d\n", i, pNode -> data);

            pNode = pNode -> pLink;

            count++;
        }

        printf("노드 개수 : %d\n", count);
    }
    else{

        printf("공백 리스트입니다.\n");
    }
}

void concatLinkedList(LinkedList *pListA, LinkedList *pListB){

    ListNode *pLastNodeA = NULL, *pFirsNodeB = NULL;

    pLastNodeA = &(pListA -> headerNode);

    for(int i = 0; i < pListA -> currentElementCount; i++){

        pLastNodeA = pLastNodeA -> pLink;
    }

    pListA -> currentElementCount += pListB -> currentElementCount;

    pFirsNodeB = &(pListB -> headerNode.pLink);

    pLastNodeA -> pLink = pFirsNodeB;
    pListB -> headerNode.pLink = NULL;

    pListB -> currentElementCount = 0;
    
}

