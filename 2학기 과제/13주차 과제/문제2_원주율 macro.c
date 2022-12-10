#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI  3.14

int main() {

    int r;
    printf("원의 반지름을 입력하세요: ");
    scanf("%d", &r);
    puts("");
    printf("%lf", r *r* PI);

    return 0;

}