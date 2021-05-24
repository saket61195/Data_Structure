#include <stdio.h>
#include <stdlib.h>
void insertAtbeginning();
void insertAtEnd();
void insertAtIndex();
void createlist();
void Display();
int countfunction();
struct node
{
    int data;
    struct node *next;
};
struct node *Head = NULL;

void insertAtBeginning()
{
    struct node *temp, *Newnode;
    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of link list\n");
    scanf("%d", &Newnode->data);
    Newnode->next = NULL;
    if (Head == NULL)
    {
        Head = Newnode;
    }
    else
    {
        temp = Head;
        Newnode->next = temp;
        Head = Newnode;
    }
}
void createList()
{
    struct node *temp, *Newnode;
    int choice = 1;
    // while (choice)
    // {

    Newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data of link list\n");
    scanf("%d", &Newnode->data);
    Newnode->next = NULL;
    if (Head == NULL)
    {
        Head = Newnode;
    }
    else
    {
        temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = Newnode;
    }
    // printf("Do you want to add more data ? enter 0 or 1\n");
    // scanf("%d", &choice);
    // }
}

void insertAtIndex()
{
    struct node *Newnode, *temp;
    int index, i = 1;
    int count = countfunction();
    printf("count = %d\n", count);
    printf("Enter the index where you want to insert node in the link list : ");
    scanf("%d", &index);
    Newnode = (struct node *)malloc(sizeof(struct node));
    if (Head == NULL)
    {
        printf("\nList is empty\n");
    }
    else
    {
        if (index < i || index > count)
        {
            printf("invalid index");
        }
        else if (index == 1)
        {
            insertAtBeginning();
        }
        else
        {
            temp = Head;
            while (i < index - 1)
            {
                temp = temp->next;
                i++;
            }
            printf("\nEnter the element in the List: ");
            scanf("%d", &Newnode->data);
            Newnode->next = temp->next;
            temp->next = Newnode;
        }
    }
}

void insertAtEnd()
{
    createList();
}

void deleteAtBeginning()
{
    struct node *temp;
    if (Head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        temp = Head;
        Head = Head->next;
        free(temp);
    }
}

void deleteAtEnd()
{
    struct node *temp, *previous;
    temp = Head;
    if (Head == NULL)
    {
        printf("\nList is Empty\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == Head)
        {
            Head = NULL;
        }
        else
        {
            previous->next = NULL;
        }
        free(temp);
    }
}
void deleteAtIndex()
{
    struct node *temp, *nextnode;
    int index, i = 1;
    int count = countfunction();
    printf("count = %d\n", count);
    printf("\nEnter the index you want to delete: ");
    scanf("%d", &index);
    if (Head == NULL)
    {
        printf("\nList is empty\n");
    }
    if (index < i || index > count)
    {
        printf("\nInvalid Entry");
    }
    else if (index == 1)
    {

        deleteAtBeginning();
    }
    else
    {
        temp = Head;
        while (i < index - 1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}
void reverse()
{
    struct node *currnode, *nextnode, *prevnode;
    prevnode = NULL;
    currnode = nextnode = Head;
    while (nextnode != NULL)
    {
        nextnode = nextnode->next;
        currnode->next = prevnode;
        prevnode = currnode;
        currnode = nextnode;
    }
    Head = prevnode;
}

void search()
{
    struct node *temp;
    int value, count = 0, flag;
    printf("\nEnter the number you want to search in link list\n");
    scanf("%d", &value);
    if (Head == NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        temp = Head;
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                printf("\nElement %d found at index %d\n", value, count);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            temp = temp->next;
            count++;
        }
        if (flag == 1)
        {
            printf("\nElement not found in the list\n");
        }
    }
}
void Display()
{
    struct node *temp;
    if (Head == NULL)
    {
        printf("\nlist is empty\n");
    }
    else
    {
        int count = 1;
        temp = Head;
        while (temp != NULL)
        {
            printf("Element at %d index is : %d\n", count, temp->data);
            temp = temp->next;
            count++;
        }
    }
}
int countfunction()
{
    struct node *temp;

    int count = 0;
    temp = Head;
    while (temp != NULL)
    {
        // printf("Element at %d index is : %d\n", count, temp->data);
        temp = temp->next;
        count++;
    }
    return count;
}
int menu()
{
    int choice;
    printf("\n1. Add value to the list ");
    printf("\n2. Insert At the Biginnning");
    printf("\n3. Insert At the End");
    printf("\n4. Insert At the Index");
    printf("\n5. Traverse/View Link List");
    printf("\n6. Delete from the Beginning");
    printf("\n7. Delete from the End");
    printf("\n8. Delete from the Index");
    printf("\n9. Reverse the Link List");
    printf("\n10. search Element in the Link List");
    printf("\n11. End the program\n");
    printf("\nEnter your choice : ");
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
            createList();
            break;
        case 2:
            insertAtBeginning();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtIndex();
            break;
        case 5:
            Display();
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
            reverse();
            break;
        case 10:
            search();
            break;
        case 11:
            exit(0);
            break;
        default:
            printf("\nPlease Enter valid Choice\n");
        }
    }
}
