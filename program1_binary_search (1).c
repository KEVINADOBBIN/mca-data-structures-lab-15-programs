#include <stdio.h>

/* Function declarations */
void bubbleSort(int a[], int n);
int binarySearchFirst(int a[], int n, int key);

int main()
{
    int a[] = {2, 3, 4, 7, 7, 9, 1, 0};
    int n = 8;
    int key = 7;
    int i, result;

    printf("The elements in the array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    bubbleSort(a, n);

    printf("\n\nThe sorted elements are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    result = binarySearchFirst(a, n, key);

    if (result != -1)
        printf("\n\nElement %d found at index position %d\n", key, result);
    else
        printf("\n\nElement not found\n");

    return 0;
}

/* Bubble Sort Function */
void bubbleSort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

/* Binary Search to find first occurrence */
int binarySearchFirst(int a[], int n, int key)
{
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (a[mid] == key)
        {
            result = mid;
            high = mid - 1; // move left to find first occurrence
        }
        else if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return result;
}
