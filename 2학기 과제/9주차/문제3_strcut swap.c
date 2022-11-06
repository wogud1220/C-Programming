#include <stdio.h>


typedef struct point {
	int xpos;
	int ypos;
}POINT;

void swap(POINT* pos1, POINT* pos2) {
	POINT temp;
	temp = *pos1;
	*pos1 = *pos2;
	*pos2 = temp;

}


int main() {
	POINT pos1 = { 2,4 };
	POINT pos2 = { 5,7 };

	
	swap(&pos1, &pos2);
	printf("바뀐 pos1의 값%d %d\n", pos1.xpos, pos1.ypos);
	printf("바뀐 pos2의 값%d %d\n", pos2.xpos, pos2.ypos);

}