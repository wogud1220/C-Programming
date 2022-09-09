#include <stdio.h>
main(void)
{
	int dan, num;
	
	for (num = 1; num < 10; num++)
	{
		for (dan = 2; dan <10; dan++)
		{
			printf("%d X %d = %d\t", dan, num, dan * num);
		}
		printf("\n");
	}
}