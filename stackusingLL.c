#include <stdio.h>
#include <stdlib.h>

// Define the node structure with typedef
typedef struct node {
    int val;
    struct node *next;
} node;

node *head = NULL; // Initialize head to NULL

// Function to create the stack (initialize head)
void createStack() {
    head = NULL; // Set head to NULL, indicating an empty stack
    printf("Stack created.\n");
}

void push() {
    int val;
    node *newNode = (node *)malloc(sizeof(node)); // Using 'node' directly
    if (newNode == NULL) {
        printf("Not able to push the element.\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &val);
        newNode->val = val;
        newNode->next = head; // Link new node to the previous head
        head = newNode; // Update head to point to the new node
        printf("Item pushed: %d\n", val);
    }
}

void pop() {
    int item;
    node *ptr;
    if (head == NULL) {
        printf("Underflow\n");
    } else {
        item = head->val;
        ptr = head;
        head = head->next; // Move head to the next node
        free(ptr); // Free the old head
        printf("Item popped: %d\n", item);
    }
}

void display() {
    node *ptr = head; // Start from head
    if (ptr == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Printing Stack elements:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->val);
            ptr = ptr->next; // Move to the next node
        }
    }
}

int main() {
    int choice = 0;
    printf("\n********* Stack operations using linked list *********\n");
    printf("\n----------------------------------------------\n");
    
    // Create the stack initially
    createStack();

    while (choice != 5) {
        printf("\n\nChoose one from the below options...\n");
        printf("\n1. Push\n2. Pop\n3. Show\n4. Create Stack\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                createStack();  // Call to create a new stack
                break;
            case 5:
                printf("Exiting....\n");
                break;
            default:
                printf("Please Enter a valid choice\n");
                break;
        }
    }
    return 0;
}
