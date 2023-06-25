// キーボードから計算式を入力し答えを出せ(計算式が間違ってる場合はエラーを出力、演算は*/+-)

// 目的  

// アルゴリズム、プログラミングの醍醐味。

// C code to convert infix to postfix expression

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


//store operators
typedef struct {
    char data[SIZE];
    int top;
} Stack;


int IsOperator(char element);
void InitStack(Stack *S);
int IsFull(Stack S);
int IsEmpty(Stack S);
void Push(Stack *S, char element);
char Pop(Stack *S);
int CheckPriority(char element);
int InfixToPostfix(Stack *postfix, char expression[SIZE]);
void CalcPostfix(Stack postfix);

int main(){
    char expression[SIZE];
    Stack postfix;

    printf("Enter an infix expression: ");
    // gets(expression);
    
    strcpy(expression, "1-2*32-5/5");
    puts(expression);

    InitStack(&postfix);

    if(InfixToPostfix(&postfix, expression) == 0){
        puts(postfix.data);

        CalcPostfix(postfix);
    }

	return 0;
}

int IsOperator(char element){
    return (element == '+' || element == '-' || element == '*'  ||element == '/');
}

void InitStack(Stack *S){
    S->top = -1;
}

int IsFull(Stack S){
    return S.top < SIZE -1;
}

int IsEmpty(Stack S){
    return S.top == -1;
}

void Push(Stack *S, char element){
    if(IsFull(*S) == 0){
        puts("you cannot push.");
    }else{
        S->data[++S->top] = element;
    }
}

char Pop(Stack *S) {
    if (IsEmpty(*S) == 1) {
        puts("you cannot pop.");
        return ' ';
    } else {
        return S->data[S->top--];
    }
}


int CheckPriority(char element){
    int ret = 0;
    
    if (element == '*' || element == '/') {
        ret = 1;
    }

    return ret;
}


int InfixToPostfix(Stack *postfix, char expression[SIZE]){
    int i, flag = 0, continuousOpe = 0, continuousNum = 0;
    Stack operator;

    InitStack(&operator);
    
    for (i = 0; i < strlen(expression); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            //put space to seperate numbers. 1 digit or more digits 
            if (continuousNum == 0) {
                Push(postfix, ' ');
                Push(postfix, expression[i]);
                continuousNum = 1;
            } else {
                Push(postfix, expression[i]);
                continuousNum = 1;
            }
            continuousOpe = 0;
        } else if (IsOperator(expression[i]) != 0) {
            //priority is * /
            while(operator.top > -1 && CheckPriority(operator.data[operator.top]) >= CheckPriority(expression[i])){
                Push(postfix, Pop(&operator));
            }
            Push(&operator, expression[i]);
            continuousOpe = 1;
            continuousNum = 0;
        } else {
            puts("please input correct expression");
            flag = 1;
            break;
        }
    }

    while (operator.top > -1) {
        Push(postfix, Pop(&operator));
    }

    return flag;
}

void CalcPostfix(Stack postfix){
    Stack operandStack;
    int i, operand = 0;
    char current;
    InitStack(&operandStack);


    for (i = 0; i <= postfix.top; i++) {
        current = postfix.data[i];

        if (isspace(current)) {
            continue;
        }
            
        if (isdigit(current)) {
            operand = 0;

            // numbers more than 2 digits in string to int
            while (isdigit(current)) {
                operand = operand * 10 + (current - '0');
                current = postfix.data[++i];
            }
            Push(&operandStack, operand);

            //incremented i in while, but decrement because i will be incremented in for loop
            i--;
        } else if (IsOperator(current)) {
            int operand2 = Pop(&operandStack);
            int operand1 = Pop(&operandStack);
            int result;

            switch (current) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    break;
            }

            Push(&operandStack, result);
        } else {
            printf("Invalid expression.\n");
        }
    }

    printf("result : %d", Pop(&operandStack));

}