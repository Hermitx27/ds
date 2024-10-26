#include <stdio.h>
#include <stdlib.h>

// Define Node as a new data type using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create an empty circular linked list
Node* createLinkedList() {
    return NULL;  // Initially, the list is empty
}

// Function to insert a node at the end
Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;

    if (head == NULL) {  // If list is empty, create the first node
        head = newNode;
        newNode->next = head;  // Link it to itself, forming a circular link
    } else {
        Node* temp = head;
        while (temp->next != head) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Link last node to new node
        newNode->next = head;  // Link new node back to head
    }
    printf("Inserted %d at the end.\n", data);
    return head;
}

// Function to display the circular linked list
void display(Node* head) {
Node* temp = head;
    if (head == NULL) {
	printf("List is empty.\n");
	return;
    }

    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // Stop when we loop back to the head
    printf("(back to head)\n");
}

// Function to delete the last node
Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    if (head->next == head) {  // Only one node
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != head) {  // Find the second last node
            temp = temp->next;
        }
        free(temp->next);  // Delete the last node
        temp->next = head;  // Maintain circular structure
    }
    printf("Deleted last node.\n");
    return head;
}

// Main function
int main() {
    Node* head = createLinkedList();  // Initialize an empty circular linked list
    int choice, data;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Delete last\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insert(head, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                head = deleteLast(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
