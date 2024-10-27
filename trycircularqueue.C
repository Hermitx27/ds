#include<stdio.h>
#define MAX 10

int cir_queue[MAX];
int rear = -1;
int front = -1;

void createQueue(){
    front = rear = -1;
    printf("Circular Queue IS Created");
}

void enqueue(){
int data;
    if((rear == MAX -1 && front==0) || (front == rear + 1))
    {
	printf("Circular Queue is full");
    }else{
	if(front == -1) front =0;

        printf("Enter Data to Push");
        scanf("%d" , &data);
        rear = (rear + 1)% MAX;
	cir_queue[rear] = data;
        printf("Element pushed: %d" , data );
    }
}
void dequeue(){
    if(front == -1){
        printf("Circular Queue is empty");
       
    }
    else{
        printf("Dequeue element: %d" , cir_queue[front]);
        if(front == rear){
            front = rear = -1;
        }else{
        front = (front + 1)% MAX;}
    }
}
void display(){
int i;
    if(front == -1){
	printf("Queue is empty");
    }else{
        printf("Queue elements: ");
	for(i = front; ;i=(i + 1)% MAX){
	    printf("%d" , cir_queue[i]);
	    if(i == rear) break;
        }
        printf("\n");
    }
}

void main(){
    int choice;
    printf("menu \n 1.create queue\n2.push\n3pop\n4display\n5 exit");
    while(1){
        printf("enter choice;");
        scanf("%d" , &choice);

        switch(choice){
            case 1: createQueue(); break;
            case 2: enqueue(); break;
            case 3: dequeue(); break;
            case 4: display(); break;
            case 5: exit(0); break;
            default:printf("Invalid choice");
        }
    }
}