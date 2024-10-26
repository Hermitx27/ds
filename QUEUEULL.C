#include <stdio.h>
#include <stdlib.h>

// Define the node structure with typedef
typedef struct node {
    int val;
    struct node *next;
} node;

node *front = NULL; // Initialize front to NULL
node *rear = NULL;  // Initialize rear to NULL

// Function to create and initialize the queue
void createQueue() {
    front = NULL; // Set front to NULL
    rear = NULL;  // Set rear to NULL
    printf("Queue created.\n");
}

// Function to enqueue an element at the rear of the queue
void enqueue() {
    int val;
    node *newNode = (node *)malloc(sizeof(node)); // Create a new node
    if (newNode == NULL) {
        printf("Not able to enqueue the element.\n");
        return;
    }
    printf("Enter the value: ");
    scanf("%d", &val);
    newNode->val = val;
    newNode->next = NULL; // New node will point to NULL

    if (rear == NULL) {
        // If queue is empty, both front and rear point to the new node
        front = newNode;
        rear = newNode;
    } else {
        // Link the new node to the last node and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("Item enqueued: %d\n", val);
}

// Function to dequeue an element from the front of the queue
void dequeue() {
int item;
node *temp=front;
    if (front == NULL) {
	printf("Underflow\n");
	return;
    }
 item = front->val;

    front = front->next; // Move front to the next node

    if (front == NULL) {
        // If the queue is now empty, also reset rear
        rear = NULL;
    }
    free(temp); // Free the old front
    printf("Item dequeued: %d\n", item);
}

// Function to display all elements in the queue
void display() {
    node *temp = front; // Start from front
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Printing Queue elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->val);
        temp = temp->next; // Move to the next node
    }
}

int main() {
    int choice = 0;
    printf("\n********* Queue operations using linked list *********\n");
    printf("\n----------------------------------------------\n");

    // Create the queue initially
    createQueue();

    while (choice != 5) {
        printf("\n\nChoose one from the below options...\n");
        printf("\n1. Enqueue\n2. Dequeue\n3. Show\n4. Create Queue\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                createQueue();  // Call to create a new queue
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
