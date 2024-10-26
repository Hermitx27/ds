#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1, rear = -1;

// Create and initialize the circular queue
void createQueue() {
    front = rear = -1;
    printf("Circular queue created successfully\n");
}

// Insert an element into the circular queue
void insert(int item) {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;  // Initialize both front and rear
    } else {
        rear = (rear + 1) % MAX;  // Circular increment
    }
    cqueue_arr[rear] = item;
    printf("Inserted %d\n", item);
}

// Delete an element from the circular queue
void deletion() {
    if (front == -1) {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue: %d\n", cqueue_arr[front]);
    if (front == rear) {
        // Queue is now empty
        front = rear = -1;  
    } else {
        front = (front + 1) % MAX;  // Circular increment
    }
}

// Display all elements in the circular queue
void display() {
int i;
    if (front == -1) {
	printf("Queue is empty\n");
	return;
    }
    printf("Queue elements: ");
    i = front;
    while (1) {
        printf("%d ", cqueue_arr[i]);
        if (i == rear) break;  // Stop if we reach the rear
        i = (i + 1) % MAX;  // Wrap around if needed
    }
    printf("\n");
}

// Main function
int main() {
    int choice, item;
    createQueue(); // Create the circular queue first

    do {
        printf("\n1. Create Queue\n2. Insert\n3. Delete\n4. Display\n5. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createQueue(); // Create or reinitialize the circular queue
                break;
            case 2:
                printf("Input the element for insertion: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 3:
                deletion();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 5);
    
    return 0;
}
