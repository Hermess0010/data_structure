#ifndef _SIM_UTIL_
#define _SIM_UTIL_
#include "simdef.h"
#include "simLinkedQueue.h"

//고객 도착 큐에 추가
void insertCustomer(int arrivalTime, int processtime, LinkedQueue *pQueue);

//고객 도착 처리
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

//서비스 시작처리
QueueNode* processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

//서비스 종료 처리
QueueNode* processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiveUserCount, int *pTotalWaitTime);

//고객의 상태를 출력
void printSimCustomer(int currentTime, SimCustomer customer);

//대기 열의 추렭
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

//최종 시뮬레이션 결과 출력
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime);

#endif