#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

void Menu() {
    printf("\n==== University Student Management ====\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Find ICP Marks of a Student\n");
    printf("4. Count the Number of Students\n");
    printf("5. Delete a Student\n");
    printf("6. Update a Student Entry\n");
    printf("7. Exit\n");
}

typedef struct /*Main Struucture to store data of students*/
{
    char name[100];
    int rollno;
    char address[1000];
    int phoneno;
    int marks;
} student;

student students[MAX_STUDENTS];
int studentCount=0;


void adddata(char name[],int rollno,char address[],int phoneno,int marks)
{
    student s1;
    strcpy(s1.name,name);
    s1.rollno=rollno;
    strcpy(s1.address,address);
    s1.phoneno=phoneno;
    s1.marks=marks;
}


int countstudents()
{
    
}

int main(){
    int choice;
    while(1){
        Menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                adddata();
                break;
            case 2:
                findStudentByRollNo();
                break;
            case 3:
                findICPMarks();
                break;
            case 4:
                countStudents();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                updateStudent();
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