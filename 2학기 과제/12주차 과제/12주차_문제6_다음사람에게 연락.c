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

    BOOK* head;
    BOOK* temp;
    char name[10];
    int cnt = 0;
    temp = head = NULL;
    while (1) {
        printf("%d번째 사람의 이름을 입력하세요  종료:q\n이름:", cnt + 1);
        scanf("%s", name);
        if (!strcmp(name, "q")) {        //  q 입력시 종료
            break;
        }
        else if (cnt == 0) {
            head = malloc(sizeof(BOOK));
            temp = head;
        }
        else {
            temp->next = malloc(sizeof(BOOK));
            temp = temp->next;
        }
        strcpy(temp->name, name);
        printf("전화번호를 입력하세요:");
        scanf("%s", temp->phonenum);
        temp->next = NULL;
        cnt++;
    }


    printf("%d개의 연락처가 저장됨.\n", cnt);
    printf("%s가 연락을 받았습니다.모든 구성원들에게 연락을 했습니다.\n", temp->name);

    temp = head;
    while (1)
    {
        if (temp->next != NULL) {
            printf("%s는 %s에게 연락해야합니다. %s의 전화번호는 %s입니다.\n",
                temp->name, temp->next->name, temp->next->name, temp->next->phonenum);
            temp = temp->next;

        }

        else
            break;
    }

    temp = head;
    /*printf("%s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n",
        head->name, head->next->name, head->next->name, head->next->phonenum);*/        //처음 사람 출력
    int i = 0;

    printf("아픈 사람을 입력하세요 :");
    scanf("%s", name);
    printf("\n%s님이 탈퇴했습니다.\n", name);
    BOOK* sick = head;

    

    while (1) {
        if (!strcmp(name, temp->name)) {
            printf("앞으로는 %s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n",
                sick->name, temp->next->name, temp->next->name, temp->next->phonenum);
            break;
        }
        /*else if (temp->next == NULL && strcmp(name, temp->name))
            printf("마지막사람입니다.");*/
        else {
            sick = temp;
            temp = temp->next;
            if (temp->next == NULL && (!strcmp(name, temp->name))) {
                printf("%s는 마지막사람입니다.\n", name);
                printf("%s는 연락할 사람이 없습니다.", sick->name);
                break;
            }
        }
    }

    temp = head;
    printf("\n연락처 출력        빠진 사람 제외하고\n");
    while (temp != NULL) {
        if (!strcmp(name, temp->name)) {
            temp = temp->next;
            continue;
        }
        printf("\n%s : %s\n", temp->name, temp->phonenum);
        temp = temp->next;
    }

    return 0;
}

