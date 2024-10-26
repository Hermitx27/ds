#include <stdio.h>
#include <stdlib.h>
#define MAX 50

int queue[MAX];
int rear = -1;
int front = -1;
int i;

// Initialize the queue
void createQueue() {
    front = rear = -1;
    printf("Queue created successfully\n");
}

// Insert an element into the queue
void insert() {
    int data;
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } else {
        if (front == -1) front = 0; // Set front to 0 if inserting the first element
        printf("Insert the element in queue: ");
        scanf("%d", &data);
        queue[++rear] = data;
        printf("Inserted %d\n", data);
    }
}

// Delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        // Reset the queue if it's empty
        front = rear = -1;
    } else {
        printf("Element deleted from queue is: %d\n", queue[front++]);
        // Reset queue if all elements are deleted
        if (front > rear) {
            front = rear = -1;  
        }
    }
}

// Display all elements in the queue
void display() {
int i;
    if (front == -1) {
	printf("Queue is empty\n");
    } else {
	printf("Queue elements: ");
	for ( i = front; i <= rear; i++) {
	    printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;

    printf("\nMENU\n 1. Create Queue\n 2. Insert\n 3. Delete\n 4. Display\n 5. Exit");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createQueue();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
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
