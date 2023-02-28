#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char ch;
    struct node *next;
};
typedef struct node node;

struct stack
{
    node *top;
    int noele;
};
typedef struct stack stack;

node* createnode(char ch)
{
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL)
    {
        printf("\nMemory is not available!");
        return NULL;
    }
    newnode->ch=ch;
    newnode->next=NULL;
    return newnode;
}

stack* createstack()
{
    stack *newstack=(stack*)malloc(sizeof(stack));
    newstack->top=NULL;
    newstack->noele=0;
    return newstack;
}

void push(stack *st,char ch)
{
    node *newnode=createnode(ch);
    newnode->next=st->top;
    st->top=newnode;
    st->noele++;
    //printf("\n%c is pushed",st->top->ch);
}

char pop(stack *st)
{
    char ch;
    if(st->top==NULL)
    {
        printf("\nStack is empty!");
        return '\0';
    }
    node *temp;
    temp=st->top;
    st->top=st->top->next;
    //printf("\n%c is popped",temp->ch);
    st->noele--;
    ch=temp->ch;
    free(temp);
    return ch;
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
        printf("%c\n",temp->ch);
        temp=temp->next;
    }
}

void strrevs(char *str)
{
    stack *strst;
    strst=createstack();
    for(int i=0;i<strlen(str);i++)
    {
        push(strst,str[i]);
    }
    int j;
    for(j=0;j<strlen(str);j++)
    {
        str[j]=pop(strst);
    }
    str[j]='\0';
}

int main()
{
    char str[100];
    printf("\nEnter the string:");
    gets(str);
    printf("\nThe user entered string: %s",str);
    strrevs(str);
    printf("\nThe reverse string: %s",str);
    return 0;
}