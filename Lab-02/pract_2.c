#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push()
{
    int val;
    if(top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter integer to push: ");
    scanf("%d", &val);
    stack[++top] = val;
    printf("%d pushed onto stack\n", val);
}

void pop()
{
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

void display()
{
    int i;
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

void checkPalindrome()
{
    int i, isPalindrome = 1;
    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    for(i = 0; i <= top/2; i++)
    {
        if(stack[i] != stack[top-i])
        {
            isPalindrome = 0;
            break;
        }
    }
    if(isPalindrome)
        printf("Stack elements form a palindrome\n");
    else
        printf("Stack elements do NOT form a palindrome\n");
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Check Palindrome\n4.Display\n5.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

