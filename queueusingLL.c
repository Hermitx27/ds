#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

void enqueue() {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    if (rear) { // Check if the queue is not empty
        rear->next = newNode; // Link the new node at the end
    } else { // Queue is empty
        front = newNode; // Initialize front if it's the first node
    }
    
    rear = newNode; // Update rear to the new node
    printf("Front: %d, Rear: %d\n", front->data, rear->data);
}

void dequeue() {
      node *temp = front; // Temporarily store the front node
    int back = front->data; // Get the data from the front node
    front = front->next; // Move front to the next node
    if (!front) { // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }

  
    if (!front) { // If the queue is now empty
        rear = NULL; // Reset rear as well
    }
    
    free(temp); // Free the memory allocated for the front node
    printf("%d deleted\n", back);
    if (front) {
        printf("Front: %d, Rear: %d\n", front->data, rear->data);
    } else {
        printf("Queue is now empty\n");
    }
}

void display() {
    node *temp = front;
    if (!temp) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp) {
        printf("%d\n", temp->data);
        temp = temp->next; // Move to the next node
    }
}

void queueempty() {
    if (!front) {
        printf("Queue is empty\n");
    } else {
        printf("Queue is not empty\n");
    }
}

void getfront() {
    if (front) {
        printf("Frontmost element: %d\n", front->data);
    } else {
        printf("Queue is empty\n");
    }
}

void getrear() {
    if (rear) {
        printf("Rearmost element: %d\n", rear->data);
    } else {
        printf("Queue is empty\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nMenu:\n1. Enqueue\n2. Dequeue\n3. Display\n4. Check if queue is empty\n5. Get front\n6. Get rear\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: queueempty(); break;
            case 5: getfront(); break;
            case 6: getrear(); break;
            case 7: printf("Exiting...\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}
