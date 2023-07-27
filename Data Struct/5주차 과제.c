#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100


typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수

void push(StackType* s, element item)

{

    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;

}



// 삭제함수

element pop(StackType* s)

{

    if (is_empty(s)) {

        fprintf(stderr, "스택 공백 에러\n");

        exit(1);

    }

    else return s->data[(s->top)--];

}



// 피크함수

element peek(StackType* s)

{

    if (is_empty(s)) {


        fprintf(stderr, "스택 공백 에러\n");

        exit(1);

    }

    else return s->data[s->top];

}

// ===== 스택 코드의 끝 =====


int check_matching(const char *in)

{

    StackType s;
    int cnt = 1;
    char ch, open_ch;
    int i, n = strlen(in);   // n= 문자열의 길이

    init_stack(&s); // 스택의 초기화
    for (i = 0; i < n; i++) {

        ch = in[i]; // ch = 다음 문자

        switch (ch) {

        case '(':   case '[':    case '{':

            push(&s, cnt);      //괄호가 열릴때마다 몇번째 괄호인지  스택에 저장함
            printf("%d", cnt);  //괄호가 몇개 열렸는지 출력
            cnt++;      //cnt는 그냥 괄호가 들어올 때마다 추가해줘야함    

            break;

        case ')':   case ']':    case '}':
            ;
            if (is_empty(&s))  return 0;

            else {

                open_ch = pop(&s);
                printf("%d", open_ch);  //닫히는 괄호가 들어온다면 스택의 top의 번호를 가져옴


                if ((open_ch == '(' && ch != ')') ||

                    (open_ch == '[' && ch != ']') ||

                    (open_ch == '{' && ch != '}')) {

                    return 0;

                }

                break;

            }

        }

    }

    if (!is_empty(&s)) return 0; // 스택에 남아있으면 오류

    return 1;

}


int eval(char str[]) {      //후위 표기식 연산
    StackType s;
    init_stack(&s);
    int op1, op2, value, i = 0;
    int len = strlen(str);
    char ch;
    
    for (i = 0; i < len; i++) {
        ch = str[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch!='^' && ch!='>' && ch!='<' && ch!='='&&\
            ch !='&' && ch!='|') {          //배열의 인덱스에 들어온 값이 숫자라면 (피연산자)
            value = ch - '0';
            push(&s, value);        //숫자를 스택에 쌓음
        }
        else {                  //연산자라면
            op2 = pop(&s);      // 3 저장되고 + 연산자라면 top에서 op2 뽑고  
            op1 = pop(&s);      // 2                 그 다음 하나줄어든 top에서 op1 뽑고
            switch (ch) {           //각 연산자에맞는 걸 수행하고 계산한 값을 스택 s에 푸시함
            case '+':push(&s, op1 + op2); break;
            case '-':push(&s, op1 - op2); break;
            case '*':push(&s, op1 * op2); break;
            case '/':push(&s, op1 / op2); break;
            case '^':push(&s, pow(op1,op2)); break;
            case '>':
                if (op1 > op2) {
                    push(&s, 1);
                    break;
                }
                else
                    push(&s, 0); break;

            case '<':
                if (op1 < op2) {
                    push(&s, 1);
                    break;
                }
                else {
                    push(&s, 0);
                    break;
                }
            case '=':
                if (op1 == op2) {
                    push(&s, 1);
                    break;
                }
                else {
                    push(&s, 0);
                    break;
                }
            case '&':           //case '&' (op1&&op2)  :push(&s,op&&op2);
                if (op1 && op2 == 1)
                    push(&s, 1);
                else
                    push(&s, 0);
                break;
            case '|':
                if (op1 || op2 == 1)
                    push(&s, 1);
                else
                    push(&s, 0);
                break;
            }
        }
    }
    return pop(&s);
}
int express(char str[]) {   //연속된 문자열 압축
    StackType s;
    StackType prints;
    init_stack(&s);
    init_stack(&prints);
    int len = strlen(str);
    int i = 0;
    int cnt;
    printf("알파벳 개수는 %d\n", len);

    while(str[i]!=NULL) {
        cnt = 1;
        while (str[i] == str[i+1] || //연속된 문자
            str[i] == str[i+1] + 32 || //연속된 대소문자
            str[i] == str[i+1] - 32) {
            i++;
            cnt++;          //동일한 알파벳이 몇개인지 셈
        }
        push(&s, cnt + '0');//알파벳 개수 푸시 %c로 나타나야해서char
        if (str[i] >= 'a' && str[i] <= 'z')//소문자일때
            push(&s, str[i]);       //그냥 푸시
        else //대문자일때 
            push(&s, str[i] + 32);//소문자로 변환 후 푸시
        i++;       //연속된 문자가 아니여도 그 다음 문자로 가야하니!!
    }

    while (!is_empty(&s))   //s 구조체에 뭔가 들어있다면
    {
        push(&prints, pop(&s));//s에서 뽑아서 ps에 저장
        //abc를 팝하면 cab가 출력이되어서 역순으로 출력해주려고 
    }
    while (!is_empty(&prints))//prins에 뭔가 있으[면
    {
        printf("%c", pop(&prints));
    }
    puts("");


    return 0;
}

int main(void) {
    StackType s;
    int num = 0;
    int result;
    char hu_str[100];
    char str[100];
    char p[100];

    while (num!=-1) {
        printf("문제 번호를 입력하세요  -1은 종료\n");
        scanf(" %d", &num, 1);
        switch (num) {

        case 1:
            printf("식을 입력하세요");
            puts("");
            scanf("%s", p);
            if (check_matching(p) == 1)
                printf("\n괄호 검사 성공\n");
            else
                printf("실패 ");
            puts("\n");
            break;
        case 2:

            printf("후위 표기식을 입력하세요\n");
            scanf("%s", hu_str);
            result = eval(hu_str);
            printf("%d\n", result);
            continue;

        case 3:
            printf("문자열을 입력하세요\n");
            scanf("%s", str);
            express(str);

        default:
            break;
        }
    }


    return 0;
}