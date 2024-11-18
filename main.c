#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu() {
    printf("\n==== University Student Management ====\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Count the Number of Students\n");
    printf("4. Delete a Student\n");
    printf("5. Update a Student Entry\n");
    printf("6. Exit\n");
}
typedef struct student /*Main Struucture to store data of students*/
{
    char name[100];
    int rollno;
    char address[1000];
    int phoneno;
    int marks;
} student;

student students[100];
int studentcount=0;

void adddata()
{
    printf("Enter Student's Name: ");
    scanf(" %s", students[studentcount].name);
    printf("Enter Student's Roll Number: ");
    scanf("%d", &students[studentcount].rollno);
    printf("Enter Student's Address: ");
    scanf(" %[^\n]s", students[studentcount].address);
    printf("Enter Student's Phone Number: ");
    scanf("%d", &students[studentcount].phoneno);
    printf("Enter Student's Marks: ");
    scanf("%d", &students[studentcount].marks);
    studentcount++;
    printf("Student added successfully!\n");
}

void finddata(){
    int x;
    printf("Enter Roll Number of Student you want to find: ");
    scanf("%d",&x);
    for(int i = 0;i<studentcount;i++){
        if(x==students[i].rollno){
            printf("Name :%s\n",students[i].name);
            printf("Roll Number: %d\n",students[i].rollno);
            printf("Address: %s\n",students[i].address);
            printf("Phone Number: %d\n",students[i].phoneno);
            printf("ICP Marks: %d\n",students[i].marks);
        }
        else{
            printf("No such student found");
        }
    }
}

int countdata()
{
    printf("%d",(studentcount+1));
}

void updatedata()
{
    printf("Enter Student's Name: ");
    scanf(" %s", students[studentcount].name);
    printf("Enter Student's Roll Number: ");
    scanf("%d", &students[studentcount].rollno);
    printf("Enter Student's Address: ");
    scanf(" %[^\n]s", students[studentcount].address);
    printf("Enter Student's Phone Number: ");
    scanf("%d", &students[studentcount].phoneno);
    printf("Enter Student's Marks: ");
    scanf("%d", &students[studentcount].marks);
    studentcount++;
    printf("Student added successfully!\n");
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
                finddata();
                break;
            case 3:
                countdata();
                break;
            case 4:
                deletedata();
                break;
            case 5:
                updatedata();
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}