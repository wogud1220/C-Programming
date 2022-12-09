#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char* ReadUserName(void) {
	char* name = (char*)malloc(sizeof(char) * 30);
	printf("What's Your name?");
	gets(name);
	return name;
}

char* job1(void) {
	char* job = (char*)malloc(sizeof(char) * 30);
	gets(job);
	return job;
 }


int main() {

	char* name1;
	char* name2;
	char* job;
	name1 = ReadUserName();
	printf("name1: %s\n", name1);
	name2 = ReadUserName();
	printf("name2: %s \n", name2);

	printf("again name1: %s \n", name1);
	printf("again name2: %s \n", name2);

	//job = job1();
	printf("%s", job1());

}