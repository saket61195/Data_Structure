#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = 0;
    if (front == 0 && rear == 0)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    struct node *temp;
    temp = front;
    if (front == 0)
    {
        printf("queue is underflow\n");
    }
    else
    {
        printf("dequeue element is %d\n", front->data);
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    temp = front;
    if (front == 0)
    {
        printf("queue is underflow\n");
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
void peek()
{
    if (front == 0)
    {
        printf("queue is underflow\n");
    }
    else
    {
        printf("peek element is %d\n", front->data);
    }
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    display();
    peek();
    dequeue();
    peek();
    display();
}