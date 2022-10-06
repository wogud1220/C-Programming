#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void main()
{
	int score;
	printf("점수를 입력하세요.\n");
	scanf("%d", &score);
	
	switch (score / 10)
	{
	case 10:
	case 9:printf("A\n"); break;	
	case 8:printf("B\n"); break;
	case 7:printf("C\n"); break;
	case 6:printf("D\n"); break;
	default: printf("F\n");
	}
}