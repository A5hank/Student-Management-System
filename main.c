#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[100];
    int rollno;
    char address[1000];
    char phoneno[15]; // Changed to char array
    float marks;      // Changed to float
    int isDeleted;    // 0 = Active, 1 = Deleted
} student;

student students[100];
int studentcount = 0;
const char *FILENAME = "SMS.txt";

void Menu() {
    printf("\n==== University Student Management ====\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Count the Number of Students\n");
    printf("4. Find the ICP Mark of a Student\n");
    printf("5. Delete a Student\n");
    printf("6. Update a Student Entry\n");
    printf("7. Exit\n");
}

void saveToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < studentcount; i++) {
        if (!students[i].isDeleted) {
            fprintf(file, "%s\n%d\n%s\n%s\n%f\n",
                    students[i].name,
                    students[i].rollno,
                    students[i].address,
                    students[i].phoneno,
                    students[i].marks);
        }
    }
    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("No existing data found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, " %[^\n] %d %[^\n] %[^\n] %f",
                  students[studentcount].name,
                  &students[studentcount].rollno,
                  students[studentcount].address,
                  students[studentcount].phoneno,
                  &students[studentcount].marks) == 5) {
        students[studentcount].isDeleted = 0; // Mark as active
        studentcount++;
    }
    fclose(file);
    printf("Data loaded from file successfully.\n");
}

int testcase(int test) {
    for (int i = 0; i < studentcount; i++) {
        if (test == students[i].rollno && students[i].isDeleted == 0) {
            return 1; // Roll number exists
        }
    }
    return 0; // Roll number does not exist
}

void adddata() {
    int test;
    printf("Enter Student's Name: ");
    scanf(" %[^\n]", students[studentcount].name);
    printf("Enter Student's Roll Number: ");
    scanf("%d", &test);

    if (testcase(test)) {
        printf("Error: Roll number already exists.\n");
        return;
    }

    students[studentcount].rollno = test;
    printf("Enter Student's Address: ");
    scanf(" %[^\n]", students[studentcount].address);
    printf("Enter Student's Phone Number: ");
    scanf(" %[^\n]", students[studentcount].phoneno);
    printf("Enter Student's Marks: ");
    scanf("%f", &students[studentcount].marks);

    students[studentcount].isDeleted = 0; // Mark as active
    studentcount++;
    printf("Student added successfully!\n");

    saveToFile();
}

void finddata() {
    int rollno, found = 0;
    printf("Enter Roll Number of Student to Find: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) {
            found = 1;
            printf("\nName: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Address: %s\n", students[i].address);
            printf("Phone Number: %s\n", students[i].phoneno);
            printf("ICP Marks: %.2f\n", students[i].marks);
            break;
        }
    }

    if (!found) {
        printf("No such student found.\n");
    }
}

void countdata() {
    int count = 0;
    for (int i = 0; i < studentcount; i++) {
        if (students[i].isDeleted == 0) {
            count++;
        }
    }
    printf("The total number of students is: %d\n", count);
}

void findmarks() {
    int rollno, found = 0;
    printf("Enter Roll Number to Find ICP Marks: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) {
            found = 1;
            printf("ICP Marks: %.2f\n", students[i].marks);
            break;
        }
    }

    if (!found) {
        printf("No such student found.\n");
    }
}

void deletedata() {
    int rollno, found = 0;
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) {
            students[i].isDeleted = 1; // Mark as deleted
            found = 1;
            printf("Student with Roll Number %d deleted successfully.\n", rollno);
            break;
        }
    }

    if (!found) {
        printf("No such student found.\n");
    } else {
        saveToFile();
    }
}

void updatedata() {
    int rollno, found = 0;
    printf("Enter Roll Number to Update: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) {
            found = 1;

            printf("\n==== Update Menu ====\n");
            printf("1. Name\n");
            printf("2. Address\n");
            printf("3. Phone Number\n");
            printf("4. Marks\n");
            printf("Enter your choice: ");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", students[i].name);
                    break;
                case 2:
                    printf("Enter New Address: ");
                    scanf(" %[^\n]", students[i].address);
                    break;
                case 3:
                    printf("Enter New Phone Number: ");
                    scanf(" %[^\n]", students[i].phoneno);
                    break;
                case 4:
                    printf("Enter New Marks: ");
                    scanf("%f", &students[i].marks);
                    break;
                default:
                    printf("Invalid choice.\n");
                    return;
            }

            printf("Student details updated successfully.\n");
            saveToFile();
            return;
        }
    }

    if (!found) {
        printf("No such student found.\n");
    }
}

int main() {
    loadFromFile();

    int choice;
    while (1) {
        Menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                adddata();
                break;
            case 2:
                finddata();
                break;
            case 3:
                countdata();
                break;
            case 4:
                findmarks();
                break;
            case 5:
                deletedata();
                break;
            case 6:
                updatedata();
                break;
            case 7:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}