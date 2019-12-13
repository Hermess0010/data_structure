#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "mapdef.h"
#include "mapLinkedStack.h"
#include "mapUtil.h"

#define TRUE 1
#define FALSE 0

int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {

    {0, -1},            //위쪽으로이동
    {1, 0},             //오른쪽으로이동
    {0, 1},            //밑으로 이동
    {-1, 0}           //왼쪽으로이동
};  //direction_offset값이 안먹어서 직접 써줌

//---------------------------------맵 위치값을 스택에 푸쉬하는 함수--------------------------------------------//
int PushLSMapPosition(LinkedStack *pStack, MapPosition data){

    if(pStack != NULL){

        StackNode Node = {0, };

        Node.data.x = data.x;
        Node.data.y = data.y;
        Node.data.direction = data.direction;

        return PushLS(pStack, Node);
    }
}

//----------------------------------------경로를 찾는 함수-------------------------------------------------------//
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack){

    if(pStack != NULL){

        MapPosition NewPosition = startPos;
        PushLSMapPosition(pStack, NewPosition);
        StackNode *Node;

        int x = NewPosition.x;
        int y = NewPosition.y;

        NewPosition.direction = 0;

        mazeArray[NewPosition.x][NewPosition.y] = 2;

        while(NewPosition.x != endPos.x && NewPosition.y != endPos.y){

             x = NewPosition.x + DIRECTION_OFFSETS[NewPosition.direction][0];
             y = NewPosition.y + DIRECTION_OFFSETS[NewPosition.direction][1];

            if(x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT){
                
                if(mazeArray[x][y] == 0){

                    NewPosition.x = x;
                    NewPosition.y = y;

                    mazeArray[NewPosition.x][NewPosition.y] = VISIT;

                    NewPosition.direction = 0;

                    pushLSMapPosition(pStack, NewPosition);
                }
                else{
                    
                    NewPosition.direction++;
                }
                if(NewPosition.direction == 5){
                
                Node = popLS(pStack);

                NewPosition.x = Node -> data.x;
                NewPosition.y = Node -> data.y;

                NewPosition.direction = 0;

                free(Node);
                }
                if(1 == isLinkedStackEmpty(pStack)){

                printf("출구가 없습니다\n");
                return 0;
                }

            }
            else{

                NewPosition.direction++;
            }

        }
    }
}

//------------------------------------------------------------찾은 경로를 보여주는 함수---------------------------------------//
void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]){

    StackNode *pNode = NULL;
    int x = 0, y = 0;

    if(pStack != NULL){

        while(FALSE == isLinkedStackEmpty(pStack)){

            pNode = popLS(pStack);

            x = pNode -> data.x;
            y = pNode -> data.y;

            printf("(%d , %d)", x, y);
            printf(" <- ");

            free(pNode);

        }

        printMaze(mazeArray);

    }
}

//--------------------------------------------------직접 미로를 출력해주는 함수----------------------------------------------------//
void printMaze(int mazeArray[HEIGHT][WIDTH]){

    for(int i = 0; i < HEIGHT; i++){

        for(int k = 0; k < WIDTH; k++){

            if(mazeArray[i][k] == WALL){

                printf("*");
            }
            else if(mazeArray[i][k] == VISIT){

                printf(".");
            }
            else{

                printf(" ");
            }

            printf("\n");
        }
    }
}