//아래의 코드를 참조하여 ???을 대신할 수 있는 매개변수 선언을 추가해보자.



void SimpleFuncOne(int *arr1, int *arr2);

void SimpleFuncTwo(int (*arr3)[4], int (*arr4)[4]);

int main(void) {

  int arr1[3];

  int arr2[4];

  int arr3[3][4];

  int arr4[2][4];



  SimpleFuncOne(arr1, arr2);

  SimpleFuncTwo(arr3, arr4);

return 0;

}