#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i = 0;
	int t, num1, num2;
	scanf("%d", &t);
	
	while (i < t) {
		scanf("%d %d", &num1, &num2);
		printf("%d\n", num1+num2);
		i++;
	}
}



