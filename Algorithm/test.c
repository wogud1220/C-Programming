#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 1000001
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory.h>
#include <ctype.h>
// #include <windows.h>
// #pragma warning(disable:4996)

int main()
{
    int arr[] = {9, 8, 2, 10, 15, 12, 3, 22, 0, 3, 1, 1};
    int arrSize = sizeof(arr) / sizeof(int);
    interationMergeSort(arr, arrSize);
}