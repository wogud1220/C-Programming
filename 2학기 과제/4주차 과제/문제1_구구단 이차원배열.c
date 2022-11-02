#include <stdio.h>
int main(void)
{
	int arr[3][9];
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 9; j++)
			arr[i][j] = (i + 2) * (j + 1);
	for (i = 0; i < 3; i++)
	{
		printf("%d단 : ", i + 2);
		for (j = 0; j < 9; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}