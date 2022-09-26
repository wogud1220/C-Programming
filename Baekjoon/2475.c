#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i;
	int arr[5];
	int j, k;
	int hap = 0;
	for (i = 0; i < 5; i++) {
		scanf("%d",&arr[i]);
	}
	i = 0;
	for (j = 0; i < 5; j++) {
		hap = arr[i] * arr[i] + hap;
		i++;
	}
	printf("%d", hap % 10);
}