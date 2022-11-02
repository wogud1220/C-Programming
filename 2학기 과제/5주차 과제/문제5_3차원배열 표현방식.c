#include <stdio.h>

intmain()
{
    int arr[2][2][2]={1,2,3,4,5,6,7,8};
    printf("%d\n",arr[1][0][1]);

    printf("1. (*(arr+1))[0][1]: %d\n",(*(arr+1))[0][1]);
    printf("2. (*(*(arr+1)+0))[1]: %d\n",(*(*(arr+1)+0))[1]);
    printf("3. (*(*(*(arr+1))+0)+1): %d\n",(*(*(*(arr+1))+0)+1));
    printf("4. (*arr[1]+0)[1]: %d\n",(*arr[1]+0)[1]);
    printf("4. (*arr[1][0]+1): %d\n",(*arr[1][0]+1));
}