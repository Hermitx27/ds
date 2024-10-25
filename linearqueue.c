#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

typedef struct lq {
    int front;
    int rear;
    int data[SIZE];
} queue;

void display(queue *);

void enqueue(queue *q, int val) {
    printf("\nFront:%d \tRear:%d", q->front, q->rear);
    if (q->rear == SIZE - 1)
        printf("\n Queue is full");
    else {
        if (q->rear == -1 && q->front == -1) {
            q->front = 0;
            q->rear = 0;
        } else {
            q->rear++;
        }
        q->data[q->rear] = val;
    }
    printf("\t\tFront:%d \tRear:%d", q->front, q->rear);
    printf("\nQueue: ");
    display(q);
}

void dequeue(queue *q) {
    int val;
    printf("\nBefore Dequeue process: \tAfter Dequeue process:");
    printf("\nFront:%d \tRear:%d", q->front, q->rear);
    if (q->rear == -1 && q->front == -1)
        printf("\n Queue is empty !");
    else {
        val = q->data[q->front];
        q->front++;
        printf("\t\tFront:%d \tRear:%d\n", q->front, q->rear);
        printf("Dequeued element: %d", val);
    }
}

void display(queue *q) {
    int i;
    if (q->rear == -1 && q->front == -1)
        printf("\n Queue is empty !");
    else {
        for (i = q->front; i <= q->rear; i++)
            printf("%d ", q->data[i]);
    }
}

void getfront(queue *q) {
    int val;
    if (q->rear == -1 && q->front == -1)
        printf("\n Queue is empty !");
    else {
        val = q->data[q->front];
        printf("\nFront:%d", q->front);
        printf("\nElement at front:%d", val);
    }
}

void getrear(queue *q) {
    int val;
    if (q->rear == -1 && q->front == -1)
        printf("\n Queue is empty !");
    else {
        val = q->data[q->rear];
        printf("\nRear:%d", q->rear);
        printf("\nElement at rear:%d", val);
    }
}

void qempty(queue *q) {
    if (q->rear == -1 && q->front == -1)
        printf("\n Queue is empty !");
    else
        printf("\n Queue is not empty");
}

void qfull(queue *q) {
    if (q->rear == SIZE - 1)
        printf("\n Queue is full");
    else
        printf("\n Queue is not full");
}

int main() {
    queue *q = (queue *)malloc(sizeof(queue)); // Allocate memory for queue
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if memory allocation fails
    }
    
    q->rear = q->front = -1; // Initialize front and rear
    int ch, val;

    do {
        printf("\nMENU \n1. Enqueue \t 2. Dequeue \n3. Display");
        printf("\t 4. Getfront \n5. Getrear \t 6. Queueempty");
        printf("\n7. Queuefull \t 8. Exit \nEnter your choice:");
        scanf("%d", &ch);
        
        switch (ch) {
            case 1:
                printf("\nEnter data :");
                scanf("%d", &val);
                enqueue(q, val);
                break;

            case 2:
                dequeue(q);
                break;

            case 3:
                display(q);
                break;

            case 4:
                getfront(q);
                break;

            case 5:
                getrear(q);
                break;

            case 6:
                qempty(q);
                break;

            case 7:
                qfull(q);
                break;

            case 8:
                free(q); // Free allocated memory before exiting
                exit(0);
        }
    } while (1); // This will continue until you manually exit by selecting option 8.

    return 0;
}
