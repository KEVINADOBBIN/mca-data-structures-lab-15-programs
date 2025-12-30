#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void stringLength();
void stringConcat();
void substring();

/* Global variables */
char s1[25] = "Flowers";
char s2[25] = "are beautiful";
char substr[20];

int main()
{
    int ch;

    while (1)
    {
        printf("\n\nEnter your choice:");
        printf("\n1. Find length of s1");
        printf("\n2. Concatenate s1 and s2");
        printf("\n3. Extract substring \"low\" from s1");
        printf("\n4. Exit\n");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            stringLength();
            break;

        case 2:
            stringConcat();
            break;

        case 3:
            substring();
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice");
        }
    }

    return 0;
}

/* Function to find length of s1 */
void stringLength()
{
    int i = 0;
    while (s1[i] != '\0')
        i++;

    printf("The length of s1 is %d\n", i);
}

/* Function to concatenate s1 and s2 */
void stringConcat()
{
    int i = 0, j = 0;

    while (s1[i] != '\0')
        i++;

    s1[i++] = ' ';

    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';

    printf("The concatenated string is: %s\n", s1);
}

/* Function to extract substring "low" from s1 */
void substring()
{
    int start = 1;  // position of 'l' in "Flowers"
    int len = 3;
    int i;

    for (i = 0; i < len; i++)
        substr[i] = s1[start + i];

    substr[i] = '\0';

    printf("The substring is: %s\n", substr);
}
