#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail;

void create()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the number \n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = tail = newnode;
        tail->next = head;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}
void display()
{
    struct node *temp;
    int count=0;
    temp = head;
    // while (temp->next != head)
    // {
    //     printf("elements are %d\n", temp->data);
    //     temp=temp->next;
    // }
    // printf("elements are %d\n", temp->data);

    do
        {
            printf("Element at %d index is : %d\n", count, temp->data);
            temp = temp->next;
            count++;
        }while(temp!= head);
}
int menu()
{
    int choice;
    printf("\n1. create link list");
    printf("\n2. disply link list");
    printf("\n3. exit\n");
    printf("enter choice : ");
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
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("invalid choice");
            break;
        }
    }
}