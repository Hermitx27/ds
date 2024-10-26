#include <stdio.h>
#include <stdlib.h>

// Define Node as a new data type using typedef
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create an empty linked list
Node* createLinkedList() {
    return NULL;  // Initially, the list is empty
}

// Function to insert a node at the end
Node* insert(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {  // If list is empty, make new node the head
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Link the last node to the new node
    }
    printf("Inserted %d at the end.\n", data);
    return head;
}

// Function to display the linked list
void display(Node* head) {
Node* temp=head;
    if (head == NULL) {
	printf("List is empty.\n");
	return;
    };
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to delete the last node
Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return head;
    }

    if (head->next == NULL) {  // If there's only one node
        free(head);
        head = NULL;
    } else {
        Node* temp = head;
        while (temp->next->next != NULL) {  // Find second last node
            temp = temp->next;
        }
        free(temp->next);  // Delete the last node
        temp->next = NULL;
    }
    printf("Deleted last node.\n");
    return head;
}

// Main function
int main() {
    Node* head = createLinkedList();  // Initialize an empty linked list
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
