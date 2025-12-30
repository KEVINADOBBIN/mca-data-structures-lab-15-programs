#include <stdio.h>

/* Function declarations */
void heapSort(int a[], int n);
void heapify(int a[], int n, int i);
void swap(int *p, int *q);

int main()
{
    int a[] = {9, 16, 32, 8, 4, 1, 5, 8, 0};
    int n = 9;
    int i;

    printf("The elements in the array are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    heapSort(a, n);

    printf("\n\nThe elements after sorting are:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}

/* Heap Sort function */
void heapSort(int a[], int n)
{
    int i;

    /* Build max heap */
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);

    /* Extract elements from heap */
    for (i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

/* Heapify function */
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;

    if (right < n && a[right] > a[largest])
        largest = right;

    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}

/* Swap function */
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
