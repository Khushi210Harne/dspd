#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newnode;
    int val, count = 0;

    printf("Enter integer elements (Enter 0 to stop):\n");
    while(1)
    {
        scanf("%d", &val);
        if(val == 0)
            break;
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->next = NULL;
        if(head == NULL)
            head = newnode;
        else
        {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
        count++;
    }

    printf("\nLinked List: ");
    temp = head;
    while(temp != NULL)
    {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Number of nodes = %d\n", count);
    return 0;
}

