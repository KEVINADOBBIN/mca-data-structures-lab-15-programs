#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 15

int stack[MAX];
int top = -1;

/* Function declarations */
void push(int val);
int pop();

int main()
{
    char postfix[MAX] = "53+82-*";
    char ch;
    int i, n1, n2, result;

    printf("Postfix expression: %s\n", postfix);

    for (i = 0; i < strlen(postfix); i++)
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            push(ch - '0');  // Convert char to int
        }
        else
        {
            n1 = pop();
            n2 = pop();

            switch (ch)
            {
            case '+':
                result = n2 + n1;
                break;
            case '-':
                result = n2 - n1;
                break;
            case '*':
                result = n2 * n1;
                break;
            case '/':
                result = n2 / n1;
                break;
            default:
                printf("Invalid operator\n");
                exit(1);
            }

            push(result);
        }
    }

    printf("Result of the expression %s is: %d\n", postfix, pop());

    return 0;
}

/* Push function */
void push(int val)
{
    if (top >= MAX - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = val;
}

/* Pop function */
int pop()
{
    if (top < 0)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}
