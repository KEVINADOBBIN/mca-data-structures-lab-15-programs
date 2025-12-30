#include <stdio.h>

/* Function declarations */
void push(int x);
int pop();
void display();

/* Global variables */
int stack[20];
int top = -1;

int main()
{
    int n1;

    /* Push elements */
    push(5);
    push(9);
    push(34);
    push(17);
    push(32);

    display();

    printf("\nTop elements deleted:\n");

    n1 = pop();
    printf("%d is popped\n", n1);

    n1 = pop();
    printf("%d is popped\n", n1);

    n1 = pop();
    printf("%d is popped\n", n1);

    return 0;
}

/* Push operation */
void push(int x)
{
    stack[++top] = x;
}

/* Pop operation */
int pop()
{
    return stack[top--];
}

/* Display stack elements */
void display()
{
    int ind = top;

    printf("\nThe elements in the stack are:\n");
    while (ind != -1)
    {
        printf("%d\n", stack[ind]);
        ind--;
    }
}
