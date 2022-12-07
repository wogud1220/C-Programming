#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
세 줄의 문장을 입력 받아 파일에 저장한 후,
그 파일을 열어 역순으로 화면에 출력하는 프로그램을 작성하시오.
이 문제를 malloc()을 이용해 해결하세요.
파일에는 내용이 3줄 있을 것을 가정하고 시작하되, 4줄 이상이 있는 경우 realloc()하세요.
*/

#define SLEN 30 	// 29자까지 입력받기로 함
#define SLINE 10 	// 10줄까지 입력받기로 함 

void inputSentence() {
    char *str;
    int i;
	
	FILE *fp=fopen("sentence.txt","wt");
	if(fp==NULL) {
		printf("파일 열기에 실패했습니다.\n");
		return;
	}
	
	str=(char *)malloc(sizeof(char)*SLEN);
	for(i=0; i<SLINE; i++) {
		memset(str, 0, sizeof(char)*SLEN);
	
		printf("문장을 입력하세요(종료:Enter)>>> ");    
    	fgets(str, SLEN, stdin);
    	if(str[0]=='\n')
    		break;
    	fwrite(str, sizeof(char), strlen(str),fp);
	}

	if(i==SLINE)
		printf("%d줄을 초과해서 입력할 수 없습니다\n", SLINE);
    free(str);
    fclose(fp);
    return;
}

int checkFileSize(FILE *fp) {
	fseek(fp, 0, SEEK_END);
	int size=ftell(fp);
	fseek(fp, 0, SEEK_SET);
	return size;
}

void printSentence() {
	int line=0;
	int filesize=0;
	char *str;
	
	FILE *fp=fopen("sentence.txt","rt");
	if(fp==NULL) {
		printf("파일이 존재하지 않거나 열기에 실패했습니다.\n");
		return;
	}
	
	filesize=checkFileSize(fp);
	str=(char *)malloc(sizeof(char)*SLEN);
	memset(str, 0, sizeof(char)*SLEN);
	
	while(!feof(fp) && ftell(fp) != filesize) {
		fgets(str, SLEN, fp);
		line++;
		printf("[%2d] %s", line, str);
	}
	free(str);
	fclose(fp);
	return;
}

void printReverse() {
	char **str;
    int i;
    int line=0;
	int filesize=0;
    
	FILE *fp=fopen("sentence.txt","rt");
	if(fp==NULL) {
		printf("파일이 존재하지 않거나 열기에 실패했습니다.\n");
		return;
	}
	
	filesize=checkFileSize(fp);
	str = (char **)malloc(sizeof(char *) * SLINE);
		
	for(i=0; (!feof(fp) && ftell(fp) != filesize); i++) {
		str[i]=(char *)malloc(sizeof(char)*SLEN);
		memset(str[i], 0, sizeof(char)*SLEN);
		fgets(str[i], SLEN, fp);
	}
	line=i;
	
	for (i=line; i>0; i--) {
		printf("[%2d] %s", i, str[i-1]);
    }

    for (i=0; i<line; i++) {
        free(str[i]);
    }
    free(str);
	fclose(fp);
	return;
}


int main() {
	inputSentence();
	printSentence();
	printReverse();
}
