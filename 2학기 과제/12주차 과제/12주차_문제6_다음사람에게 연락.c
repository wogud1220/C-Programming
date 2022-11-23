#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct book
{
    char name[22];
    char phonenum[22];
    struct book* next;
}BOOK;

int main() {

    BOOK* head, * temp;
    char name[10];
    int cnt = 0;
    temp = head = NULL;
    while (1) {
        printf("%d번째 사람의 이름을 입력하세요  종료:q\n이름:", cnt + 1);
        scanf("%s",name);
        if (!strcmp(name, "q")) {        //  q 입력시 종료
            break;
        }
        else if (cnt == 0) {
            head = (char*)malloc(sizeof(BOOK));
            temp = head;
        }
        else {
            temp->next = (char*)malloc(sizeof(BOOK));
            temp = temp->next;
        }
        strcpy(temp->name, name);
        printf("전화번호를 입력하세요\n");
        scanf("%s", temp->phonenum);
        temp->next = NULL;
        cnt++;
    }
   
    free(head);
    free(temp);
    return 0;

}