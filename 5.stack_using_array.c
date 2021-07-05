#include <stdio.h>
#include <stdlib.h>
#define N 5 //declare a macro

int stack[N];
int top = -1;

void push()
{
    int x;
    printf("enter the number you want to insert ");
    scanf("%d", &x);
    if (top == N - 1)
    {
        printf("stack is overflow ");
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    int item;
    if (top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        item = stack[top];
        top--;
        printf("pop item is %d\n", item);
    }
}

void peek()
{
    if (top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        printf("current top iten is %d\n", stack[top]);
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("stack is underflow\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%d\n", stack[i]);
        }
    }
}

int menu()
{
    int choice;
    printf("\n1. Push operation ");
    printf("\n2. Pop operation ");
    printf("\n3. peek operation ");
    printf("\n4. display stack ");
    printf("\n5. exit from program\n");
    printf("\n Please enter your choice ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}
int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("please enter valid choice\n");
            break;
        }
    }
}