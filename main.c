#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu() {
    printf("\n==== University Student Management ====\n");
    printf("1. Add Student Details\n");
    printf("2. Find Student by Roll Number\n");
    printf("3. Count the Number of Students\n");
    printf("4. Find the ICP mark of a student\n");
    printf("5. Delete a Student\n");
    printf("6. Update a Student Entry\n");
    printf("7. Exit\n");
}
typedef struct student /*Main Structure to store data of students*/
{
    char name[100];
    int rollno;
    char address[1000];
    int phoneno;
    int marks;
    int isDeleted;
} student;

student students[100];
int studentcount=0;
int testcase(int test)
{
    for (int i=0;i<studentcount;i++)
    {
        if (test==students[i].rollno && students[i].isDeleted!=1)
        return 5;
    }
}

void adddata()
{
    int test;
    printf("Enter Student's Name: ");
    scanf(" %s", students[studentcount].name);
    printf("Enter Student's Roll Number: ");
    scanf("%d",&test);
    int q=testcase(test);
    if (q==5)
    {
        printf("Invalid Roll no.");
    }
    else
    {
        students[studentcount].rollno=test;
        printf("Enter Student's Address: ");
        scanf(" %[^\n]s", students[studentcount].address);
        printf("Enter Student's Phone Number: ");
        scanf("%d", &students[studentcount].phoneno);
        printf("Enter Student's Marks: ");
        scanf("%d", &students[studentcount].marks);
        studentcount++;
        printf("Student added successfully!\n");
    }
}

void finddata(){
    int x;
    int z = 0;
    printf("Enter Roll Number of Student you want to find: ");
    scanf("%d",&x);
    {
        for(int i = 0;i<studentcount;i++)
        {
            if(x==students[i].rollno && students[i].isDeleted!=1)
            {
                z = 1;
                printf("Name :%s\n",students[i].name);
                printf("Roll Number: %d\n",students[i].rollno);
                printf("Address: %s\n",students[i].address);
                printf("Phone Number: %d\n",students[i].phoneno);
                printf("ICP Marks: %d\n",students[i].marks);
            } 
        }
    }
    if(z==0){
        printf("No such student found!");
    }
}

void countdata()
{
    int c = 0;
    for(int i = 0;i<studentcount;i++){
        if(students[i].isDeleted==0){
            c++;
        }
    }
    printf("The total number of students is: %d",c);
}

void findmarks()
{
    int z;
    int x = 0;
    printf("Enter Roll Number of Student you want to find: ");
    scanf("%d",&z);
    for(int i = 0;i<studentcount;i++){
        if(z==students[i].rollno && students[i].isDeleted!=1)
        {
            x = 1;
            printf("ICP Marks: %d\n",students[i].marks);
        }
    }
    if(x==0){
        printf("No such student found!");
    }
}

void deletedata()
{
    int r, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &r);

    for (int i = 0; i < studentcount; i++) {
        if (!students[i].isDeleted && students[i].rollno == r){
            students[i].isDeleted = 1;
            printf("Student with Roll Number %d deleted successfully.\n", r);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll Number %d not found.\n", r);
    }
}

void updatedata()
{
    int ud;
    printf("Enter the roll no of student you want to update data of:");
    scanf("%d",&ud);
    int valid=0;
    int ind;
    for(int i = 0;i<studentcount;i++)
    {
        if(ud==students[i].rollno && students[i].isDeleted!=1)
        {
            valid=1;
            ind=i;
            break;
        }
    }
    int ch;
    printf("\n==== Select the data you want to update ====\n");
    printf("1. Name\n");
    printf("2. Roll Number\n");
    printf("3. Address\n");
    printf("4. Phone Number\n");
    printf("5. ICP Marks\n");
    printf("6. Exit\n");
    if (valid==1)
    {

    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            char x[100];
            printf("The old name is: %s\n",students[ind].name);
            printf("Enter the new name: ");
            scanf("%\ns",&x);
            strcpy(students[ind].name,x);
            printf("Data updated succesfully!!!");
            break;
        case 2:
            printf("The old roll no. is: %d\n",students[ind].rollno);
            printf("Enter the new roll no.: ");
            scanf("%d",&students[ind].rollno);
            printf("\nData updated succesfully!!!");
            break;
        case 3:
            char y[1000];
            printf("The old address is: %s\n",students[ind].address);
            printf("Enter the new address: ");
            scanf("%[^\n]s",&y);
            strcpy(students[ind].address,y);
            printf("\nData updated succesfully!!!");
            break;
        case 4:
            printf("The old phone no. is: %d\n",students[ind].phoneno);
            printf("Enter the new phone no.: ");
            scanf("%d",&students[ind].phoneno);
            printf("\nData updated succesfully!!!");
            break;
        case 5:
            printf("The old ICP Marks: %d\n",students[ind].marks);
            printf("Enter the new ICP marks: ");
            scanf("%d",&students[ind].marks);
            printf("\nData updated succesfully!!!");
            break;
        case 6:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }
    }
    else
    {
        printf("Invalid choice. Please try again.\n");
    }
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
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}