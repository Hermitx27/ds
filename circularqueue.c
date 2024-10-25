#include <stdio.h>
#define MAX 5

int cqueue_arr[MAX];
int front = -1, rear = -1;

void insert(int item) {
    // Check for overflow
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        // Initialize both front and rear
        front = rear = 0;  
    } else {
        rear = (rear + 1) % MAX;  // Circular increment
    }
    cqueue_arr[rear] = item;
}

void deletion() {
    // Check for underflow
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

void getfront() {
    if (front != -1) {
        printf("Front element: %d\n", cqueue_arr[front]);
    } else {
        printf("Queue is empty\n");
    }
}

void getrear() {
    if (rear != -1) {
        printf("Rear element: %d\n", cqueue_arr[rear]);
    } else {
        printf("Queue is empty\n");
    }
}

void checkFull() {
    if ((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue is full\n");
    } else {
        printf("Queue is not full\n");
    }
}

void checkEmpty() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", cqueue_arr[i]);
        if (i == rear) break;  // Stop if we reach the rear
        i = (i + 1) % MAX;  // Wrap around if needed
    }
    printf("\n");
}

int main() {
    int choice, item;
    do {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Get front\n5. Get rear\n6. Check if full\n7. Check if empty\n8. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Input the element for insertion: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                getfront();
                break;
            case 5:
                getrear();
                break;
            case 6:
                checkFull();  // Updated function name
                break;
            case 7:
                checkEmpty(); // Updated function name
                break;
            case 8:
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 8);
    
    return 0;
}
