#include <stdio.h>
int ref(int *p) {
	int i = 1;
	int  n = 1;
	for (i = 1; i <= 100; i++) {
		if (*(p + i) % n == 0) {
			printf("%d", *(p + i));
			n = n * 2;
		}
	}
}
int main() {
	int arr[101];
	int i = 1;
	int* ptr = arr;
	for (i = 1; i <= 100; i++) {
		*(ptr + i) = i;
	}
	int ref(ptr);







}
