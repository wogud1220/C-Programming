/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct oneword {
    char word[20];
    char meaning[20];
}ONEWORD;

int checkword(ONEWORD* ptr, char* in_word, int cnt);
void addList(ONEWORD* ptr, char* in_word);

int main() {
    ONEWORD dict[100];      //구조체의 들어간 단어의 개수
    char in_word[20];		//구조체의 word와 비교하기 위해서
    int cnt = 0;			//현재까지의 단어 개수

    while (1) {
        printf("단어를 입력하세요 종료:q\n");
        printf("단어 : ");
        scanf("%s", in_word);
        getchar();
        //fgets(in_word, sizeof(in_word), stdin);
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
}*/


//내가한것
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct oneword {
	char word[20];
	char meaning[100];
}ONEWORD;

int CheckList(ONEWORD* dictionary, char *in_word) {
	for (int i = 0; i < 100; i++) {
		if (!strcmp((dictionary + i)->word, in_word)) {
			printf("이미 있는 단어입니다.");
			return 1;
		}
	}
	return 0;
}

int AddList(ONEWORD* dictionary, char *in_word) {
	printf("없는 단어입니다 추가하겠습니다.\n");

	strcpy(dictionary->word, in_word);
	printf("뜻: ");
	scanf("%s", dictionary->meaning);
	return 0;

}


int main() {
	ONEWORD dictionary[100];
	char in_word[20];	//20글자의 단어 입력받음

	for(int i=0;i<100;i++) {
		printf("단어를 입력하세요: ");
		scanf("%s", in_word);
		if (in_word == 'q') {
			return 0;
		}
		if (CheckList(dictionary, in_word))
			continue;
		AddList(&dictionary[i], in_word);




	}
}