#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

data* insert()
{
    data* temp = (data*)malloc(sizeof(data));
    char name[20];
    char number[20];
    printf("�̸� : ");
    scanf("%s", temp->name);
    printf("��ȭ��ȣ : ");
    scanf("%s", temp->number);
    temp->next = NULL;
    return temp;
}