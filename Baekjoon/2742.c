#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i) {
		printf("%d\n", n);
		n = n - 1;
	}
}