#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void GetScore();
void GetSumOfPerson();
void GetSumOfSubject();

int main()
{
    int score[5][5];
    int i, j;
    GetScore(score);
    GetSumOfPerson(score);
    GetSumOfSubject(score);
    printf("\n점수표:\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
            printf("%d ", score[i][j]);
        printf("\n");
    }
}

void GetScore(int score[5][5])
{
    printf("점수를 입력해주세요:\n");
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            scanf("%d", &score[i][j]);
    }
}

void GetSumOfPerson(int score[5][5])
{
    int i, j, sum_p = 0;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == 4)
            {
                score[i][j] = sum_p;
                sum_p = 0;
                break;
            }
            sum_p += score[i][j];
        }
    }
}

void GetSumOfSubject(int score[5][5])
{
    int i, j, sum_s = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (j == 4)
            {
                score[j][i] = sum_s;
                sum_s = 0;
                break;
            }
            sum_s += score[j][i];
        }
    }
}