#include <stdio.h>

/* Function declarations */
void quickSort(int a[], int low, int high);
void swap(int *p, int *q);

int main()
{
    int a[] = {5, 3, 1, 6, 0, 2, 4};
    int n = 7;
    int i;

    printf("Program to perform Quick Sort\n");

    quickSort(a, 0, n - 1);

    printf("\nSorted numbers are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/* Quick Sort function */
void quickSort(int a[], int low, int high)
{
    int pivot, i, j;

    if (low < high)
    {
        pivot = low;
        i = low + 1;
        j = high;

        while (i <= j)
        {
            while (i <= high && a[i] <= a[pivot])
                i++;

            while (a[j] > a[pivot])
                j--;

            if (i < j)
                swap(&a[i], &a[j]);
        }

        swap(&a[pivot], &a[j]);

        quickSort(a, low, j - 1);
        quickSort(a, j + 1, high);
    }
}

/* Swap function */
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
