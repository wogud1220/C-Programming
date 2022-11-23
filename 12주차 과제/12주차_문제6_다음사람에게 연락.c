#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct book
{
    char name[22];
    char phonenum[22];
    struct book* next;
}BOOK;

int main() {

    BOOK person;
    char name[10];
    int cnt = 0;
    while (1) {
        printf("%d번째 사람의 이름을 입력하세요\n", cnt+1);
        scanf("%s", person.name);

        if (!strcmp(person.name,"q")) {
            break;
        }
        cnt++;
        printf("전화번호를 입력하세요\n");
        scanf("%s")
    }

}