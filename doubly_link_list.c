#include <stdio.h>
#include <stdlib.h>
void display();
void insertAtBeginning();
int length();
struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL, *temp;
void createLinkList()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Element in the link list : ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        /*  temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp; */

        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void insertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the number to add in the list : ");
    scanf("%d", &newnode->data);
    newnode->prev = 0; // * we can use use NULL or 0
    newnode->next = 0;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Element in the link list : ");
    scanf("%d", &newnode->data);
    newnode->prev = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = temp = newnode;
    }
    else
    { 
        // * IMPORTANT => : Time complexity is O(1) // if use while loop then time complexity will be O(n)
        
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}
void insertAtPosition()
{
    int loc,i=1;;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    int len=length();
    printf("lenth of link list is : %d\n",len);
    printf("\nEnter the location you want to insert : ");
    scanf("%d",&loc);
    if(loc < i || loc>len)
    {
        printf("\nInvalid Entry");
    }
    else if(loc==1)
    {
        insertAtBeginning();
    }
    else
    {
        temp=head;
        printf("Enter the number : ");
        scanf("%d",&newnode->data);
        while(i<loc -1)
        {
            temp=temp->next;
            i++;
        }
        newnode->prev=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->next->prev=newnode;
    }
}
int length()
{
    struct node *temp;
    int count =0;
        temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
    return count;
}

void display()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Elements are : %d\n", temp->data);
            temp = temp->next;
        }
    }
}
int menu()
{
    int choice;
    printf("\n1. Add element in doubly link list");
    printf("\n2. Insert or Add element in Beginning doubly link list");
    printf("\n3. Insert or Add element at the End doubly link list");
    printf("\n4. Insert or Add element at the position doubly link list");
    printf("\n5. display doubly link list");
    printf("\n6. End the program\n");
    printf("\n Enter Your choice : ");
    scanf("%d", &choice);
    return choice;
}

int main()
{
    while (1)
    {
        switch (menu())
        {
        case 1:
            createLinkList();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalide choice please enter again");
            break;
        }
    }
}