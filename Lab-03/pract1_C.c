
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
    char name[50];
    int roll;
    float avgMarks;
};

void addStudents(struct Student s[], int *n)
{
    int i;
    printf("Enter number of students: ");
    scanf("%d", n);
    for(i=0;i<*n;i++)
    {
        printf("Enter name of student %d: ", i+1);
        scanf("%s", s[i].name);
        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);
        printf("Enter average marks: ");
        scanf("%f", &s[i].avgMarks);
    }
}

void bubbleSort(struct Student s[], int n)
{
    int i, j;
    struct Student temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(s[j].avgMarks < s[j+1].avgMarks)
            {
                temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
            }
        }
    }
}

void displayStudents(struct Student s[], int n)
{
    int i;
    if(n==0)
    {
        printf("No students to display\n");
        return;
    }
    printf("\nStudents sorted by Avg Marks (Descending):\n");
    printf("Name\tRoll\tAvg Marks\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].avgMarks);
    }
}

int main()
{
    struct Student students[100];
    int n=0, choice;
    while(1)
    {
        printf("\nMenu:\n1.Add Students\n2.Display Sorted Students\n3.Exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addStudents(students, &n);
                bubbleSort(students, n);
                break;
            case 2:
                displayStudents(students, n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

