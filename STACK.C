#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int stack[MAX]; // Stack array
int top = -1;   // Stack top index
// Initialize the stack
void createStack() {
    top = -1;
    printf("Stack created successfully\n");
}
// Push an element onto the stack
void push(int data) {
    if (top == MAX - 1) {
	printf("Stack is full\n");
    } else {
	stack[++top] = data;
	printf("Pushed data: %d\n", data);
    }
}
// Pop an element from the stack
void pop() {
    if (top == -1) {
	printf("Stack is empty\n");
    } else {
	printf("Popped data: %d\n", stack[top--]);
    }
}
// Display all elements in the stack
void display() {
int i;
    if (top == -1) {
	printf("Stack is empty\n");
    } else {
	printf("Stack elements: ");
	for ( i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
// Main function
int main() {
    int choice, data;
    printf("\nMENU\n 1. Create Stack\n 2. Push\n 3. Pop\n 4. Display\n 5. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createStack();
                break;
            case 2:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 3:
                pop();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice, please try again\n");
        }
    }
    return 0;
}
