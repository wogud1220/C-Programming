#include <stdio.h>
int main() {
	int i = 0;
	int arr[5] = { 1,2,3,4,5 };
	int* ptr = arr;
	*ptr = *ptr + 2;
	while (i < 5) {
		printf("%d\n", (*ptr +i));
		i++;
	}





}