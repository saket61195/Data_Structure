#include <stdio.h>
#include <stdlib.h>
#define n 5
int stack[n];
int top = -1;

void push(char item)
{
    if (top == n - 1)
    {
        printf("stack is overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("stack is underflow");
    }
    else
    {
        return (stack[top]--);
    }
}
int parenthesis_match(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')

        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            if (top == -1)
            {
                printf("stack is underflow");
            }
            else
            {
                pop();
            }
        }
    }
    if (top == -1) /*stack empty*/
    {
        printf("Balanced Parentheses\n");
        return 1;
    }
    else
    {
        printf("not match\n");
        return 0;
    }
}

int main()
{
    char exp[n];
    int valid;
    printf("Enter an algebraic expression : ");
    scanf("%[^\n]s",exp);
    if (parenthesis_match(exp))
    {
        printf("\nThe parenthesis is matching\n");
    }
    else
    {
        printf("\nThe parenthesis is not matching\n");
    }
}