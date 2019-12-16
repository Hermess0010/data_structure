#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simdef.h"
#include "simLinkedQueue.h"
#include "simutil.h"

#define TRUE 1
#define FALSE 0

//------------------------------------------고객 도착 큐에 추가 함수----------------------------------------//
void insertCustomer(int arrivalTime, int servicerTime, LinkedQueue *pArrivalQueue){

    if(pArrivalQueue != NULL){

        QueueNode Node = {0, };

        Node.data.status = arrival;
        Node.data.arrivalTime = arrivalTime;
        Node.data.serviceTime = servicerTime;
        Node.data.startTime = 0;
        Node.data.endTime = 0;

        enqueueLQ(pArrivalQueue, Node);
    }

}

//----------------------------------------고객 도착 처리 함수--------------------------------------------//
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue){

    if(currentTime >= 0 && currentTime <= 10){

        if(pArrivalQueue != NULL){

            if(pWaitQueue != NULL){

                QueueNode *pNode = NULL;

                while(isLinkedQueueEmpty(pArrivalQueue) == FALSE){

                    if(currentTime == pArrivalQueue -> pFrontNode -> data.arrivalTime){

                    pNode = dequeueLQ(pArrivalQueue);
                    enqueueLQ(pWaitQueue, *pNode);
                    printSimCustomer(currentTime, pNode -> data);

                    free(pNode);

                    free(pNode);
                    }
                    else{

                        free(pNode);
                        break;
                    }

                }
                
            }
        }
    }
}

//-----------------------------------------서비스 시작 처리 함수------------------------------------------//
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue){

    if(currentTime >= 0 && currentTime <= 10){

        if(pWaitQueue != NULL){

            QueueNode *pNode = NULL;

            if(pWaitQueue -> pFrontNode -> data.serviceTime == currentTime){

                if(isLinkedQueueEmpty(pWaitQueue) == FALSE){

                    pNode = dequeueLQ(pWaitQueue);

                    if(pNode != NULL){

                        pNode -> data.status = start;
                        pNode -> data.startTime = currentTime;
                        printSimCustomer(currentTime, pNode -> data);

                        free(pNode);

                        return pNode;
                    }
                }
                

                
            }
        }
    }

    return NULL;
}

//--------------------------------------서비스 종료 처리 함수------------------------------------------------//
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pNode, int *pServiceUserCount, int *pTotalWaitTime){

    if(currentTime >= 0 && currentTime <= 10){

        if(pNode != NULL){

            int endTime = 0;
            int waitTime = 0;

            endTime = pNode -> data.startTime + pNode -> data.serviceTime;

            if(endTime <= currentTime){

                waitTime = pNode -> data.startTime - pNode -> data.arrivalTime;

                (*pServiceUserCount)++;
                (*pTotalWaitTime) += waitTime;

                pNode -> data.status = end;
                pNode -> data.endTime = currentTime;
                printSimCustomer(currentTime, pNode -> data);

                free(pNode);

                return NULL;
            }
        }
    }
    return NULL;
}

//-------------------------------------고객들의 상태를 출력해주는 함수----------------------------------------//
void printSimCustomer(int currentTime, SimCustomer customer){

    printf("[%d], ", currentTime);

    switch(customer.status){

        case arrival:
            printf("고객도착\n");
            break;

        case start:
            printf("서비스 시작\n");
            printf("도착 - %d, 대기시간 - %d\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));
            break;

        case end:
            printf("서비스 종료\n");
            printf("도착 - %d, 시작 - %d, 대기시간 - %d, 서비스시간 - %d\n", customer.arrivalTime, customer.startTime, (
                customer.startTime - customer.arrivalTime), (customer.endTime - customer.startTime));
            break;
    }
}

//------------------------------------------대기열 출력 함수-------------------------------------//
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue){

    printf("[%d], 현재 고객 대기수 : %d\n", currentTime, pWaitQueue -> currentElementCount);

}

//------------------------------------------최종결과 보고서 출력 함수------------------------------//
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime){

    printf("REPORT\n");
    printf("서비스 고객 수 : %d\n", serviceUserCount);
    if(serviceUserCount > 0){

        printf("평균 대기 시간 : %f\n", ((float)totalWaitTime) / (float)serviceUserCount);
    }
    printf("현재 대기열의 고객수 : %d\n", pWaitQueue -> currentElementCount);
}