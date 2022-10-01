#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int x, int y) {
	return x + y;
}
int subtract(int x, int y) {
	return x - y;
}
int multi(int x, int y) {
	return x * y;
}
int big(int x, int y) {
	if (x > y)
		return x;
	else
		return y;
}
int small(int x, int y) {
	if (x < y)
		return x;
	else
		return y;
}


int main() {
	int x, y, n;
	int(*fp)(int x, int y);

	printf("두 정수를 입력하세요\n");
	scanf("%d %d", &x, &y);
	printf("\n어떤 연산을 실행할까요?\n");
	start:
	printf("(1~5 중 선택. 0입력하면 종료) <== 반복 실행\n");
	printf("0: 종료\n1: +\n2: -\n3: *\n4: 최댓값\n5: 최솟값\n\n");
	scanf("%d", &n);
	if (n == 0) {
		printf("종료하겠습니다.");
		return 0;
	}
	else if (n == 1) {
		fp = sum;
		printf("%d\n", fp(x, y));
	}
	else if (n == 2) {
		fp = subtract;
		printf("%d\n", fp(x, y));
	}
	else if (n == 3) {
		fp = multi;
		printf("%d\n", fp(x, y));
	}
	else if (n == 4) {
		fp = big;
		printf("%d\n", fp(x, y));
	}
	else if (n == 5) {
		fp = small;
		printf("%d\n", fp(x, y));
	}
	else
		printf("0~5중 선택하세요.\n");
		printf("\n");
		goto start;
	}