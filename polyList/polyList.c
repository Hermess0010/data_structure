#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "polyList.h"

#define TRUE 1
#define FALSE 0

//---------------------------------다항식 리스트의 마자막 노드를 추가하는 함수---------------------------------//
int addPolyLast(LinkedList *pList, float coef, int degree){

    int ret = FALSE;

    if(pList != NULL){

        ListNode Node = {0, };

        Node.coef = coef;
        Node.degree = degree;

        int Length = getLinkedListLength(pList);
        ret = addLLElement(pList, Length, Node);

    }

    return ret;
}

//-------------------------------다항식 리스트 두개를 더하고 출력하는 함수--------------------------------------//
LinkedList* polyAdd(LinkedList *pListA, LinkedList *pListB){

    if(pListA != NULL){

        if(pListB != NULL){

            LinkedList *pListC = createLinkedList();
            ListNode *pNodeA = NULL, *pNodeB = NULL;

            pNodeA = &(pListA -> headerNode);
            pNodeB = &(pListB -> headerNode);

            while(pNodeA != NULL && pNodeB != NULL){

                pNodeA = pNodeA -> pLink;
                pNodeB = pNodeB -> pLink;

                int coefA = pNodeA -> coef;
                int coefB = pNodeB -> coef;

                if(pNodeA -> degree == pNodeB -> degree){

                    addPolyLast(pListC, coefA + coefB , pNodeA -> degree);

                    pNodeA = pNodeA -> pLink;
                    pNodeB = pNodeB -> pLink;
                }
                else if(pNodeA -> degree > pNodeB -> degree){

                    addPolyLast(pListC, coefA, pNodeA -> degree);

                    pNodeA = pNodeA -> pLink;
                }
                else if(pNodeA -> degree < pNodeB -> degree){

                    addPolyLast(pListC, coefB, pNodeB -> degree);

                    pNodeB = pNodeB -> pLink;
                }
            }

            while(pNodeA != NULL){

                addPolyLast(pListC, pNodeA -> coef, pNodeA -> degree);

                pNodeA = pNodeA -> pLink;
            }

            while(pNodeB != NULL){

                addPolyLast(pListC, pNodeB -> coef, pNodeB -> degree);

                pNodeB = pNodeB -> pLink;
            }

            return pListC;
        }
        else{

            printf("오류, NULL다항식이 전달되었습니다\n");
            return NULL;
        }
    }
    else{

            printf("오류, NULL다항식이 전달되었습니다\n");
            return NULL;
        }
}

void displayPolyList(LinkedList *pList){

    if(pList != NULL){

        ListNode *pNode = NULL;
        pNode = &(pList -> headerNode);

        for(int i= 0; i < pList -> currentElementCount; i++){

            pNode = pNode -> pLink;
            printf("%4.1fx^%d", pNode -> coef, pNode -> degree);
            printf(" + ");
        }
    }else{

            printf("오류, NULL다항식이 전달되었습니다\n");
        }
}

LinkedList* polySub(LinkedList *pListA, LinkedList *pListB){

    if(pListA != NULL){

        if(pListB != NULL){

            LinkedList *pListC = createLinkedList();
            ListNode *pNodeA = NULL, *pNodeB = NULL;

            pNodeA = &(pListA -> headerNode);
            pNodeB = &(pListB -> headerNode);

            while(pNodeA != NULL && pNodeB != NULL){

                pNodeA = pNodeA -> pLink;
                pNodeB = pNodeB -> pLink;

                int coefA = pNodeA -> coef;
                int coefB = pNodeB -> coef;

                if(pNodeA -> degree == pNodeB -> degree){

                    addPolyLast(pListC, coefA - coefB , pNodeA -> degree);

                    pNodeA = pNodeA -> pLink;
                    pNodeB = pNodeB -> pLink;
                }
                else if(pNodeA -> degree > pNodeB -> degree){

                    addPolyLast(pListC, coefA, pNodeA -> degree);

                    pNodeA = pNodeA -> pLink;
                }
                else if(pNodeA -> degree < pNodeB -> degree){

                    addPolyLast(pListC, coefB, pNodeB -> degree);

                    pNodeB = pNodeB -> pLink;
                }
            }

            while(pNodeA != NULL){

                addPolyLast(pListC, pNodeA -> coef, pNodeA -> degree);

                pNodeA = pNodeA -> pLink;
            }

            while(pNodeB != NULL){

                addPolyLast(pListC, pNodeB -> coef, pNodeB -> degree);

                pNodeB = pNodeB -> pLink;
            }

            return pListC;
        }
        else{

            printf("오류, NULL다항식이 전달되었습니다\n");
            return NULL;
        }
    }
    else{

            printf("오류, NULL다항식이 전달되었습니다\n");
            return NULL;
        }
}
