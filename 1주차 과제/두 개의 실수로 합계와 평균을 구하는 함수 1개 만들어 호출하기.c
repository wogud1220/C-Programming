#include <stdio.h>
void add(int num1, int num2, int *sum, int *avg) {	//main �Լ����� �Է¹��� ���� 2���� 
	*sum = num1 + num2;		// main�Լ����� �Ű������� �Ѱ��� num1,num2�� ���Ͽ� ������ ���� sum�� ���� ����
	*avg = (num1 + num2) / 2;//main�Լ����� �Ű������� �Ѱ��� �͵��� �̿��Ͽ� ����� ����ϰ� avg�� ���� ����
}
int main(void) {	// main�Լ� ����
	int num1, num2, sum, avg;	//������ ���� ����
	scanf_s("%d %d", &num1, &num2);	//�Է¹��� ������ num1�� num2�� �ּҿ� ����
	add(num1, num2, &sum, &avg);	//4���� ���ڵ��� add�Լ��� �����ϸ� add�Լ� ȣ��
	printf("�հ�:%d\n���:%d\n", sum, avg);	//sum�� avg�� �� ���
}
