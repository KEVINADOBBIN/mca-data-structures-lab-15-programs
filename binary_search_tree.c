#include <stdio.h>
#include <stdlib.h>

/* Node structure for BST */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Function declarations */
struct node* newNode(int data);
void printPreorder(struct node* node);
void printInorder(struct node* node);
void printPostorder(struct node* node);

int main()
{
    /* Create BST */
    struct node* root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(5);
    root->left->left = newNode(0);
    root->right->left = newNode(3);
    root->right->right = newNode(9);
    root->right->left->right = newNode(6);

    /* Traversals */
    printf("Preorder traversal of binary tree:\n");
    printPreorder(root);
    printf("\n");

    printf("Inorder traversal of binary tree:\n");
    printInorder(root);
    printf("\n");

    printf("Postorder traversal of binary tree:\n");
    printPostorder(root);
    printf("\n");

    return 0;
}

/* Function to create a new node */
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Preorder traversal */
void printPreorder(struct node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

/* Inorder traversal */
void printInorder(struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

/* Postorder traversal */
void printPostorder(struct node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}
