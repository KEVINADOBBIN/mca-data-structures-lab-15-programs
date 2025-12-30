#include <stdio.h>

// Function declarations
void bubbleSort(int a[], int n);
void binarySearchFirstOccurrence(int a[], int n, int key);

int main() {
    int a[15] = {2, 3, 4, 7, 7, 9, 1, 0};
    int n = 8;
    int key = 7;
    int i;

    printf("Elements in the array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    bubbleSort(a, n);

    printf("\n\nSorted elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }

    binarySearchFirstOccurrence(a, n, key);

    return 0;
}

// Bubble Sort Function
void bubbleSort(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Binary Search to find first occurrence
void binarySearchFirstOccurrence(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    int result = -1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (a[mid] == key) {
            result = mid;
            high = mid - 1; // search left for first occurrence
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (result != -1) {
        printf("\n\nElement %d found at location %d", key, result + 1);
        printf("\nFirst occurrence of %d is at location %d\n", key, result + 1);
    } else {
        printf("\n\nElement %d not found in the array\n", key);
    }
}
