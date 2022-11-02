#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>



typedef struct Oneword {
	char word[20];
	char meaning[100];
}ONEWORD;

typedef struct dictionary {
	char Onewordict[100];
}DICTIONARY;


/*void compare(ONEWORD* wordarr, DICTIONARY* dictarr) {
	if (!strcmp(wordarr, dictarr)) {
		printf("이미 있는 단어입니다.");

	}
	else {
		printf("없는 단어입니다. 저장하겠습니다.\n");
		strcpy(dictarr, wordarr);
		cnt++;
	}
}*/

int main()
{
	ONEWORD wordarr[100];
	DICTIONARY dictarr[100];
	int i;
	int a = 1;
	int cnt = 0;

	for (i = 1; i < 100; i++) {
		printf("단어를 입력하세요\n");
		scanf("%s", wordarr[i].word);
		strcat(dictarr[a].Onewordict, wordarr[i].word);
		//compare (&wordarr[i].word, &dictarr[i-1].Onewordict);
	ONE:
		if (!strcmp(wordarr[i].word, dictarr[a].Onewordict)) {
			printf("이미 있는 단어입니다.\n");
		}
		else {
			a++;
			continue;
		}
		printf("없는 단어입니다 추가하겠습니다.\n");
		goto ONE;
		cnt++;
		puts("뜻이 무엇입니까?");
		scanf("%s", wordarr[i].meaning);
	}
}
	



