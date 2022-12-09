#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)

{
    int i;
    long fpos;

    FILE* fp = fopen("text.txt", "wt");
    fputs("1234-", fp);
    fclose(fp);

    fp= fopen("test.txt", "rt");

    for (i = 0; i < 4; i++) {
        putchar(fgetc(fp));
        fpos = ftell(fp);
        fseek(fp, -1, SEEK_END);
        putchar(fgetc(fp));
        fseek(fp, fpos, SEEK_SET);

    }
    fclose(fp);
    return 0;


}