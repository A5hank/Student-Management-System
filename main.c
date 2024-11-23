#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Programer defined structure for student details
typedef struct student 
{
    char name[100]; //Student Name- Can be Full name
    int rollno; //Student roll number. Should be unique
    char address[1000];
    char phoneno[15]; 
    float marks;      
    int isDeleted;    // 0 = Active, 1 = Deleted
} student;

student students[100]; // Array to save student data in stack before saving in Secondary memory
int studentcount = 0;
const char *FILENAME = "SMS.txt"; // File Name in which data is saved in secondary storage.

// Main menu visible to user on running the program 
void Menu() 
{
    printf("\n==== University Student Management ====\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Count the Number of Students\n");
    printf("4. Find the ICP Mark of a Student\n");
    printf("5. Delete a Student\n");
    printf("6. Update a Student Entry\n");
    printf("7. Exit\n");
}

//Function to save file in Secondary Memory
void saveToFile() 
{
    FILE *file = fopen(FILENAME, "w");
    if (!file) 
    {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < studentcount; i++) 
    {
        if (!students[i].isDeleted) 
        {
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


//Funtion to load data from Secondary Storage
void loadFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) 
    {
        printf("No existing data found. Starting fresh.\n");
        return;
    }

    while (fscanf(file, " %[^\n] %d %[^\n] %[^\n] %f", students[studentcount].name, &students[studentcount].rollno, students[studentcount].address, students[studentcount].phoneno, &students[studentcount].marks) == 5) 
    {
        students[studentcount].isDeleted = 0; // Mark as active
        studentcount++; //Counting number of students 
    }
    fclose(file);
    printf("Data loaded from file successfully.\n");
}

// Function to stop repetition of Roll number of students
int testcase(int test) 
{
    for (int i = 0; i < studentcount; i++) 
    {
        if (test == students[i].rollno && students[i].isDeleted == 0) 
        {
            return 1; // Roll number exists
        }
    }
    return 0; // Roll number does not exist
}

//Function to let user enter data of students
void adddata() 
{
    int test; //Variable to test roll number 
    printf("Enter Student's Name: ");
    scanf(" %[^\n]", students[studentcount].name);
    printf("Enter Student's Roll Number: ");
    scanf("%d", &test);
    //Testing roll number for uniquness
    if (testcase(test)) //Function call inside if statement 
    { 
        printf("Error: Roll number already exists.\n");
        return;
    }

    students[studentcount].rollno = test;
    printf("Enter Student's Address: ");
    scanf(" %[^\n]", students[studentcount].address);
    printf("Enter Student's Phone Number: ");
    scanf(" %[^\n]", students[studentcount].phoneno);
    printf("Enter Student's ICP Marks: ");
    scanf("%f", &students[studentcount].marks);

    students[studentcount].isDeleted = 0; // Marks student as active
    studentcount++;
    printf("Student added successfully!\n");

    saveToFile(); //Function call - Adds updated data of file to secondary memory
}

//Function to find user by roll number
void finddata() 
{
    int rollno;
    int found = 0; //Variable to check if student is found or not. 1=found 0=not found
    printf("Enter Roll Number of Student to Find: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) 
    {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) 
        {
            found = 1;
            //Printing details of student 
            printf("\nName: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Address: %s\n", students[i].address);
            printf("Phone Number: %s\n", students[i].phoneno);
            printf("ICP Marks: %.2f\n", students[i].marks);
            break;
        }
    }

    if (!found) 
    { 
        printf("No such student found.\n");
    }
}

//Function to see number of students(Undeleted)
void countdata() 
{
    int count = 0;
    for (int i = 0; i < studentcount; i++) 
    {
        if (students[i].isDeleted == 0) 
        {
            count++;
        }
    }
    printf("The total number of students is: %d\n", count);
}

//Function to find ICP marks of a student given roll numbe
void findmarks() 
{
    int rollno;
    int found = 0; //Variable to check if student is found or not. 1=found 0=not found
    //Taking roll number as input from user.
    printf("Enter Roll Number to Find ICP Marks: ");
    scanf("%d", &rollno); 

    for (int i = 0; i < studentcount; i++) 
    {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) 
        {
            found = 1;
            printf("ICP Marks: %.2f\n", students[i].marks);
            break;
        }
    }

    if (!found) 
    {
        printf("No such student found.\n");
    }
}

// Function to delete a student without moving elements in an array.
void deletedata() 
{
    int rollno, found = 0;
    //Taking roll number as input from user.
    printf("Enter Roll Number to Delete: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) 
    {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) 
        {
            students[i].isDeleted = 1; // Mark as deleted
            found = 1; //Marks Student as found
            printf("Student with Roll Number %d deleted successfully.\n", rollno);
            break;
        }
    }

    if (!found) 
    {
        printf("No such student found.\n"); 
    } 
    else 
    {
        saveToFile();  //Function call - Adds updated data of file to secondary memory
    }
}


//Function to  update stident details given current roll number
void updatedata() 
{
    int rollno, found = 0;
    //Taking roll number as input from user.
    printf("Enter Roll Number to Update: ");
    scanf("%d", &rollno);

    for (int i = 0; i < studentcount; i++) 
    {
        if (rollno == students[i].rollno && students[i].isDeleted == 0) 
        {
            found = 1; //Marks student as found

            //Showing options to user which are available for updation
            printf("\n==== Update Menu ====\n");
            printf("1. Name\n");
            printf("2. Address\n");
            printf("3. Phone Number\n");
            printf("4. Marks\n");
            
            //Asking user to choose a field for updation 
            printf("Enter your choice: ");
            int choice;
            scanf("%d", &choice);

            //Conditions based on user choice
            switch (choice) 
            {
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
            return; //Function call - Adds updated data of file to secondary memory
        }
    }

    if (!found) 
    {
        printf("No such student found.\n");
    }
}


int main() 
{
    loadFromFile(); // Function call- Loading exisiting data from Secondary memory

    //Displaying main Menu Until Exit is chosen
    int choice;
    while (1) 
    {
        Menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
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