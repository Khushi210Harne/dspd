#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* newNode(int data)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insertLevel(struct node* root, int data)
{
    struct node* queue[100];
    int front = 0, rear = 0;
    struct node* temp = root;
    struct node* newnode = newNode(data);
    if(!root) return newnode;
    queue[rear++] = temp;
    while(front < rear)
    {
        temp = queue[front++];
        if(!temp->left)
        {
            temp->left = newnode;
            return root;
        }
        else queue[rear++] = temp->left;
        if(!temp->right)
        {
            temp->right = newnode;
            return root;
        }
        else queue[rear++] = temp->right;
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

void preorder(struct node *root)
{
    if(root==NULL) return;
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

int search(struct node *root,int key)
{
    if(root==NULL) return 0;
    if(root->data==key) return 1;
    if(search(root->left,key)) return 1;
    if(search(root->right,key)) return 1;
    return 0;
}

int main()
{
    struct node *root=NULL;
    int ch,n,i,val,key;
    while(1)
    {
        printf("\n1.Insert Nodes\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    printf("Enter value for node %d: ",i+1);
                    scanf("%d",&val);
                    root = insertLevel(root,val);
                }
                break;
            case 2:
                if(root==NULL) printf("Tree empty\n");
                else
                {
                    printf("Inorder: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if(root==NULL) printf("Tree empty\n");
                else
                {
                    printf("Preorder: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root==NULL) printf("Tree empty\n");
                else
                {
                    printf("Postorder: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                if(root==NULL) printf("Tree empty\n");
                else
                {
                    printf("Enter element to search: ");
                    scanf("%d",&key);
                    if(search(root,key)) printf("Found\n");
                    else printf("NULL\n");
                }
                break;
            case 6:
                exit(0);
        }
    }
    return 0;
}



