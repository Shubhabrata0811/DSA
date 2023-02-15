#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;

node *root = NULL;

node* createnode(int data)
{
	node *newnode;
	newnode = (node*)malloc(sizeof(node));
	newnode->data=data;
    newnode->right=newnode->left=NULL;
	return newnode;
}

node* insert(node *root,int idata)
{
	if(root==NULL)
	{
		root=createnode(idata);
		printf("\n%d inserted.",root->data);
		return root;
	}
	else if(idata<root->data)
	{
		root->left=insert(root->left,idata);
	}
	else
	{
		root->right=insert(root->right,idata);
	}

}

node* inordersuccssor(node *i)
{
    node *succssor=NULL;
    if(i!=NULL)
    {
        succssor=i;
        i=i->right;
    }
    return succssor;
}

node* deletenode(node *root,int ddata)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->data==ddata)
    {
        if(root->right==NULL)
        {
            root=root->left;
        }
        else if(root->left==NULL)
    }
    else if(ddata<root->data)
    {
        root->left=deletenode(root->left,ddata);
    }
    else if(ddata>root->data)
    {
        root->right=deletenode(root->right,ddata);
    }
    else
    {
          
    }
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\t%d",root->data);
		inorder(root->right);
	}
	return;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
        printf("\t%d",root->data);
        preorder(root->left);
		preorder(root->right);
	}
	return;
}

void postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%d",root->data);
	}
	return;
}
int main()
{
    char choice;
    while(scanf("%c",&choice,printf("\nEnter 'I' for insert a new element\n'D' for delete an element\n'S' to show the tree\n'F' for found  an element\n'E' for exit\nEnter your choice:")))
    {
        if(choice>96 && choice<124)
        {
            choice-=32;
        }
        switch(choice)
        {
            case 'I':
            	{
            		int idata;
					scanf("%d",&idata,printf("\nEnter the data to be inserted: "));
            		root=insert(root,idata);
            		break;
            	}
            // case 'D':
            //     {
            //         scanf("%d",&ddata,printf("\nEnter the data of the node to delete:"));
            //         root=deletenode(root,ddata);
            //         break;
            //     }
            case 'S':
                {
                    if(root==NULL)
                    {
                        printf("\nTree has no elements!!");
                        break;
                    }
                    else
                    {
                        printf("\nInorder traversal:");
                        inorder(root);
                        printf("\nPreorder traversal:");
                        preorder(root);
                        printf("\npostorder traversal:");
                        postorder(root);
                        break;
                    }
                }
            // case 'F':
            //     {
            //         scanf("%d",&fdata,printf("\nEnter the data of the node to find:"));
            //         if(searchnode(root,fdata)==NULL)
            //         {
            //             printf("\nKey not exist");
            //         }
            //         else
            //         {
            //             printf("\nKey exist");
            //         }
            //         break;
            //     }
            case 'E':return 0;
            default:printf("\nInvalid input!!");break;
        }
        fflush(stdin);
    }
    return 0;
}