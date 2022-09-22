#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	double A, b;
	scanf("%lf %lf", &A, &b);
	printf("%.9lf", A / b);
}