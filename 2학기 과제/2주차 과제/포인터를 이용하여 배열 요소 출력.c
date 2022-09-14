#include <stdio.h>
int main() {
	int i = 0;
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };	//arrd의 배열에 4개의 실수 저장
	double* pb = arrd;
	for (i = 0; i < 4; i++) {
		printf("%lf\n", pb[i]);
	}
	return 0;
 
}
