#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)

/*typedef struct data {
    char name[20];
    char number[20];
    struct data* next;
}data;
//새로운 노드 생성 해서 데이터 입력받고 노드 반환
*/
#include "header.h"
extern data* insert();
/*data* insert()
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
}*/
                                                    //연결리스트중 마지막 요소찾아서 반환

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
    printf("<<연락처 입력>>\n");
    head = insert();
    char s[10];
    for (int i = 1; ; i++)
    {
        if (i >= 5)
        {
            char menu;
            printf("5명 이상 입력했습니다. 종료하시겠습니까?\n예 : q\n아니요 : n\n");
            printf("입력 : ");
            getchar();
            scanf("%c", &menu);
            if (menu == 'q')
                break;
        }
        //마지막 노드 찾아서 마지막노드 뒤에 새로운 노드 연결시키기
        data* temp = find_finish(head);
        temp->next = insert();
    }
    data* cp1 = head;
    data* cp2 = head;
    data* cp3 = head;
    printf("\n<<연락처 출력>>\n");
    while (cp1->next != NULL)
    {
        printf("%s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n", cp1->name, cp1->next->name, cp1->next->name, cp1->next->number);
        cp1 = cp1->next;
    }
    if (cp1->next == NULL)
        printf("%s이 연락을 받았습니다. 모든 구성원들에게 연락을 했습니다.\n", cp1->name);
    printf("아픈 사람을 입력하세요 ");
    scanf("%s", s);
    while (cp3->next != NULL) {
        if (strcmp(cp3->next->name, s) == 0) {
            printf("%s는%s에게 연락해야합니다. %s의 전화번호는 %s입니다.", cp3->name, cp3->next->next->name, cp3->next->next->name, cp3->next->next->number);
        }
        cp3 = cp3->next;
    }

    return 0;
}
