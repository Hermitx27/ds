#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int stack[MAX];      // Stack array
int top = -1;        // Stack top index

// Function to check if the stack is full
int isStackFull() {
    return top == MAX - 1; 
}

// Function to check if the stack is empty
int isStackEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int data) {
    if (isStackFull()) {
        printf("Stack is full\n");
    } else {
        stack[++top] = data;  // Increment top and add data
        printf("Pushed data: %d\n", data);
    }
}

// Function to pop an element from the stack
void pop() {
    if (isStackEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Popped data: %d\n", stack[top--]);  // Return the top element and decrement top
    }
}

// Function to display all elements in the stack
void display() {
    if (isStackEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to display the top element of the stack
void stackTop() {
    if (isStackEmpty()) {
        printf("Stack is empty\n");
    } else {
        printf("Top of stack: %d\n", stack[top]);
    }
}

// Main function
int main() {
    int choice, data;

    // Display menu options
    printf("\nMENU\n 1. Push\n 2. Pop\n 3. Display\n 4. Stack Top\n 5. Check if Empty\n 6. Check if Full\n 7. Exit");
    
    while (1) { // Infinite loop to continuously execute until exit
        printf("\nEnter your choice: ");
        scanf("%d", &choice); // Read user choice

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data); // Read data to push
                push(data);
                break;
            case 2:
                pop(); // Pop element
                break;
            case 3:
                display(); // Display stack
                break;
            case 4:
                stackTop(); // Show top element
                break;
            case 5:
                if (isStackEmpty()) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
            case 6:
                if (isStackFull()) {
                    printf("Stack is full\n");
                } else {
                    printf("Stack is not full\n");
                }
                break;
            case 7:
                exit(0); // Exit program
            default:
                printf("Invalid choice, please try again\n");
        }
    }

    return 0; // This line will not be reached
}
