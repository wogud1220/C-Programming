#include <stdio.h>
int main(void)
{
	int sum = 0;
	int a = 0;

	while (a <= 100) {
		++a;
		if (sum >= 2000)
			break;
		if (a == 6)
			continue;
		if (a > 10 && a % 10 == 6)
			continue;
		if (a % 5 == 0)
			sum += a * 2;
		sum += a;
	}
	printf("%d\n",sum);
	return 0;
}
