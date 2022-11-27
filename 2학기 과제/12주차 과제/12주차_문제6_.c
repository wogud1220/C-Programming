#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct number_book {
char name[10];
char phone_number[20];
struct number_book *next;
}call;

int main() {
struct number_book *head;
struct number_book *temp;
char name[10];
int cnt = 0;
temp = head = NULL;

while (1) {
printf("비상연락망에 추가할 사람의 이름을 입력해주세요 (최소 5명의 정보를 입력하고 입력을 종료하고 싶으면 q를 입력해주세요) : ");
scanf_s("%s", name, 10);

if (name[0] == 'q')
break;
else if (cnt == 0) {
head = malloc(sizeof(call));
temp = head;
}
else {
temp->next = malloc(sizeof(call));
temp = temp->next;
}

strcpy_s(temp->name, 10, name);

printf("비상연락망에 추가할 사람의 전화번호를 입력해주세요: ");
scanf_s("%s", temp->phone_number, 20);

temp->next = NULL;

cnt++;
}

free(head);
free(temp);

return 0;
}