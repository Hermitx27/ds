#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Student structure
struct Student {
    int rollno;
    char name[50];
    float marks;
    struct Student* next;
};

// Function to create a new student node
struct Student* createStudent(int rollno, const char* name, float marks) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollno = rollno;
    strcpy(newStudent->name, name);
    newStudent->marks = marks;
    newStudent->next = newStudent; // Point to itself for circularity
    return newStudent;
}

// Function to insert a record in sorted order
void insertRecord(struct Student** head, int rollno, const char* name, float marks) {
    struct Student* newStudent = createStudent(rollno, name, marks);
    if (*head == NULL) { // If the list is empty
        *head = newStudent;
    } else {
        struct Student* current = *head;
        struct Student* prev = NULL;
        do {
            if (current->rollno > rollno) break; // Found the position to insert
            prev = current;
            current = current->next;
        } while (current != *head);
        
        if (prev == NULL) { // Insert before head
            struct Student* last = *head;
            while (last->next != *head) last = last->next;
            last->next = newStudent;
            newStudent->next = *head;
            *head = newStudent; // Update head
        } else { // Insert in between or at the end
            newStudent->next = current;
            prev->next = newStudent;
        }
    }
}

// Function to display the database
void displayDatabase(struct Student* head) {
    struct Student* temp = head;
    if (head == NULL) {
        printf("Database is empty.\n");
        return;
    }
    do {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollno, temp->name, temp->marks);
        temp = temp->next;
    } while (temp != head);
}

// Function to delete a record
void deleteRecord(struct Student** head, int rollno) {
    struct Student* current = *head;
    struct Student* prev = NULL;
    if (*head == NULL) {
        printf("Database is empty.\n");
        return;
    }
    do {
        if (current->rollno == rollno) {
            if (prev == NULL) { // Deleting the head
                if (current->next == *head) { // Only one node
                    free(current);
                    *head = NULL;
                } else {
                    struct Student* last = *head;
                    while (last->next != *head) last = last->next;
                    last->next = current->next;
                    *head = current->next;
                    free(current);
                }
            } else {
                prev->next = current->next;
                free(current);
            }
            printf("Record with Roll No %d deleted.\n", rollno);
            return;
        }
        prev = current;
        current = current->next;
    } while (current != *head);
    printf("Record with Roll No %d not found.\n", rollno);
}

// Main function
int main() {
    struct Student* studentDB = NULL; // Initialize the database
    int choice;

    do {
        printf("\nStudent Database Menu:\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Insert Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int rollno;
            char name[50];
            float marks;
            printf("Enter Roll No: ");
            scanf("%d", &rollno);
            printf("Enter Name: ");
            scanf(" %[^\n]s", name);
            printf("Enter Marks: ");
            scanf("%f", &marks);
            insertRecord(&studentDB, rollno, name, marks);
        } else if (choice == 2) {
            displayDatabase(studentDB);
        } else if (choice == 3) {
            int rollno;
            char name[50];
            float marks;
            printf("Enter Roll No: ");
            scanf("%d", &rollno);
            printf("Enter Name: ");
            scanf(" %[^\n]s", name);
            printf("Enter Marks: ");
            scanf("%f", &marks);
            insertRecord(&studentDB, rollno, name, marks);
        } else if (choice == 4) {
            int rollno;
            printf("Enter Roll No to delete: ");
            scanf("%d", &rollno);
            deleteRecord(&studentDB, rollno);
        } else if (choice == 5) {
            printf("Exiting the program.\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free all allocated memory before exit
     while (studentDB) {
         deleteRecord(&studentDB, studentDB->rollno);
     }

    return 0;
}
