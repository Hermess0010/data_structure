#ifndef _STM_DEF_
#define _STM_DEF_

typedef enum SimStatus{ arrival, start, end } SimStatus;

typedef struct SimCustomer{
    
    SimStatus status;
    int arrivalTime;        //도착시간
    int serviceTime;        //서비스시간
    int startTime;          //시작시각
    int endTime;            //종료시각 = 시작 시각 + 서비스 시간
}SimCustomer;

#endif