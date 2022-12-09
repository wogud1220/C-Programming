#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE(X)   X*X
#define SQUARE_1(X)	(X)*(X)
#define SQUARE_2(X) (X*X)


int main() {
	printf("%d\n", SQUARE(2));	// 정상적으로 4 출력.

	printf("%d\n", SQUARE_1(3 + 2));	//25 출력

	printf("%d\n",120/SQUARE(2));	//30이 나와야하는데 120 출력	== 120/2*2가 실행됨

	printf("%d\n", 120 / SQUARE_2(2));	//괄호를 한번 더 해서 정상적인 값 나옴.  == 120/(2*2)가 실행됨


}