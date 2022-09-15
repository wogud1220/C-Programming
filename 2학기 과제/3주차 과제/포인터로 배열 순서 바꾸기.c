#include <stdio.h>
int main() {

	int arr[6] = { 1,2,3,4,5,6 };
	int i;
	int* ptr1 = arr;
	int* ptr2 = &arr[5];
	int temp;
	
	for (i = 0; i < 3; i++) {

		temp = *(ptr1+i);
		*(ptr1+i)= *(ptr2-i);
		*(ptr2-i) = temp;
	}
	for(i=0;i<6;i++)
		printf("%d ", *(ptr1+i));
}