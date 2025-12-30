#include <stdio.h>
#include <stdlib.h>

/* Node structure for BST */
typedef struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
} tnode;

/* Function declarations */
tnode* insert(tnode* root, int elem);
tnode* minValueNode(tnode* node);
tnode* deleteNode(tnode* root, int key);
void inorderDisplay(tnode* root);

int main()
{
    tnode* root = NULL;

    /* Initial BST creation */
    root = insert(root, 18);
    root = insert(root, 15);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 17);
    root = insert(root, 41);

    printf("BST after initial creation:\n");
    inorderDisplay(root);
    printf("\n");

    /* Insert 45 and 19 */
    root = insert(root, 45);
    printf("BST after inserting 45:\n");
    inorderDisplay(root);
    printf("\n");

    root = insert(root, 19);
    printf("BST after inserting 19:\n");
    inorderDisplay(root);
    printf("\n");

    /* Delete 15, 17, 41 */
    root = deleteNode(root, 15);
    printf("BST after deleting 15:\n");
    inorderDisplay(root);
    printf("\n");

    root = deleteNode(root, 17);
    printf("BST after deleting 17:\n");
    inorderDisplay(root);
    printf("\n");

    root = deleteNode(root, 41);
    printf("BST after deleting 41:\n");
    inorderDisplay(root);
    printf("\n");

    return 0;
}

/* Insert node in BST */
tnode* insert(tnode* root, int elem)
{
    if (root == NULL)
    {
        tnode* newNode = (tnode*)malloc(sizeof(tnode));
        newNode->data = elem;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (elem < root->data)
        root->left = insert(root->left, elem);
    else if (elem > root->data)
        root->right = insert(root->right, elem);
    else
        printf("Data %d already exists!\n", elem);

    return root;
}

/* Find minimum value node */
tnode* minValueNode(tnode* node)
{
    tnode* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

/* Delete node from BST */
tnode* deleteNode(tnode* root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            tnode* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            tnode* temp = root->left;
            free(root);
            return temp;
        }

        tnode* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/* Inorder display of BST */
void inorderDisplay(tnode* root)
{
    if (root != NULL)
    {
        inorderDisplay(root->left);
        printf("%d ", root->data);
        inorderDisplay(root->right);
    }
}
