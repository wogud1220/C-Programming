#include <stdio.h>
int ref(int arr[101]);
int main() {
	int arr[101];
	int i;
	for (i = 1; i <= 100; i++) {
		arr[i] = i;
	}
	ref(arr);
	return 0;
}
int ref(int arr[101]) {
	int i = 1;
	int n = 2;
	for (i = 1; i <= 100; i++) {
		if (arr[i] % n == 0) {
			printf("%d\n", arr[i]);
			n = n * 2;
		}
	}
}