#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


void MaxAndMin(int* ptr, int** a, int** b);

int main(void) {

    int* maxPtr;
    int* minPtr;
    int arr[5];

    printf("number : ");
    for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);

    MaxAndMin(arr, &maxPtr, &minPtr);
    printf("max : %d\nmin : %d\n", *maxPtr, *minPtr);

    return 0;
}
void MaxAndMin(int* ptr, int** a, int** b) {

    int max, min;
    min = max = ptr[0];

    for (int i = 0; i < 5; i++)
    {
        if (max < *(ptr + i)) max = ptr[i];
        if (min > *(ptr + i)) min = ptr[i];
    }
    *a = &max;
    *b = &min;
}