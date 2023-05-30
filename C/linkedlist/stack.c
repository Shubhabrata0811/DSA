#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node node;

struct stack
{
    node *top;
    int noele;
};
typedef struct stack stack;

node* createnode(int data)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("\nMemory is not available!");
        return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

stack* createstack()
{
    stack *newstack;
    newstack=(stack*)malloc(sizeof(stack));
    newstack->top=NULL;
    newstack->noele=0;
    return newstack;
}

void push(stack *st,int data)
{
    node *newnode=createnode(data);
    newnode->next=st->top;
    st->top=newnode;
    st->noele++;
    printf("\n%d is pushed",st->top->data);
}

void pop(stack *st)
{
    if(st->top==NULL)
    {
        printf("\nStack is empty!");
        return;
    }
    node *temp;
    temp=st->top;
    st->top=st->top->next;
    printf("\n%d is popped",temp->data);
    st->noele--;
    free(temp);
}

void display(stack *st)
{
    if(st->noele==0)
    {
        printf("\nStack is empty!");
        return;
    }
    node *temp;
    temp=st->top;
    printf("\nThere are %d elements in the stack.\nThe stack is:\n",st->noele);
    while(temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
    stack *st;
    st=createstack();
    push(st,9);
    display(st);
    push(st,8);
    display(st);
    push(st,7);
    display(st);
    push(st,6);
    display(st);
    pop(st);
    display(st);
    pop(st);
    display(st);
    push(st,5);
    display(st);
    return 0;
}