#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


// [문제 1]

/*void print_ddarr(int(*pa)[4]) {
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++) {
			printf("%d ", pa[i][j]);
		}
		printf("\n");
	}
}
int main(void)

{
	int arr[3][4] = { {1,2},{3,4,5},{6,7,8,9} };
	print_ddarr(arr);

	return 0;
}*/

//[문제 2]

/*int swap(char** ptr1, char** ptr2) {
	char *temp;
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;


}
int main(void) {
	char arr1[20];
	char arr2[20];

	gets(arr1);
	gets(arr2);

	int* ptr1 = arr1;
	int* ptr2 = arr2;

	swap(&ptr1,&ptr2);

	printf("\n\n%s\n", ptr1);
	printf("%s", ptr2);
}*/