#include<stdio.h>
#include<stdlib.h>

//Creat the node structure
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node node;

//Initially set the value of root NULL(Empthy tree)
node *root=NULL;

//Create a new node with a given data and return the node's address
node* createnode(int data)
{
    node *newnode;
    newnode = (node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("\nCreating new node is not possible!!");
        return NULL;
    }
    newnode->data=data;
    newnode->right=newnode->left=NULL;
    return newnode;
}

//Take the element user want to insert and insert the element in the binary search tree
void insert()
{
    int idata;
    node *newnode,*prev,*curr;
    scanf("%d",&idata,printf("\nEnter the data of node to insert:"));
    newnode = createnode(idata);
    if(newnode==NULL)
    {
        return;
    }
    else
    {
        if(root==NULL)
        {
            root=newnode;
            printf("\n%d inserted at the root.",root->data);
            return;
        }
        else
        {
            prev=NULL;
            curr=root;
            while(curr!=NULL)
            {
                prev=curr;
                if(curr->data > newnode->data)
                {
                    curr=curr->left;
                }
                else
                {
                    curr=curr->right;
                }
            }
            if(prev->data > newnode->data)
            {
                prev->left=newnode;
                printf("\n%d is inserted.",prev->left->data);
            }
            else
            {
                prev->right=newnode;
                printf("\n%d is inserted.",prev->right->data);
            }
            return;
        }
    }
}

//Print the inorder traversal of the binary tree
void inorder(node *i)
{
    if(i!=NULL)
    {
        inorder(i->left);
        printf("\t%d",i->data);
        inorder(i->right);
    }
    return;
}

//Print the preorder traversal of the binary tree
void preorder(node *i)
{
    if(i!=NULL)
    {
        printf("\t%d",i->data);
        preorder(i->left);
        preorder(i->right);
    }
    return;
}

//Print the postorder traversal of the binary tree
void postorder(node *i)
{
    if(i!=NULL)
    {
        postorder(i->left);
        postorder(i->right);
        printf("\t%d",i->data);
    }
    return;
}
// Return the node of the node that has the data that needs to be found
node* searchnode(node *root, int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(key==root->data)
    {
        return root;
    }
    else if(key<root->data)
    {
        return searchnode(root->left,key);
    }
    else
    {
        return searchnode(root->right,key);
    }
}

/*void deletenode()
{
    int ddata;
    node *i=root,*parent=NULL,*t1,*t2,*temp;
    if(root==NULL)
    {
        printf("\nTree has no element!!");
        return;
    }
    scanf("%d",&ddata,printf("\nEnter the data of the node to delete:"));
    while(i!=NULL && i->data!=ddata)
    {
        parent=i;
        if(parent->data>ddata)
        {
            i=parent->left;
        }
        else
        {
            i=parent->right;
        }
    }
    if(i==NULL)
    {
        printf("\n%d is not found!!",ddata);
        return;
    }
    else
    {
        if(i->left==NULL)
        {
            t1=i->right;
        }
        else if(i->right==NULL)
        {
            t1=i->left;
        }
        else
        {
            t2=i;
            t1=i->right;
            temp=t1->left;
            while(temp!=NULL)
            {
                t2=t1;
                t1=temp;
                temp=t1->left;
            }
            if(t1!=i)
            {
                t2->left=t1->right;
                t1->right=i->right;
            }
            t1->left=i->left;
        }
    }
    if(parent==NULL)
    {
        root=t1;
    }
    else
    {
        if(parent->left==i)
        {
            parent->left=t1;
            if(i->right!=NULL)
            {
                t1->right=i->right;
            }
        }
        else
        {
            parent->right=t1;
            if(i->left!=NULL)
            {
                t1->left=i->left;
            }
        }
    }
    printf("\n%d is deleted.",i->data);
    free(i);
    return;
}*/

//return the inorder succssor of a given node
node* inordersucc(node *i)
{
    node *curr=i;
    while(curr && curr->left != NULL)
    {
        curr=curr->left;
    }
    return curr;
}

//delete the node having given data
node* deletenode(node *root,int ddata)
{
    node *temp;
    if(root==NULL)
    {
        printf("\nTree has no such element!!");
        return NULL;
    }
    if(ddata < root->data)
    {
        root->left=deletenode(root->left,ddata);
    }
    else if(ddata > root->data)
    {
        root->right=deletenode(root->right,ddata);
    }
    else
    {
        if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deletenode(root->right,temp->data);
    }
    return root;
}


int main()
{
    char choice;

    int fdata,ddata;
    while(scanf("%c",&choice,printf("\nEnter 'I' for insert a new element\n'D' for delete an element\n'S' to show the tree\n'F' for found  an element\n'E' for exit\nEnter your choice:")))
    {
        if(choice>96 && choice<124)
        {
            choice-=32;
        }
        switch(choice)
        {
            case 'I':insert();break;
            case 'D':
                {
                    scanf("%d",&ddata,printf("\nEnter the data of the node to delete:"));
                    root=deletenode(root,ddata);
                    break;
                }
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
            case 'F':
                {
                    scanf("%d",&fdata,printf("\nEnter the data of the node to find:"));
                    if(searchnode(root,fdata)==NULL)
                    {
                        printf("\nKey not exist");
                    }
                    else
                    {
                        printf("\nKey exist");
                    }
                    break;
                }
            case 'E':return 0;
            default:printf("\nInvalid input!!");break;
        }
        fflush(stdin);
    }
    return 0;
}