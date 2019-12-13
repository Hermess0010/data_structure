#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {

    {0, -1},            //위쪽으로이동
    {1, 0},             //오른쪽으로이동
    {0, 1},            //밑으로 이동
    {-1, 0}           //왼쪽으로이동
};

enum PosStatus { NOT_VISIT = 0, WALL = 1, VISIT = 2};

typedef struct MapPosition{

    int x;
    int y;
    int direction;
}MapPosition;

int mazeArray[HEIGHT][WIDTH] = {
    {0, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1},
    {1, 0, 0 ,0 ,0 ,0 ,0 ,0},
    {1, 1, 1, 1, 1, 1, 1, 0}
};
#endif