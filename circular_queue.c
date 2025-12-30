#include <stdio.h>
#include <stdlib.h>

#define N 10

int cqueue[N];
int front = -1, rear = -1;

/* Function declarations */
void enqueue(int item);
void dequeue(int item);
void display();

int main()
{
    /* Insert elements */
    enqueue(5);
    enqueue(7);
    enqueue(0);
    enqueue(6);
    enqueue(3);
    enqueue(9);

    printf("\nCircular Queue after insertions:");
    display();

    /* Delete elements */
    dequeue(6);
    dequeue(9);
    dequeue(5);

    printf("\nCircular Queue after deletions:");
    display();

    return 0;
}

/* Enqueue operation */
void enqueue(int item)
{
    if ((front == 0 && rear == N - 1) || ((rear + 1) % N == front))
    {
        printf("\nQueue is full\n");
        return;
    }

    if (front == -1) // Empty queue
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % N;
    }

    cqueue[rear] = item;
    printf("\nItem inserted: %d", item);
}

/* Dequeue by value */
void dequeue(int item)
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    int i = front, found = 0;

    while (1)
    {
        if (cqueue[i] == item)
        {
            found = 1;
            break;
        }
        if (i == rear) break;
        i = (i + 1) % N;
    }

    if (!found)
    {
        printf("\nItem %d not found in queue\n", item);
        return;
    }

    // Shift elements to remove the item
    while (i != rear)
    {
        int next = (i + 1) % N;
        cqueue[i] = cqueue[next];
        i = next;
    }

    if (front == rear) // Only one element
        front = rear = -1;
    else
        rear = (rear - 1 + N) % N;

    printf("\nItem removed: %d", item);
}

/* Display queue */
void display()
{
    if (front == -1)
    {
        printf("\nQueue is empty\n");
        return;
    }

    printf("\nQueue elements: ");
    int i = front;
    while (1)
    {
        printf("%d ", cqueue[i]);
        if (i == rear) break;
        i = (i + 1) % N;
    }
    printf("\n");
}
