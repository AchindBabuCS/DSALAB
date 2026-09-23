#include <stdio.h>

int top = -1;
int max = 4;
int st[5];

void printStack()
{
    if (top == -1)
    {
        printf("Stack: [ Empty ]\n");
        return;
    }
    printf("Stack: [");
    for (int i = 0; i <= top; i++)
    {
        printf("%d", st[i]);
        if (i < top)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

void push(int x)
{
    if (top == max)
    {
        printf("Stack Overflow!\n");
    }
    else
    {
        top++;
        st[top] = x;
        printf("%d pushed into stack.\n", x);
        printStack();
    }
}

int pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        int y = st[top];
        top--;
        return y;
    }
}

int peek()
{
    if (top == -1)
    {
        return -1;
    }
    return st[top];
}

int main()
{
    int i = 0, j = 0, k = 0;
    while (k == 0)
    {
        printf("\n1:push 2:pop 3:peek 4:exit\n");
        printf("Enter option to execute: ");
        scanf("%d", &i);
        if (i == 1)
        {
            printf("Enter element: ");
            scanf("%d", &j);
            push(j);
        }
        else if (i == 2)
        {
            int g = pop();
            if (g == -1)
            {
                printf("Stack Underflow!\n");
            }
            else
            {
                printf("Popped element: %d\n", g);
                printStack();
            }
        }
        else if (i == 3)
        {
            int p = peek();
            if (p == -1)
            {
                printf("Stack Underflow! (Stack is empty)\n");
            }
            else
            {
                printf("Top element: %d\n", p);
            }
        }
        else
        {
            printf("Exiting...\n");
            break;
        }
    }
    return 0;
}