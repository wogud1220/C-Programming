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

    printf("%d개의 연락처가 저장됨.\n",cnt);
    printf("%s이 연락을 받았습니다.모든 구성원들에게 연락을 했습니다.\n", temp->name);
    printf("아픈 사람을 입력하세요 :");
    scanf("%s", name);
    temp = head;
    while (temp != NULL) {
        if (!strcmp(name, temp->name)) {
            printf("%s는 %s에게 연락해야합니다. %s의 전화번호는 %s입니다.\n",
                name, temp->next->name, temp->next->name, temp->next->phonenum);
            break;
        }
        else
            temp = temp->next;
    }
    
    temp = head;
    printf("%s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n", 
        head->name, head->next->name, head->next->name, head->next->phonenum);
    int i = 0;


    while(temp!=NULL) {
        temp = temp->next;
        printf("%s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n", 
            temp->name, temp->next->name, temp->next->name, temp->next->phonenum);
    }



    return 0;


    


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996)
typedef struct data {
    char name[20];
    char number[20];
    struct data* next;
}data;
//새로운 노드 생성 해서 데이터 입력받고 노드 반환
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
//연결리스트중 마지막 요소찾아서 반환
data* find_finish(data* node)
{
    while (1)
    {
        if (node->next == NULL)
            return node;
        node = node->next;
    }
}
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
    printf("구성원 이름을 입력하세요 : ");
    scanf("%s", s);
    while (cp3->next != NULL) {
        if (strcmp(cp3->next->name, s) == 0) {
            printf("%s는%s에게 연락해야합니다. %s의 전화번호는 %s입니다.",cp3->name,cp3->next->next->name, cp3->next->next->name, cp3->next->next->number);
        }
        cp3 = cp3->next;
    }

    return 0;
}
