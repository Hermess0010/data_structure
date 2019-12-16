#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simdef.h"
#include "simLinkedQueue.h"
#include "simutil.h"

#define TRUE 1
#define FALSE 0

int main(){
    
    int currentTime = 0;
    int endTime = 10;
    int serviceUserCount = 0;
    int totalWaitTime = 0;

    LinkedQueue *pArrivalQueue = NULL, *pWaitQueue = NULL;
    QueueNode *pServiceNode1 = NULL;

    pArrivalQueue = createLinkedQueue();
    pWaitQueue = createLinkedQueue();
    if(pArrivalQueue != NULL && pWaitQueue == NULL){

        printf("오류, createLinkedQueue()\n");
        return FALSE;
    }

    insertCustomer(0, 3, pArrivalQueue);
    insertCustomer(2, 2, pArrivalQueue);
    insertCustomer(4, 1, pArrivalQueue);
    insertCustomer(6, 1, pArrivalQueue);
    insertCustomer(8, 3, pArrivalQueue);

    for(currentTime = 0; currentTime < endTime; currentTime++){

        processArrival(currentTime, pArrivalQueue, pWaitQueue);

        //서비스 종료처리
        if(pServiceNode1 != NULL){
            pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, 
                &serviceUserCount, &totalWaitTime);
        }

        //서비스 시작
        if(pServiceNode1 == NULL){

            pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
        }

        //대기큐 상태 출력
        printWaitQueueStatus(currentTime, pWaitQueue);
    }

    //최종 결과물 출력
    printReport(pWaitQueue, serviceUserCount, totalWaitTime);

    //메모리헤제
    if(pServiceNode1 != NULL){
        free(pServiceNode1);
    }
    
    deleteLinkedQueue(pArrivalQueue);
    deleteLinkedQueue(pWaitQueue);

    return 0;


}