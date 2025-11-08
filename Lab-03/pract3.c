
#include<stdio.h>
#include<stdlib.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert()
{
    char ch;
    if(rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter character to insert: ");
    scanf(" %c", &ch);
    if(front == -1)
        front = 0;
    queue[++rear] = ch;
    printf("%c inserted into queue\n", ch);
}

void delete()
{
    if(front == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted element: %c\n", queue[front++]);
    if(front > rear)
        front = rear = -1;
}

void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for(i = front; i <= rear; i++)
        printf("%c ", queue[i]);
    printf("\n");
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

