#include<stdio.h>
#include<stdlib.h>

struct node     //create the node structure
{
    int data;
    struct node *left, *right;
};
typedef struct node node;       //give a short name "node" to the structure

node *root=NULL;

node* creatnode(int data)       //function that creates a new node with the given data
{
    node *add;
    add = (node*)malloc(sizeof(node));
    if(add==NULL)
    {
        printf("\nMemory is not available...");
        return NULL;
    }
    add->data=data;
    add->left=NULL;
    add->right=NULL;
    return add;
}

void insert(int data)       //insert the node having given data
{
    node *curr,*prev,*add;
    if(root==NULL)      //if there is no previous data in the tree then the element should be in root
    {
        root=creatnode(data);
        if(root==NULL)
        {
            printf("\nInsertion not possible!!");
            return;
        }
        printf("\n%d is inserted",root->data);
        return;
    }
    else
    {
        add=creatnode(data);
        if(add==NULL)
        {
            printf("\nInsertion not possible!!");
            return;
        }
        curr=root;
        prev=NULL;
        while(curr!=NULL)
        {
            prev=curr;
            if(add->data>curr->data)
            {
                curr=curr->right;
            }
            else
            {
                curr=curr->left;
            }
        }
        if(add->data>prev->data)
        {
            prev->right=add;
            printf("\n%d is inserted",prev->right->data);
        }
        else
        {
            prev->left=add;
            printf("\n%d is inserted",prev->left->data);
        }
    }
    return;
}

void preordertree(node *pnode)
{
    if(pnode==NULL)
    {
        return;
    }
    else
    {
        printf("  %d  ",pnode->data);
        preordertree(pnode->left);
        preordertree(pnode->right);

    }
}

void postordertree(node *pnode)
{
    if(pnode==NULL)
    {
        return;
    }
    else
    {
        postordertree(pnode->left);
        postordertree(pnode->right);
        printf("  %d  ",pnode->data);
    }
}

void inordertree(node *pnode)
{
    if(pnode==NULL)
    {
        return;
    }
    else
    {
        inordertree(pnode->left);
        printf("  %d  ",pnode->data);
        inordertree(pnode->right);

    }
}

int main()
{
    int i,data,n;
    scanf("%d",&n,printf("\nNumber of data to be imserted: "));
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the (%d) data to be inserted:",i);
        scanf("%d",&data);
        insert(data);

    }
    if(root==NULL)
    {
        printf("\nNo data available!!");
        return 0;
    }
    printf("\nThe preorder tree is :");
    preordertree(root);
    printf("\nThe postorder tree is :");
    postordertree(root);
    printf("\nThe inorder tree is :");
    inordertree(root);

    return 0;
}