#include <stdio.h>

int main(void)
{
    int a;
    a = getchar();
    if (a >= 'a' && a <= 'z')
    {
        a -= ('a' - 'A');
        putchar(a);
    }
    else if(a >= 'A' && a <= 'Z')
    {
        a += ('a' - 'A');
        putchar(a);
    }
    return 0;
}