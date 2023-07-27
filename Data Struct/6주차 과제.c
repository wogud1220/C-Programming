#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (((a)>(b))?(a):(b))
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100

char infixstr[100];
char postfixStr[100];


typedef int element;       // typedef char element;
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

// 연산자의 우선순위를 반환한다.
int prec(char op)
{
    switch (op) {
    case '(': case ')': return 0;
    case '&': case '|': return 1;
    case '>': case '<': return 2;
    case '+': case '-': return 3;

    case '*': case '/': case'%': return 4;

    case '^': return 5;
   
    
    }
    return -1;
}
int eval(char str[]) {      //후위 표기식 연산
    StackType s;
    init_stack(&s);
    int op1, op2, value, i = 0;
    int len = strlen(str);
    char ch;

    for (i = 0; i < len; i++) {
        ch = str[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '^' && ch != '>' && ch != '<' && ch != '=' && \
            ch != '&' && ch != '|' && ch !='%') {          //배열의 인덱스에 들어온 값이 숫자라면 (피연산자)
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
            case '^':push(&s, pow(op1, op2)); break;
            case '%':push(&s, op1 % op2); break;
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

// 중위 표기 수식 -> 후위 표기 수식

void infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    int cnt = 0;
    StackType s;
    init_stack(&s); // 스택 초기화

    for (i = 0; i < len; i++) {

        ch = exp[i];

        switch (ch) {

        case '+': case '-': case '*': case '/': case'%':
        case '^': case '>': case '<': case '&':case'|':// 연산자를 만나면+ 나머지 연산자

            // 스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력

            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                if (ch == '^') {
                    //push(&s, ch);
                    break;
                }
                postfixStr[cnt] = peek(&s);
                cnt++;
                printf("%c", pop(&s));
            }
            push(&s, ch);

            break;

        case '(': // 왼쪽 괄호를 만나면
            
            push(&s, ch);

            break;

        case ')': // 오른쪽 괄호를 만나면

            top_op = pop(&s);

            // 왼쪽 괄호를 만날때까지 출력

            while (top_op != '(') {
                postfixStr[cnt] = top_op;
                cnt++;
               
                printf("%c", top_op);

                top_op = pop(&s);

            }

            break;

        default: // 피연산자를 만나면
            postfixStr[cnt] = ch;
            cnt++;
            printf("%c", ch);

            break;


        }

    }

    while (!is_empty(&s)) {   // 스택에 남은 연산자들을  pop 순서대로 출력
        postfixStr[cnt] = peek(&s);
        cnt++;
        printf("%c", pop(&s));
    }




}



int main() {    // 중위표기 문자열 입력하고,

    StackType s;
    init_stack(&s);
    int gstr[100];
    int result;
    while (strcmp(infixstr, "quit")) {
    printf("중위표기 문자열을 입력하세요. quit를 입력하면 종료.\n");
    scanf("%s", infixstr);
    infix_to_postfix(infixstr);  //함수내에서 팝해서 출력
    puts("");
    result= eval(postfixStr); //배열로 넘겨줘야함
    printf("계산결과: %d\n\n", result);
 }

    return 0;


}
