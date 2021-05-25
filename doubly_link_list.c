#include <stdio.h>
#include <stdlib.h>
void display();
void insertAtBeginning();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition();
int length();
struct node
{
    int data;
    struct node *prev, *next;
};
struct node *head = NULL, *tail;
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
        head = tail = newnode;
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

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
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
        head = tail = newnode;
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
        head = tail = newnode;
    }
    else
    {
        // * IMPORTANT => : Time complexity is O(1) // if use while loop then time complexity will be O(n)

        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}
void insertAtPosition()
{
    int loc, i = 1;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int len = length();
    printf("lenth of link list is : %d\n", len);
    printf("\nEnter the location you want to insert : ");
    scanf("%d", &loc);
    if (loc < i || loc > len)
    {
        printf("\nInvalid Entry");
    }
    else if (loc == 1)
    {
        insertAtBeginning();
    }
    else
    {
        temp = head;
        printf("Enter the number : ");
        scanf("%d", &newnode->data);
        while (i < loc - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}
void insertAfterPosition()
{
    int loc, i = 1;
    ;
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int len = length();
    printf("lenth of link list is : %d\n", len);
    printf("\nEnter the location you want to insert : ");
    scanf("%d", &loc);
    if (loc < i || loc > len)
    {
        printf("\nInvalid Entry");
    }
    else if (loc == len)
    {
        insertAtEnd();
    }
    else
    {
        temp = head;
        printf("Enter the number : ");
        scanf("%d", &newnode->data);
        while (i < loc)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}
void deleteAtBeginning()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("\nList is empty\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = NULL; //temp->next=NULL
        free(temp);
    }
}
void deleteAtEnd()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(temp);
    }
}

void deleteAtIndex()
{
    int loc, i = 1;
    struct node *temp;
    int len = length();
    printf("lenth of link list is : %d\n", len);
    printf("\nEnter the location you want to delete : ");
    scanf("%d", &loc);
    if (loc < i || loc > len)
    {
        printf("\nInvalid Entry");
    }
    else if (loc == 1)
    {
        deleteAtBeginning();
    }
    else
    {
        temp = head;
        while (i < loc)
        {
            temp = temp->next;
            i++;
        }
        if (temp->next == NULL)
        {
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
        }
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
    }
}
void reverse()
{
    struct node * current,*nextnode;
    current=head;
    while(current!=NULL)
    {
    nextnode=current->next;
    current->next=current->prev;
    current->prev=nextnode;
    current=nextnode;
    }
    current=head;
    head=tail;
    tail=current;
}

int length()
{
    struct node *temp;
    int count = 0;
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
    printf("\n5. Insert or Add element After position doubly link list");
    printf("\n6. delete element at the Beginning doubly link list");
    printf("\n7. delete element at the end doubly link list");
    printf("\n8. delete element at the Location doubly link list");
    printf("\n9. display doubly link list");
    printf("\n10. reverse doubly Link List");
    printf("\n11. End the program\n");
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
            insertAfterPosition();
            break;
        case 6:
            deleteAtBeginning();
            break;
        case 7:
            deleteAtEnd();
            break;
        case 8:
            deleteAtIndex();
            break;
        case 9:
            display();
            break;
        case 10:
            reverse();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nInvalide choice please enter again");
            break;
        }
    }
}