#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/*int value(int a) {
	return = a * a;
	
}
int main() {
	int a;
	scanf("%d", &a);
	printf("%d", value(a));
}*/
int reference(int* num) {
	return  *num * *num;
}
int main() {
	int a;
	int* ptr = &a;
	scanf("%d", &a);
	printf("%d", reference(ptr));
}