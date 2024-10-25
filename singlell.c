#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    float marks;
    struct Student* next;
};

// Function to create a new student record
struct Student* createStudent(int rollno, const char* name, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollno = rollno;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = NULL;
    return newStudent;
}

// Function to insert a new record
void insertRecord(struct Student** head, int rollno, const char* name, float marks) {
    struct Student* newStudent = createStudent(rollno, name, marks);
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next) temp = temp->next;
        temp->next = newStudent;
    }
}

// Function to display the student database
void displayDatabase(struct Student* head) {
    if (!head) {
        printf("The database is empty.\n");
        return;
    }
    printf("\nStudent Database:\n");
    for (struct Student* temp = head; temp; temp = temp->next) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollno, temp->name, temp->marks);
    }
}

// Function to delete a record
void deleteRecord(struct Student* head, int rollno) {
    struct Student* temp = head;
    struct Student* prev = NULL;

    while (temp && temp->rollno != rollno) {
        prev = temp;
        temp = temp->next;
    }
    
    if (!temp) {
        printf("Record with Roll No %d not found.\n", rollno);
        return;
    }
    
    if (prev) {
        prev->next = temp->next;  // Non-head node case
    } else {
        head = temp->next;         // Head node case
    }
    free(temp);
    printf("Record with Roll No %d deleted.\n", rollno);
}

// Function to reverse the linked list
void reverseList(struct Student** head) {
    struct Student *prev = NULL, *current = *head, *next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("The list has been reversed.\n");
}

// Main function
int main() {
    struct Student* head = NULL;
    int choice, rollno;
    char name[50];
    float marks;

    while (1) {
        printf("\n1. Insert a new record\n2. Display database\n3. Delete a record\n4. Reverse List\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter Roll No: ");
                scanf("%d", &rollno);
                printf("Enter Name: ");
                scanf(" %[^\n]s", name);
                printf("Enter Marks: ");
                scanf("%f", &marks);
                insertRecord(&head, rollno, name, marks);
                printf("Record inserted.\n");
                break;
            case 2:
                displayDatabase(head);
                break;
            case 3:
                printf("Enter Roll No to delete: ");
                scanf("%d", &rollno);
                deleteRecord(head, rollno);
                break;
            case 4:
                reverseList(&head);
                break;
            case 5:
                // Free all nodes before exiting
                while (head) {
                    struct Student* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
