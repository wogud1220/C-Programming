#include <stdio.h>
//�����͸� ������� ���� swap
/*void swap(int x, int y) {		//swap �Լ��� main �Լ������� x, y�� �޾ƿ���
	int temp;		//	x,y�� ������ �ٲ���
	temp = x;
	x = y;
	y = temp;				
}
int main(void) {	//main �Լ� ����
	int x = 5, y = 20;	//x�� y�� �� ����
	swap(x, y);		//swap �Լ� ȣ��
	printf("%d %d", x, y);	//�ٲ� x, y�� ���
	return 0;		//main �Լ� ����
}*/


//�����͸� ����� swap

/*int swap(int* x, int* y) {//�������� ���� x,y�� �Ű������� �޴� swap�Լ� ����
	int temp = *x;		//x�� �ִ� ���� temp�� �̵�
	*x = *y;			//y�� �ִ� ���� x�� �̵�
	*y = temp;			//y�� �ִ� ���� temp�� �̵�
}

int main(void) {		//main�Լ� ����
	int x, y;			//������ ���� x, y ����
	x = 10, y = 30;		//x�� 10, y�� 30 ����
	printf("���� �� x���� y�� %d %d\n", x, y);	//swap�� x���� y�� ���
	swap(&x, &y);		//x�� y���� �ּҸ� swap�Լ��� �Ű������� �̵�
	printf("���� �� x���� y�� %d %d\n", x, y);	// ���� �� x���� y�� ���
}*/