#define _CRT_SECURE_NO_WARNINGS
//문제4. 
#include<stdio.h>
int main(void)
{
    int arr[10];
    int* pf = arr, * pb = &arr[9];
    int n, i;
    for (i = 0; i < 10; i++)
    {
        printf("int: ");
        scanf("%d", &n);
        if (n % 2 == 0)
        {
            *pb = n;
            pb--;
        }
        else
        {
            *pf = n;
            pf++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/*#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int arr[10];
	int* p = &arr[0];
	int* pb = &arr[9];
	int i = 0;
	int n = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &n);
		if (arr[i] % 2 == 0) {
			*pb = n;
			pb--;
		}
		else{
			*p = n;
			p++;
		}
	}
	for (i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	}

*/