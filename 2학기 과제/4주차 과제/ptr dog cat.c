#include <stdio.h>
void poin(char** a, char** b) {
	char* temp;
	temp= *a;
	*a = *b;
	*b =  temp;
}
int main()
{
	char* pa = "dog";
	char* pb = "cat";
	printf("바꾸기 전 : %s %s\n", pa, pb);
	poin(&pa, &pb);
	printf("바꾼 후 : %s %s\n", pa,pb);
}