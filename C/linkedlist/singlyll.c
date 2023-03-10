#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

//Create a node
node* createnode(int data)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

//Insert at beginning
void insert_at_beg(int val)
{
    node *newnode=createnode(val);
    if(newnode==NULL)
    {
        printf("\nMemory is not available!");
        return;
    }
    newnode->next=head;
    head=newnode;
    printf("\n%d is inserted at beginning ",head->data);
}

//Insert at end
void insert_at_end(int val)
{
    node *newnode=createnode(val);
    if(newnode==NULL)
    {
        printf("\nMemory is not available!");
        return;
    }
    node *temp=head;
    if(temp==NULL)
    {
        head=newnode;
        printf("\n%d is inserted at head node.",head->data);
        return;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    printf("\n%d is inserted at end.",temp->next->data);
}

//Insert at specific position
void insert_at_loc(int val,int loc)
{
    if(loc<1)
    {
        printf("\nInvalid position!");
        return;
    }
    node *newnode=createnode(val);
    if(newnode==NULL)
    {
        printf("\nMemory is not available!");
        return;
    }
    if(loc==1)
    {
        newnode->next=head;
        head=newnode;
        printf("\n%d is inserted at beginning.",head->data);
        return;
    }
    node *temp=head;
    for(int pos=1;(pos<loc-1)&&(temp!=NULL);pos++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nInvalid position!");
        return;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    printf("\n%d is inserted at %d.",temp->next->data,loc);
}

//Delete a node from beginning
void delete_at_beg()
{
    if(head==NULL)
    {
        printf("\nList Empty!");
        return;
    }
    node *temp=head;
    head=head->next;
    printf("\n%d deleted.",temp->data);
    free(temp);
}

//Delete a node from bend
void delete_at_end()
{
    if(head==NULL)
    {
        printf("\nList Empty!");
        return;
    }
    node *temp=head;
    node *pre;
    while(temp->next!=NULL)
    {
        pre=temp;
        temp=temp->next;
    }
    printf("\n%d is deleted",temp->data);
    if(temp==head)
        head=NULL;
    else
        pre->next=NULL;
    free(temp);
}

//Delete from a specific location
void delete_at_loc(int loc)
{
    if(head==NULL)
    {
        printf("\nList Empty!");
        return;
    }
    if(loc<1)
    {
        printf("\nInvalid position!");
        return;
    }
    if(loc==1)
    {
        node *temp=head;
        head=head->next;
        printf("\n%d deleted.",temp->data);
        free(temp);
        return;
    }
    node *temp=head;
    for(int pos=1;(pos<loc-1)&&(temp!=NULL);pos++)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("\nInvalid position!");
        return;
    }
    node *ptr=temp->next;
    temp->next=temp->next->next;
    printf("\n%d is deleted",ptr->data);
    free(ptr);
}

//Delete a specific element
void delete_val(int val)
{
    if(head==NULL)
    {
        printf("\nList Empty!");
        return;
    }
    node *temp=head;
    node *prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==val)
        {
            if(prev==NULL)
                head=temp->next;
            else
                prev->next=temp->next;
            printf("\n%d is deleted",temp->data);
            free(temp);
            return;
        }
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        printf("\n%d not found.",val);
}

void print_list()
{
    if(head==NULL)
    {
        printf("\nList Empty!");
        return;
    }
    node *temp=head;
    printf("\nThe list: ");
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        if(temp->next!=NULL)
            printf("-->");
        temp=temp->next;
    }
}

int main()
{
    print_list();
    insert_at_beg(0);
    print_list();
    insert_at_end(2);
    print_list();
    insert_at_end(5);
    print_list();
    insert_at_loc(1,2);
    print_list();
    insert_at_loc(10,27);
    print_list();
    insert_at_loc(4,3);
    print_list();
    delete_at_loc(0);
    print_list();
    delete_at_loc(3);
    print_list();
    delete_at_loc(10);
    print_list();
    delete_at_loc(4);
    print_list();
    delete_val(4);
    print_list();
    delete_val(2);
    print_list();
    return 0;
}