#include <stdio.h>
#include <stdlib.h>

/* Node structure for polynomial */
struct node {
    int coeff;
    int power;
    struct node* link;
};

/* Function declarations */
struct node* insert(struct node* head, int coeff, int power);
void display(struct node* head);
void addPoly(struct node* poly1, struct node* poly2);

/* Global pointers */
struct node *poly1 = NULL, *poly2 = NULL;

int main()
{
    /* Polynomial 1: 6x^3 + 10x^2 + 0x + 5 */
    poly1 = insert(poly1, 6, 3);
    poly1 = insert(poly1, 10, 2);
    poly1 = insert(poly1, 0, 1);
    poly1 = insert(poly1, 5, 0);

    /* Polynomial 2: 4x^2 + 2x + 1 */
    poly2 = insert(poly2, 4, 2);
    poly2 = insert(poly2, 2, 1);
    poly2 = insert(poly2, 1, 0);

    printf("Polynomial 1:");
    display(poly1);

    printf("Polynomial 2:");
    display(poly2);

    printf("\nSum of polynomials:\n");
    addPoly(poly1, poly2);

    return 0;
}

/* Function to insert a node at the end */
struct node* insert(struct node* head, int coeff, int power)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->link = NULL;

    if (head == NULL)
        return newnode;

    struct node* temp = head;
    while (temp->link != NULL)
        temp = temp->link;

    temp->link = newnode;
    return head;
}

/* Function to display polynomial */
void display(struct node* head)
{
    struct node* temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d ", temp->coeff, temp->power);
        if (temp->link != NULL)
            printf("+ ");
        temp = temp->link;
    }
    printf("\n");
}

/* Function to add two polynomials */
void addPoly(struct node* poly1, struct node* poly2)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->power == poly2->power)
        {
            printf("%dx^%d ", poly1->coeff + poly2->coeff, poly1->power);
            poly1 = poly1->link;
            poly2 = poly2->link;
        }
        else if (poly1->power > poly2->power)
        {
            printf("%dx^%d ", poly1->coeff, poly1->power);
            poly1 = poly1->link;
        }
        else
        {
            printf("%dx^%d ", poly2->coeff, poly2->power);
            poly2 = poly2->link;
        }

        if (poly1 != NULL || poly2 != NULL)
            printf("+ ");
    }

    /* Print remaining terms */
    while (poly1 != NULL)
    {
        printf("%dx^%d", poly1->coeff, poly1->power);
        poly1 = poly1->link;
        if (poly1 != NULL) printf(" + ");
    }

    while (poly2 != NULL)
    {
        printf("%dx^%d", poly2->coeff, poly2->power);
        poly2 = poly2->link;
        if (poly2 != NULL) printf(" + ");
    }

    printf("\n");
}
