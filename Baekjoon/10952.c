#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int i = 0;
	int num1, num2;
	while (scanf("%d %d", &num1, &num2)) {
		if (num1 == 0 && num2 == 0)
			return 0;
		printf("%d\n", num1+num2);
		i++;
	}
}
