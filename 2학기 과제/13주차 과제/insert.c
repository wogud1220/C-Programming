#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

data* insert()
{
    data* temp = (data*)malloc(sizeof(data));
    char name[20];
    char number[20];
    printf("이름 : ");
    scanf("%s", temp->name);
    printf("전화번호 : ");
    scanf("%s", temp->number);
    temp->next = NULL;
    return temp;
}