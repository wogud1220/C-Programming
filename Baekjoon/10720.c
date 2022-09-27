#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	char arr[100];
	scanf("%s", arr);
	int i;
	for (i = 0; i < n; i++) {
		sum += arr[i] - '0';
	}
	printf("%d", sum);
}
