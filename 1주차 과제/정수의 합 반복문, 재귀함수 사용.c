#include <stdio.h>
/*int main(void) {			//main�Լ� ����
	int i, num1;			//int�� ���� ����
	int sum = 0;
	printf("������ �Է��ϼ���\n");	//���� ���
	scanf_s("%d", &num1);		//������ �Է¹޾� num1������ ����
	for (i = 0; i <= num1; i++) {	//1���� �Է¹��� �������� ���ϴ� ���� ����
		sum+=i;		//sum�� 0���� �Է��� ���� �� ����
	}
	printf("%d", sum);	//sum�� ���
	return 0;	//main�Լ� ����
}*/
int hap(int num1) {	//num1�� �Ű������� ���� hap�Լ� ����
	if (num1==0){	//���� num1���� 0�̶��
		return 0; // 0 ��ȯ �ϱ�, hap�Լ� ����
	}
	else { //���� ���ǿ� �������� �ʴ´ٸ�
		return num1 + hap(num1 - 1); //num1���� ��ȯ�ϰ� (num1-1)�� ���� hap�Լ��� �ٽ� ȣ��
	}
}
int main(void) {	//main �Լ� ����
	int num1 = 0;	//������ ���� ����
	printf("������ �Է��ϼ���");	//���� ���
	scanf_s("%d", &num1);		//�Է¹��� ���� num1�� ����
	hap(num1);	//hap�Լ��� num1�� ����
	printf("%d", hap(num1));	//hap �Լ��� return �� ���
	return 0; //main �Լ� ����



}