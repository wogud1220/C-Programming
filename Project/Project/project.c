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
start:
	printf("�� ������ �Է��ϼ���\n");
	scanf("%d %d", &x, &y);
	printf("\n� ������ �����ұ��?\n");
	printf("(1~5 �� ����. 0�Է��ϸ� ����) <== �ݺ� ����\n");
	printf("0: ����\n1: +\n2: -\n3: *\n4: �ִ�\n5: �ּڰ�\n\n");
	scanf("%d", &n);
	if (n == 0) {
		printf("�����ϰڽ��ϴ�.");
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
		printf("0~5�� �����ϼ���.\n");
		printf("\n");
		goto start;
	}