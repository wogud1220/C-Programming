#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPARE(A,B)    (A>B)?A:B

int main() {
    int a, b;
    printf("정수 2개를 입력하세요:");
    scanf("%d %d", &a, &b);
    puts("");
    printf("더 큰 값은:%d", COMPARE(a, b));
}