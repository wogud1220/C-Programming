#include <stdio.h>
int main(void) {

    int ten;

    printf("10진수를 입력하세요:");
    scanf_s("%d", &ten);
    printf("10진수 값은:%d\n", ten);
    binary(ten);
    return 0;
}
int binary(int ten) {
    if (ten > 1)
        binary(ten / 2);
    printf("%d", ten % 2);
}
