#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 1; i < 10; i++) {
		printf("%d * %d = %d\n", n, i, n * i);
	}
}