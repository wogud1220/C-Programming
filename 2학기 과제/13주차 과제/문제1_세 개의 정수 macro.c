#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUM(A,B,C)  (A+B+C)
#define MUL(A,B,C)  (A*B*C)


int main(){

    int a, b, c;

    printf("정수 3개를 입력하세요 :");
    scanf("%d %d %d", &a, &b, &c);
    puts("");
    printf("덧셈 결과: %d\n", SUM(a,b,c));
    printf("곱셈 결과: %d\n", MUL(a,b,c));

}