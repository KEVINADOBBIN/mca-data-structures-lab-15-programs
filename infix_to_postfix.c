#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 25

char stack[MAX];
int top = -1;

/* Function declarations */
void push(char ch);
char pop();
int precedence(char ch);

int main()
{
    char infix[MAX] = "x^y/(5*z)+2";
    char ch;
    int i, len;

    push('(');                  // Push '(' at the beginning
    strcat(infix, ")");          // Append ')' at the end
    len = strlen(infix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: ");

    for (i = 0; i < len; i++)
    {
        ch = infix[i];

        if (isalnum(ch))          // Operand
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
                printf("%c", pop());
            pop();                // Pop '('
        }
        else                       // Operator
        {
            while (precedence(ch) <= precedence(stack[top]))
                printf("%c", pop());
            push(ch);
        }
    }

    printf("\n");
    return 0;
}

/* Function to return precedence of operators */
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-': return 1;
    case '*':
    case '/': return 2;
    case '^': return 3;
    default: return 0;
    }
}

/* Push character onto stack */
void push(char ch)
{
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = ch;
}

/* Pop character from stack */
char pop()
{
    if (top < 0)
        return '\0';
    else
        return stack[top--];
}
