#include <stdio.h>

/* Function declaration */
int gcd(int a, int b);

int main()
{
    int a = 4, b = 6, c = 8;

    printf("Program to print GCD of 3 numbers\n");
    printf("GCD of %d, %d and %d is %d\n", a, b, c, gcd(a, gcd(b, c)));

    return 0;
}

/* Recursive function to find GCD of two numbers */
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
