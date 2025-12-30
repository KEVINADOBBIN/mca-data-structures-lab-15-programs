#include <stdio.h>

/* Function declarations */
void partition(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int a[] = {75, 8, 1, 16, 48, 3, 7, 0};
int t[20];
int n = 8;

int main()
{
    int i;

    printf("Program to perform Merge Sort\n");

    printf("\nUnsorted array of elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    partition(a, 0, n - 1);

    printf("\n\nSorted array of elements (Descending Order):\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/* Partition function */
void partition(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        partition(a, low, mid);
        partition(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

/* Merge function for descending order */
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (a[i] >= a[j])        // Descending order
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }

    while (i <= mid)
        t[k++] = a[i++];

    while (j <= high)
        t[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = t[i];
}
