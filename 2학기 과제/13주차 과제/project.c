#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

/*typedef struct data {
    char name[20];
    char number[20];
    struct data* next;
}data;
//���ο� ��� ���� �ؼ� ������ �Է¹ް� ��� ��ȯ
*/
#include "header.h"
extern data* insert();
/*data* insert()
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
}*/
                                                    //���Ḯ��Ʈ�� ������ ���ã�Ƽ� ��ȯ

/*data* find_finish(data* node)
{
    while (1)
    {
        if (node->next == NULL)
            return node;
        node = node->next;
    }
}*/
extern data *find_finish();

int main()
{
    data* head;
    printf("<<����ó �Է�>>\n");
    head = insert();
    char s[10];
    for (int i = 1; ; i++)
    {
        if (i >= 5)
        {
            char menu;
            printf("5�� �̻� �Է��߽��ϴ�. �����Ͻðڽ��ϱ�?\n�� : q\n�ƴϿ� : n\n");
            printf("�Է� : ");
            getchar();
            scanf("%c", &menu);
            if (menu == 'q')
                break;
        }
        //������ ��� ã�Ƽ� ��������� �ڿ� ���ο� ��� �����Ű��
        data* temp = find_finish(head);
        temp->next = insert();
    }
    data* cp1 = head;
    data* cp2 = head;
    data* cp3 = head;
    printf("\n<<����ó ���>>\n");
    while (cp1->next != NULL)
    {
        printf("%s�� %s���� ������ �ؾ� �մϴ�. %s�� ��ȭ��ȣ�� %s�Դϴ�.\n", cp1->name, cp1->next->name, cp1->next->name, cp1->next->number);
        cp1 = cp1->next;
    }
    if (cp1->next == NULL)
        printf("%s�� ������ �޾ҽ��ϴ�. ��� �������鿡�� ������ �߽��ϴ�.\n", cp1->name);
    printf("���� ����� �Է��ϼ��� ");
    scanf("%s", s);
    while (cp3->next != NULL) {
        if (strcmp(cp3->next->name, s) == 0) {
            printf("%s��%s���� �����ؾ��մϴ�. %s�� ��ȭ��ȣ�� %s�Դϴ�.", cp3->name, cp3->next->next->name, cp3->next->next->name, cp3->next->next->number);
        }
        cp3 = cp3->next;
    }

    return 0;
}
