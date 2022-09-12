#include <stdio.h>
int main() {
	int i = 0;
	double arrd[4] = { 12.4, 23.1, 15.7, 31.2 };
	double* pb = arrd;
	for (i = 0; i < 4; i++) {
		printf("%lf\n", pb[i]); 
	}
	return 0;
 
}