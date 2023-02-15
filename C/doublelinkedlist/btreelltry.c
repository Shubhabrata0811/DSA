#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
typedef struct node node;

node *root = NULL;

void insert(node *root)
{
    node *curr,*prev,*add;
    add=(node*)malloc(sizeof(node));
    add->left=NULL;
    add->right=NULL;
    if (add==NULL)
    {
        printf("\nMemory not available.");
        return;
    }
    else
    {
        printf("\nEnter the data to be inserted:");
        scanf("%d",&add->data);
        if(root==NULL)
        {
            root=add;
            printf("\n%d is inserted at root.",root->data);
            printf("\n%x",root);
            return;
        }
        else
        {
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
                printf("\n%d is inserted",add->data);
            }
            else
            {
                prev->left=add;
                printf("\n%d is inserted",add->data);
            }
            return;
        }
    }
}

void printtree(node *root)
{
    node *curr;
    printf("\n");
    curr=root;
    printf("  %d  ",curr->data);
    printtree(curr->left);
    printtree(curr->right);
    return;
}

int main()
{
    int i;
    for(i=1;i<=5;i++)
    {
        insert(root);
        printf("\n%x",root);
    }
    if(root==NULL)
    {
        printf("\nNo data available.");
    }
    else
    {
        printtree(root);
    }
    return 0;
}