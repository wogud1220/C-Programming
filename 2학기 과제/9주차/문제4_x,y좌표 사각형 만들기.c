#include <stdio.h>

typedef struct point {

    int xpos;

    int ypos;

} POINT;


void swap(POINT* pos1, POINT* pos2) {

     printf("넓이:%d", (pos2->xpos - pos1->xpos) * (pos2->ypos - pos1->ypos));
}

int main() {

    POINT pos1 = { 0,0 };
    POINT pos2 = { 100,100 };


    printf("좌하단:%d %d\n", pos1.xpos, pos1.ypos);
    printf("우상단:%d %d\n", pos2.xpos, pos2.ypos);
    printf("좌상단:%d %d\n", pos1.xpos, pos2.ypos);
    printf("우하단:%d %d\n", pos2.xpos, pos1.ypos);
    swap(&pos1, &pos2);
}