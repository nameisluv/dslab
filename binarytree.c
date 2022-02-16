#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();

    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}

void preorder(node *t)
{
    if(t!=NULL)
    {
        printf("\n%d",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t)
{
    if(t!=NULL)
    {
        preorder(t->left);
        printf("\n%d",t->data);
        preorder(t->right);
    }
}

void postorder(node *t)
{
    if(t!=NULL)
    {
        preorder(t->left);
        preorder(t->right);
        printf("\n%d",t->data);
    }
}

int main()
{   int ch;
    node *root;
    root=create();
    while(1) {
        printf("\nEnter\n1.preorder\n2.inorder\n3.postorder\n4.exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nThe preorder traversal of tree is:\n");
                preorder(root);
                break;
            case 2:
                printf("\nThe inorder traversal of tree is:\n");
                inorder(root);
                break;
            case 3:
                printf("\nThe postorder traversal of tree is:\n");
                postorder(root);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}