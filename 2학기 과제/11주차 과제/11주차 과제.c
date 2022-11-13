int main() {
	FILE* fp;
	fp = fopen("text.txt", "w+");

	if (fp == NULL) {
		puts("파일오픈 실패!");
		return -1;
	}

	char* name1 = (char*)malloc(sizeof(char) * 10);
	char* name2 = (char*)malloc(sizeof(char) * 10);
	char* name3 = (char*)malloc(sizeof(char) * 10);
	printf("문장을 입력하세요 :");

	scanf("%s", name1);
	fputs(name1, fp);
	fputs("\n", fp);
	scanf("%s", name2);
	fputs(name2, fp);
	fputs("\n", fp);
	scanf("%s", name3);
	fputs(name3, fp);
	fputs("\n", fp);


	if (name1 <= 4) {
		name1=(char*)realloc(name1, sizeof(char)*4)

	}


	fseek(fp, -10, SEEK_END);

	while (fgets(name3, sizeof(name3), fp) != NULL) {
		printf("%s", name3);
	}


	free(name1);
	free(name2);
	free(name3);
	return 0;
}