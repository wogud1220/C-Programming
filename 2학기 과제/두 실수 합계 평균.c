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
	printf("�� ���� �Ǽ��� �Է��ϼ���");
	scanf_s("%f %f", &num1, &num2);
	float h =hap(num1, num2);
	float average =avr(num1, num2);
	printf("�� �Ǽ��� ���� %f\n", h);
	printf("�� �Ǽ��� ����� %f", average);
	return 0;
}