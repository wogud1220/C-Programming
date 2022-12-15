#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct book
{
    char name[22];
    char phonenum[22];
    struct book* next;
    // struct book* back;
}BOOK;

void memoryFree(BOOK* head);

int main() {

    BOOK* head;
    BOOK* temp;
    BOOK* back;
    char name[10];
    int cnt = 0;
    temp = head = NULL;

    //---------------------
    // cnt명 입력 받는 코드 
    //--------------------- 
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
    //back = temp;            //역순 출력 변수 선언

    printf("%d개의 연락처가 저장됨.\n", cnt);
    //--- 마지막 사람 이름 출력해봄 
    printf("%s가 연락을 받았습니다.모든 구성원들에게 연락을 했습니다.\n", temp->name);


    //-------------------------------------------
    // 처음부터 마지막 사람까지 비상연락망 출력함
    //------------------------------------------- 
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


    //----------------------------------------------------
    // 아픈 사람을 입력 받아, 아픈 사람을 건너 뛰고 연락함
    //---------------------------------------------------- 
    temp = head;
    /*printf("%s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n",
        head->name, head->next->name, head->next->name, head->next->phonenum);*/        //처음 사람 출력
    int i = 0;

    printf("아픈 사람을 입력하세요 :");
    scanf("%s", name);

    //--- 아픈 사람이 탈퇴한 건 아니고....... 
    //printf("\n%s님이 탈퇴했습니다.\n", name);


    //--- 아픈 사람이 누구인지  찾기 위함 
    BOOK* sick = head;


    while (1) {
        //--- 여기서 왜 sick->name과 비교하지 않고 temp->name과 비교할까요??? 
        //--- 아래에서 temp아 아픈 사람이고, sick은 아픈사람의 바로 앞에 있는 사람인가요?   ㅇㅇ
        //--- 그러면 sick->name이 temp->next->name에게 연락하는 게 맞음 
        if (!strcmp(name, temp->name)) { //--- 아픈 사람을 찾았으면 
            printf("앞으로는 %s는 %s에게 연락을 해야 합니다. %s의 전화번호는 %s입니다.\n",      //아픈 사람 건너뛰고 연락하기
                sick->name, temp->next->name, temp->next->name, temp->next->phonenum);
            break;                                                  //아픈 사람은 이제 필요 없으니 free해줘야하는지... 근데 해버리면 다음 공간을 못 가르키지 않는지..?
            //--- 아픈 사람도 다음 모임엔 병이 나아 다시 나올 수 있으니
            //--- 완전히 삭제하지는 않습니다. 탈퇴한 사람만 삭제합니다. free 안 해도 됩니다. 
        }
        else { //--- 아픈 사람을 찾지 못했으면 그 다음 사람으로 넘어감. 
            sick = temp;
            temp = temp->next;
            //--- 아픈 사람을 찾았고, 그 사람이 마지막 사람이면  
            if (temp->next == NULL && (!strcmp(name, temp->name))) {        //마지막 사람일 때 출력 문구
                printf("%s는 마지막사람입니다.\n", name);
                printf("%s는 연락할 사람이 없습니다.", sick->name);
                break;
            }
        }
    }

    //--- 탈퇴한 사람 입력 받아서 처리하세요. 
    printf("탈퇴한  사람을 입력하세요 :");
    scanf("%s", name);
    //--- 이렇게 입력 받아서 위에 아픈 사람 찾는 부분과 동일하게 처리하되,
    //--- 탈퇴한 사람 다음 사람을 이전 사람에게 연결해주고 메모리 free해줌.
    //--- sick->next=temp->next; free(temp);


    //------------------------------------------------------------
    // 비상연락망 출력하는 부분 (name에 아픈 사람이 들어있다고 하면 아픈사람은 출력 안 됨) 
    //------------------------------------------------------------ 
    temp = head;

    printf("\n연락처 출력        빠진 사람 제외하고\n");         //연락처 출력 빠진 사람 제외.

    while (temp != NULL) {
        if (!strcmp(name, temp->name)) {
            temp = temp->next;
            continue;
        }
        printf("\n%s : %s\n", temp->name, temp->phonenum);
        temp = temp->next;
    }

    //--------------------------
    // 전체 메모리 해제하고 종료
    // 방법 1) head를 넘겨주고 메일 마지막 사람부터 free하는 재귀함수를 작성하거나
    // 방법 2) 일단 제일 끝까지 찾아간 후, 그 이전 사람을 유지하고 끝 사람 삭제...를 반복 
    //         ==> 그런데 이전 사람을 다 유지하는 게 쉽지 않음.
    //         ==> 마지막 문제처럼 prev(앞사람) 포인터를 유지하면 좀 쉽게 됨 
    // 방법 1 권장 
    //-------------------------- 
    temp = head;
    sick = head;

    //--- 이렇게 하면 head 하나만 해제됨 
    //free(head);                 //메모리 해제하기

    /*while (temp != NULL) {
        free(temp);         //이렇게 해제해버리면 다음 공간을 가르키는 것이 사라질 것 같은데 어떻게 해제하는 지 모르겠습니다...
        temp = temp->next;
    }*/


    /*while (sick != NULL) {
        free(sick);         //이렇게 해제해버리면 다음 공간을 가르키는 것이 사라질 것 같은데 어떻게 해제하는 지 모르겠습니다...
        sick= sick->next;
    }*/


    //--------------
    // 재귀함수 예시
    //--------------
    printf("\n재귀함수로 메모리 해제. 가장 마지막 것부터 해제됨\n");
    memoryFree(head);

    return 0;
}

void memoryFree(BOOK* head) {
    if ((head->next) != NULL) {
        memoryFree(head->next);
        printf("%s 메모리해제\n", head->name);
        free(head);
    }
    else { // 마지막 사람이면 
        printf("%s 메모리해제\n", head->name);
        free(head);
    }
    return;
}

