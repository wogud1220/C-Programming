#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i = 0;
	int n, j;
	scanf("%d", &n);
	for (j = 1; j <= n; j++) {
		for (i = 1; i <= j; i++) {
			printf("*");
		}
		printf("\n");
	}
}