#include<stdio.h>
#define MAX 10
int stack[MAX];
int top = -1;
void createstack(){
    top = -1;
    printf("Stack created successfully ");v
}
void push(){
    int data;
    if(top == MAX -1){
	printf("Stack is full");
    }
    else{
	printf("Enter data to pushed in stack");
	scanf("%d"  ,&data );
	stack[++top]  = data;
	printf("Pushed data: %d\n" , data);
    }
}
void pop(){
    if(top == -1){
	printf("Stack is empty");
    }
    else{
	printf("pop element: %d" , stack[top--]);
    }
}
void display(){
    int i;
    if(top == -1){
	printf("Stack is empty");
    }
    else{
	for(i=0;i<=top;i++){
	    printf("%d" , stack[i]);
	}
    }
}
void main(){
    int choice;
    printf("Select operation to perform on stack\n");
    printf("Menu\n 1. Create\n 2.Push \n 3.Pop \n 4.Display \n 5.Exit\n");
    while(1){
	printf("enter choice:\n");
	scanf("%d" , &choice);
	switch(choice){
	    case 1: createstack(); break;
	    case 2: push(); break;
	    case 3: pop(); break;
	    case 4: display(); break;
	    case 5: exit(0); break;
	    default: printf("Invalid choice");
	}
    }

}

