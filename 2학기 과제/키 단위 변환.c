#include <stdio.h>					
float high(float i) {		// �Ǽ�i�� �Է¹޾� �Ǽ��� ��ȯ�ϴ� �Լ� ����
	float result;		//�Ǽ��� ���� result ����
	result = (float)i / 100;	// �Է� ���� Ű�� m������ ��ȯ
	return result;				// result���� main �Լ��� ��ȯ
}
int main(void) {				//main �Լ� ����
	int i;						//������ ���� i����
	float c;					//�Ǽ��� ���� c ����
	printf("Ű�� �Է��ϼ���.\n"); //���� ���
	scanf_s("%d", &i);			//Ű�� �Է¹޾� i�� ����
	c = high((float)i);			//high �Լ� ȣ��
	printf("%.2lfm�Դϴ�.", c);	//c��� ���
	return 0;					//�Լ� ����
}