#include <stdio.h>

int stack[100];
int top = -1;

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[100], ch;
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        if (ch >= '0' && ch <= '9')
            push(ch - '0');

        else
        {
            b = pop();
            a = pop();

            if (ch == '+')
                push(a + b);
            else if (ch == '-')
                push(a - b);
            else if (ch == '*')
                push(a * b);
            else if (ch == '/')
                push(a / b);
        }
    }

    printf("Result: %d", pop());

    return 0;
}
