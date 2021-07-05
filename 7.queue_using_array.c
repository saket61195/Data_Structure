#include <stdio.h>
#include <stdlib.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;
void enqueue(int x)
{
    if (rear == n - 1)
    {
        printf("queue is overflow \n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is underflow \n");
    }
    else
    {
        printf("dequeue elemenet is %d\n", queue[front]);
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is underflow\n");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d\n", queue[i]);
        }
    }
}
void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("queue is underflow\n");
    }
    else
    {
        printf(" peek element is %d\n", queue[front]);
    }
}
int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);
    enqueue(20);
    enqueue(25);
    enqueue(45);
    // peek();
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    peek();
    display();
    enqueue(95);
    enqueue(95);
    enqueue(95);
    enqueue(95);
    enqueue(95);
    display();
}