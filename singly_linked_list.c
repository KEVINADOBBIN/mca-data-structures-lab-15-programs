#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node* link;
};

/* Global pointers */
struct node *head = NULL, *curptr, *prevptr, *newnode;

/* Function declarations */
void insertNode(int data);
void deleteNode(int data);
void display();

int main()
{
    /* Insert nodes */
    insertNode(61);
    display();

    insertNode(16);
    display();

    insertNode(8);
    display();

    insertNode(27);
    display();

    /* Delete nodes */
    deleteNode(8);
    display();

    deleteNode(61);
    display();

    deleteNode(27);
    display();

    return 0;
}

/* Function to insert at beginning */
void insertNode(int data)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = head;
    head = newnode;
}

/* Function to delete a node by value */
void deleteNode(int data)
{
    prevptr = NULL;
    curptr = head;

    while (curptr != NULL)
    {
        if (curptr->data == data)
        {
            if (prevptr != NULL)
                prevptr->link = curptr->link;
            else
                head = curptr->link;

            printf("\nElement %d deleted", data);
            free(curptr);
            return;
        }
        else
        {
            prevptr = curptr;
            curptr = curptr->link;
        }
    }

    printf("\nElement %d not found", data);
}

/* Function to display the linked list */
void display()
{
    curptr = head;
    printf("\nElements in linked list: ");
    while (curptr != NULL)
    {
        printf("->%d", curptr->data);
        curptr = curptr->link;
    }
    printf("\n");
}
