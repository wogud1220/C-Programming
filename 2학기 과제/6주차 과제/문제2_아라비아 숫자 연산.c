#include <stdio.h>

int main(void)
{
    char a[20];
    char num[20];
    int sum = 0;

    printf("아라비아 숫자만 연산합니다.\n");
    gets(a);

    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            sum += (a[i] - 48);
        }
    }
    printf("%d", sum);

    return 0;
}