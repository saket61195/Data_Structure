#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
struct stack *top = NULL;

void push()
{
    struct stack *newnode;
    newnode = (struct stack *)malloc(sizeof(struct stack));
    printf("enter the number ");
    scanf("%d", &newnode->data);
    newnode->next = top;
    top = newnode;
}
void pop()
{
    struct stack *temp;
    temp = top;
    if (top == 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("pop element is %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("top element of the stack is %d\n", top->data);
    }
}

void display()
{
    struct stack *temp;
    temp = top;
    if (top == 0)
    {
        printf("stack is empty\n");
    }
    else
    {
        while (temp != 0)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}
int menu()
{
    int choice;
    printf("\n1. enter the element you want to insert");
    printf("\n2. check peek element ");
    printf("\n3. enter the element to pop ");
    printf("\n4. display stack");
    printf("\n5. exit");
    printf("\n enter your choice ");
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
            peek();
            break;
        case 3:
            pop();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("please inter valid key");
            break;
        }
    }
}