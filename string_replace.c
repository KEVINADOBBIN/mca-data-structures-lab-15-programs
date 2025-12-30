#include <stdio.h>
#include <string.h>

int main()
{
    char s2[30] = "are beautiful";
    char pattern[] = "are";
    char replace[] = "is";
    char result[30];

    int i = 0, j = 0, k = 0;
    int found = 0;

    printf("String before replace: %s\n", s2);

    while (s2[i] != '\0')
    {
        /* Check for pattern match */
        if (s2[i] == pattern[0])
        {
            j = 0;
            while (pattern[j] != '\0' && s2[i + j] == pattern[j])
                j++;

            if (pattern[j] == '\0')
            {
                /* Pattern found */
                found = 1;
                printf("Pattern found at index: %d\n", i);

                /* Copy replacement string */
                j = 0;
                while (replace[j] != '\0')
                    result[k++] = replace[j++];

                i += strlen(pattern);
                continue;
            }
        }

        result[k++] = s2[i++];
    }

    result[k] = '\0';

    if (found)
        printf("String after replace: %s\n", result);
    else
        printf("Pattern not found\n");

    return 0;
}
