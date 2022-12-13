#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct oneword {
    char word[20];
    char meaning[20];
}ONEWORD;

int checkword(ONEWORD* ptr, char* in_word, int cnt);
void addList(ONEWORD* ptr, char* in_word);
void readDict(ONEWORD* rptr, int* cptr);
void printDict(ONEWORD* pptr, int cnt);
void writeDict(ONEWORD* wptr, int cnt);

int main() {
    ONEWORD dict[100];
    char in_word[20];		//구조체의 word와 비교하기 위해서
    int cnt = 0;			//현재까지의 단어 개수

    readDict(dict, &cnt);	//파일에서 단어 불러오기

    printDict(dict, cnt);	//단어 전체 출력하기

    while (1) {
        printf("단어를 입력하세요 종료:q\n");
        printf("단어 : ");
        fgets(in_word, sizeof(in_word), stdin);
        //gets(in_word);
        in_word[strlen(in_word) - 1] = '\0';

        if (!strcmp(in_word, "q"))		//q가 입력되면 반복문 중지
            break;

        if (checkword(dict, in_word, cnt))	//이미 있는단어면 새로운 단어 받기
            continue;

        addList(&dict[cnt], in_word);// 없는 단어면 받은 단어 저장


        printf("%d번째 단어 출력 %s : %s\n", cnt + 1, dict[cnt].word, dict[cnt].meaning);
        cnt++;
    }
    writeDict(dict, cnt);
    return 0;
}

//1을 반환하면 참 
int checkword(ONEWORD* ptr, char* in_word, int cnt) {

    int i = 0;
    for (i = 0; i < cnt; i++) {
        //이미 입력돼있는 것
        if (!strcmp((ptr + i)->word, in_word)) {
            printf("이미 있는 단어입니다. \n %s : %s\n", (ptr + i)->word, (ptr + i)->meaning);
            return 1;
        }
    }
    return 0;
}

//새로운 단어

void addList(ONEWORD* ptr, char* in_word) {
    strcpy(ptr->word, in_word);

    printf("뜻 :");
    fgets(ptr->meaning, sizeof(ptr->meaning), stdin);
    ptr->meaning[strlen(ptr->meaning) - 1] = '\0';

    return;
}

void readDict(ONEWORD* rptr, int* cptr) {
    int i = 0;
    FILE* fp = fopen("dict.dat", "rb");	//구조체니깐 바이너리
    if (fp == NULL) {
        printf("파일이 없습니다.\n");
            return;
    }
    for (i = 0; i < 100 && feof(fp) == 0; i++) {
        fread((ONEWORD*)(rptr + i), sizeof(ONEWORD), 1, fp);
    }
    fclose(fp);
    *cptr = i - 1;
}
void printDict(ONEWORD* pptr, int cnt) {
    int i;
    for (i = 0; i < cnt; i++) {
        printf("[%3d번째 단어] %s  %s\n", i + 1, (pptr + i)->word, (pptr + i)->meaning);
    }
}
void writeDict(ONEWORD* wptr, int cnt) {
    int i = 0;
    FILE* fp = fopen("dict.dat", "wb");	//구조체니깐 바이너리
    if (fp == NULL) {
        printf("파일이 없습니다.\n");
            return;
    }
    for (i = 0; i < cnt; i++) {
        fwrite((ONEWORD*)(wptr + i), sizeof(ONEWORD), 1, fp);
    }
    fclose(fp);
}
