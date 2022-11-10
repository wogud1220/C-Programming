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


int compare(ONEWORD* wordarr, DICTIONARY *dictarr, int cnt) {
	if (!strcmp(wordarr, dictarr)) {
		printf("이미 있는 단어입니다.");
	}
	else {
		printf("없는 단어입니다. 저장하겠습니다.\n");
		strcat(dictarr, wordarr);
		printf("뜻을 입력해주세요\n");
		gets(wordarr->meaning);

	}
	return cnt;
}


int main()
{
	FILE* fp = fopen("dict_origin.txt", "rt");
	FILE* fp2 = fopen("dictionary.txt", "wt");

	if (fp == NULL||fp2==NULL) {
		puts("파일 오픈 실패!");
			return -1;
	}

	int i = 0;
	int a = 0;
	int cnt = 0;
	int count;
	char str[100];
	ONEWORD wordarr[100] = { 0, };
	DICTIONARY dictarr[100] = { 0, };
	printf("기존에 기록된 영한 사전:\n");
	while (fgets(str, sizeof(str), fp) != NULL) {
		printf("%s", str);
	}
	FILE* fp3 = fopen("dict_origin.txt", "wt");

	while (i < 3) {
		printf("단어를 입력하세요\n");
		gets(wordarr[i].word);		//scanf("%s", );
		fputs(wordarr[i].meaning, fp2);
		fputs(wordarr[i].meaning, fp3);
		compare(wordarr[i].word, dictarr[cnt].Onewordict, cnt);
		i++;
		fputs(dictarr[cnt].Onewordict, fp2);
		fputs("\n", fp2);
		fputs(dictarr[cnt].Onewordict, fp3);
		fputs("\n", fp3);
	}


	fclose(fp);
	fclose(fp2);
	fclose(fp3);
	return 0;
}
