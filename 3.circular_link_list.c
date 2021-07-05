#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *tail;

void create()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the number : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
}
void insertAtbeg()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("enter the number : ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertAtIndex()
{
    struct node *newnode;
    int loc;
}
void display()
{
    struct node *temp;
    int count = 0;
    temp = tail;
    if (tail == NULL)
    {
        printf("list is empty");
    }
    else
    {
        do
        {
            printf("Element at %d index is : %d\n", count, temp->data);
            temp = temp->next;
            count++;
        } while (temp != tail);
    }
}

int menu()
{
    int choice;
    printf("\n1. create link list");
    printf("\n2. disply link list");
    printf("\n3. exit");
    printf("\n4. Insert At beg ");
    printf("\n5. Insert At index \n");
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
        case 4:
            insertAtbeg();
            break;
        case 5:
            insertAtIndex();
            break;
        default:
            printf("invalid choice");
            break;
        }
    }
}