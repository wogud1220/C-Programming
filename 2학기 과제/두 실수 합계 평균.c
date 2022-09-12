#include <stdio.h>
float avr(float a, float b) {
	float average = (a + b) / 2;
	return average;
}
float hap(float a, float b) {
	float h = a + b;
	return h;
}
int main(void) {
	float num1, num2;
	printf("두 개의 실수를 입력하세요");
	scanf_s("%f %f", &num1, &num2);
	float h =hap(num1, num2);
	float average =avr(num1, num2);
	printf("두 실수의 합은 %f\n", h);
	printf("두 실수의 평균은 %f", average);
	return 0;
}