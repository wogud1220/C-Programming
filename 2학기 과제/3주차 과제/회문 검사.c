#include<stdio.h>
voidPalindrome(char *p);
intmain(void)
{
    char word[50];
    printf("word: ");   
    scanf("%s", word);  
    Palindrome(word);
    return 0;
}
voidPalindrome(char *p)
{
    int i,count=0,len=0;
    for(i=0;p[i]!=0;i++)
    {
        len+=1;
    }
    for(i=0;i<len/2;i++)
    {
        if(p[i]==p[len-i-1])  
        {
            count++;    
            if(count>=len/2)    
                printf("회문입니다.");    
        }
        else    
        {
            printf("회문이 아닙니다.");
            break;
        }
    }
}

/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int JudgePalindrome(char str[]);

int main()
{
    char str[100];
    scanf("%s", str);
    if (JudgePalindrome(str) == 1) printf("회문 입니다.");
    else printf("회문이 아닙니다.");
}

int JudgePalindrome(char str[])
{
    int len = 0, judge;
    for (int i = 0; str[i] != '\0'; i++) len++;
    for (int i = 0; i <= len / 2; i++)
    {
        if (str[i] == str[len - 1 - i]) judge = 1;
        else
        {
            judge = 0;
            break;
        }
    }
    return judge;
}*/