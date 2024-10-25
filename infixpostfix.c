#include <stdio.h>
#include <ctype.h>
#define MAX 10

char stack[MAX];
int top = -1;

char pop() {
    if (top == -1) {
        printf("\n Stack is empty");
        return -1; // Return an invalid character
    } else {
        char op = stack[top];
        top--;
        return op;
    }
}

int stackempty() {
    return (top == -1);
}

void push(char op) {
    if (top == MAX - 1)
        printf("\n Stack is full");
    else {
        top++;
        stack[top] = op;
    }
}

int priority(char op) {
    if (op == '^')
        return 3;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void intopost(char in[], char post[]) {
    int i = 0, j = 0;
    char op;
    while (in[i] != '\0') {
        if (isalnum(in[i])) {
            post[j] = in[i];
            j++;
        } else if (in[i] == '(') {
            push(in[i]);
        } else if (in[i] == ')') {
            while (!stackempty() && (op = pop()) != '(') {
                post[j] = op;
                j++;
            }
        } else {  // Operator
            while (!stackempty() && priority(in[i]) <= priority(stack[top])) {
                op = pop();
                post[j] = op;
                j++;
            }
            push(in[i]);
        }
        i++;
    }

    while (!stackempty()) {
        op = pop();
        post[j] = op;
        j++;
    }
    post[j] = '\0';
}

int main() {
    char infix[50];
    char postfix[50];

    printf("\nEnter the expression: \n");
    scanf("%s", infix);

    intopost(infix, postfix);

    printf("\nPostfix = %s\n", postfix);

    return 0;
}
