#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node *root, int key)
{
    if(root == NULL)
        return createNode(key);
    if(key < root->data)
        root->left = insert(root->left, key);
    else if(key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void search(struct node *root, int key)
{
    if(root == NULL)
    {
        printf("NULL\n");
        return;
    }
    if(root->data == key)
    {
        printf("Found\n");
        return;
    }
    if(key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

struct node* deleteLeaf(struct node *root, int key)
{
    if(root == NULL)
        return NULL;
    if(key < root->data)
        root->left = deleteLeaf(root->left, key);
    else if(key > root->data)
        root->right = deleteLeaf(root->right, key);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else
        {
            printf("Not a leaf node, cannot delete.\n");
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main()
{
    struct node *root = NULL;
    int ch, key;
    while(1)
    {
        printf("\n1.Search\n2.Insert\n3.Delete Leaf\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                if(root == NULL)
                    printf("Tree empty\n");
                else
                {
                    printf("Enter element to search: ");
                    scanf("%d", &key);
                    search(root, key);
                }
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Inorder after insertion: ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                if(root == NULL)
                    printf("Tree empty\n");
                else
                {
                    printf("Enter leaf element to delete: ");
                    scanf("%d", &key);
                    root = deleteLeaf(root, key);
                    printf("Inorder after deletion: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}


