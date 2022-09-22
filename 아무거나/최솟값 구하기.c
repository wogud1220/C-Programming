#include <stdio.h>
void main()
{
	int a = 3, b = 8, c = 9, d = 2, e = 4;
	int min;

	min = (a <= b && a <= c && a <= e && a <= d) ? (a) :
		(b <= a && b <= c && b <= e && b <= d) ? (b) :
		(c <= b && c <= a && c <= e && a <= d) ? (c) :
		(d <= a && d <= b && d <= c && d <= e) ? (d) :
		(e <= a && e <= c && e <= b && e <= d) ? (e) : (0);


	printf("최솟값은= %d\n", min);
}