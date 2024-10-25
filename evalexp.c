#include<stdio.h>
#include<ctype.h>
#define MAX 10

float stack[MAX];
int top = -1;

int stackfull() {
    return (top == MAX - 1);
}

int stackempty() {
    return (top == -1);
}

void push(float val) {
    if (stackfull()) {
        printf("Stack is full\n");
    } else {
        top++;
        stack[top] = val;
    }
}

float pop() {
    if (stackempty()) {
        printf("Stack is empty\n");
        return -1;  // Return a default invalid value to handle empty case
    } else {
        float val = stack[top];
        top--;
        return val;
    }
}

float evaluatepost(char exp[]) {
    int i = 0;
    float op1, op2, value;

    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push((float)(exp[i] - '0'));
        } else {
            op2 = pop();
            op1 = pop();
            switch (exp[i]) {
                case '+':
                    value = op1 + op2;
                    break;
                case '-':
                    value = op1 - op2;
                    break;
                case '*':
                    value = op1 * op2;
                    break;
                case '/':
                    value = op1 / op2;
                    break;
                case '%':
                    value = (int)op1 % (int)op2;
                    break;
                default:
                    printf("Invalid operator encountered: %c\n", exp[i]);
                    return -1;  // Return invalid result on error
            }
            push(value);
        }
        i++;
    }
    return pop();
}

int main() {
    float val;
    char exp[50];

    printf("\nEnter the postfix expression: ");
    scanf("%s", exp);

    val = evaluatepost(exp);

    if (val != -1) {  // Only print if valid result
        printf("\nValue of postfix expression: %.2f\n", val);
    }

    return 0;
}
