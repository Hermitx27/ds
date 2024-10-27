#include <stdio.h>
#define MAX 10

int queue[MAX];
int rear = -1;
int front = -1;
int i;

void createqueue()
{
    front = rear = -1;
    printf("Queue is created.\n");
}

void enqueue()
{
    int data;
    if (rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
            front = 0;
        printf("Enter Element to enqueue.\n");
        scanf("%d", &data);
        queue[++rear] = data;
        printf("Enqueue Element: %d", data);
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Element dequeue: %d", queue[front++]);
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (front == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        int i;
        for (i = front; i <= rear; i++)
        {
            printf("%d", queue[i]);
        }
        printf("\n");
    }
}

void main()
{

    int choice;
    printf("menu \n 1.create \n 2. enqueue \n 3. dequeue \n 4.display \n 5.exit");
    while (1)
    {
        printf("Enter operation to perform:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createqueue();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}