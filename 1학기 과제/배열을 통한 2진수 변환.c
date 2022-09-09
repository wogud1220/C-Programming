#include <stdio.h>
int main(void) {
	int a[20];
	int i = 0;
	int num = 0;
	int j;
	printf("10진수 값을 입력하세요 \n");
	scanf_s("%d", &num);
	printf("\n10진수: %d\n", num);
	printf("2진수 : ");


	while (num > 0) {
		a[i++] = num % 2;
		num = num / 2;

	}
	for (j = 0; j < i; j++)
			printf("%d", a[i - j - 1]);
	return 0;





}
